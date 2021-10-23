/*
============================================================================
 Name        : CgoSIP_PhonebookContainer from goSIP_PhonebookContainer.h
 Author      : Allan Bate & Adrian Rodriguez
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Declares container control for application.
============================================================================
*/

#ifndef GOSIP_PHONEBOOKCONTAINER_H
#define GOSIP_PHONEBOOKCONTAINER_H

// INCLUDES
#include <coecntrl.h>
#include <eiklbx.h>
#include <aknsfld.h>
#include <aknutils.h>
#include <aknlists.h>
#include <cntdb.h>
#include <badesca.h>
#include <eiktxlbm.h>

// CONSTANTS *FROM CONTACTS S60 SAMPLE*
#include "constantcontacts.h"

// FORWARD DECLARATIONS
class CEikLabel;        // for example labels

// CLASS DECLARATION

/**
*  CgoSIP_PhonebookContainer  container control class.
*  
*/
class CgoSIPPhonebookContainer2 : public CCoeControl, MCoeControlObserver, MEikListBoxObserver
    {
    public: // Constructors and destructor
        
        /**
        * EPOC default constructor.
        * @param aRect Frame rectangle for container.
        */
        void ConstructL(const TRect& aRect);

        /**
        * Destructor.
        */
        ~CgoSIPPhonebookContainer2();

		/**
		* Constructor
		*/
		CgoSIPPhonebookContainer2();

    public: //new functions

		void HandleMarkCommandL(TInt cmd);


        /**
        * AddNewContactDlgL
        * The method adds new contact
        */
        void AddNewContactDlgL();

        /**
        * EditContactDlgL
        * The method edits contact
        */
        void EditContactDlgL();

        /**
        * DeleteContactDlgL
        * The method deletes contact
        */
        void DeleteContactDlgL();

        /**
        * AddContactToGrpL
        * The method adds contact to selected contact group
        */
        void AddContactToGrpL();

        /**
        * GetSelectedContactL
        * The method stores selected contact and open group
        * list to the listbox
        */
        void GetSelectedContactL();

        /**
        * CreateContactTemplateL
        * The method creates new contact template
        */
        void CreateContactTemplateL();

        /**
        * DeleteContactGroupL
        * The method deletes contact group
        */
        void DeleteContactGroupL();

        /**
        * DeleteContactDatabaseQueryL
        * The method deletes contacts db
        */
        void DeleteContactDatabaseQueryL();

        /**
        * ShowContactsL
        * The method shows contacts in the listbox
        */
        void ShowContactsL();

        /**
        * ShowContactGroupsL
        * The method shows contact groups in the listbox
        */
        void ShowContactGroupsL();

        /**
        * IsContactsOnListBox
        * The method returns true if contacs are in the listbox
        * @return status of listbox
        */
        TBool IsContactsOnListBox();

        /**
        * IfContactDbSelected
        * The method returns true if contacs are opened.
        * @return status of contact database attribute
        */
        TBool IfContactDbSelected();

        /**
        * OpenDefaultDatabaseL
        * The method opens default contact database
        */
        void OpenDefaultDatabaseL();

        /**
        * DeleteContactDatabaseL
        * The method deletes contact db from disk
        * @param aDbName name of the contact database
        */
        void DeleteContactDatabaseL( TDesC& aDbName );

        /**
        * OpenContactDatabase
        * The method stores name of the contact database
        * complete path
        * to the variable iDbName
        * @param aDbName name of the contact database
        */
        void UpdateContactDbName( TDesC& aDbName );

        /**
        * DatabaseExists
        * The method Checks if contact database is exist
        * @param aDbName name of the contact database
        * @return status of database
        */
        TBool DatabaseExists( TDesC& aDbName );

    private: // Functions from base classes

       /**
        * From CoeControl,SizeChanged.
        */
        void SizeChanged();

       /**
        * From CoeControl,CountComponentControls.
        */
        TInt CountComponentControls() const;

       /**
        * From CCoeControl,ComponentControl.
        */
        CCoeControl* ComponentControl(TInt aIndex) const;

       /**
        * From CCoeControl,Draw.
        */
        void Draw(const TRect& aRect) const;
       	
		/**
		* From MCoeControlObserver
		* Acts upon changes in the hosted control's state. 
		*
		* @param	aControl	The control changing its state
		* @param	aEventType	The type of control event 
		*/
        void HandleControlEventL(CCoeControl* aControl,TCoeEvent aEventType);

        /**
        * From CCoeControl
        * event handling section
        * e.g Listbox events
        * @param aKeyEvent Event to handled.
        * @param aType Type of the key event.
        * @return Response code (EKeyWasConsumed, EKeyWasNotConsumed).
        */
        TKeyResponse OfferKeyEventL( const TKeyEvent& aKeyEvent, TEventCode aType );

		/**
        * From MEikListBoxObserver,HandleListBoxEventL.
        * Handles listbox events.
        * @param aListBox, pointer to listbox - not in use
        * @param aEventType, event which happened
        */
        void HandleListBoxEventL( CEikListBox* aListBox, TListBoxEvent aEventType );

	private: // New functions
		/**
		* SetUpListIcons
		* The method creates the icons for the listbox
		*/
		void SetUpListIcons();

        /**
        * UpdateListBoxL
        * The method updates listbox
        */
        void UpdateListBoxL();

        /**
        * ReadContactsFromDbL
        * The method reads contacts from contact database
        */
        void ReadContactsFromDbL();

        /**
        * ReadContactGroupsFromDbL
        * The method reads contact groups from contact database
        */
        void ReadContactGroupsFromDbL();

        /**
        * ShowInformationNoteNoDbL
        * The method shows no contact database selected information note
        */
        void ShowInformationNoteNoDbL();

        /**
        * GetContactDbName
        * The method adds complete path for contact database
        * @param aDbName name of the db
        * @param aCompleteDbName contains path and dbname
        * contains complete path and name for db
        */
        void GetContactDbName( TDesC& aDbName, TPtr aCompleteDbName );

	private: //data
        
        CEikLabel* iLabel;          // example label
        CEikLabel* iToDoLabel;      // example label

        /**
        * iContactDb the contact database
        * Owned by CContContainer object
        */
        CContactDatabase* iContactDb;

        /**
        * iListBox the listbox
        * Owned by CContContainer object, instantiated in
        * ConstructL, deleted in destructor
        */
        //CEikTextListBox* iListBox;
		CAknColumnListBox* iListBox;

        /**
        * iContactArray the array of the contacts
        * Owned by CContContainer object, instantiated in
        * ConstructL, deleted in destructor
        */
        CDesCArray*       iContactArray;

        /**
        * iDbName the name of the contact database
        * variable contains path and name
        */
        TBuf<KMaxDatabasePathAndNameLength>	  iDbName;

        /**
        * iSelectedItemId the id of the selected item
        */
        TContactItemId	  iSelectedItemId;

		/**
        * iContactGroupArray the array of the contacts
        * Owned by CContContainer object, instantiated in
        * ConstructL, deleted in destructor
        */
        //CDesCArray*       iContactGroupArray;

   };

#endif


