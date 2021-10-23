/*
============================================================================
 Name        : CgoSIPChatUserListContainer from goSIPChatUserListContainer.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Declares container control for application.
============================================================================
*/

#ifndef GOSIPCHATUSERLISTCONTAINER_H
#define GOSIPCHATUSERLISTCONTAINER_H

// INCLUDES
#include <coecntrl.h>
#include <aknlists.h>
#include <barsread.h>
#include <aknquerydialog.h>
#include <stringloader.h>
#include <badesca.h>        // for CDesCArray
   
// FORWARD DECLARATIONS
class CEikLabel;        // for example labels
class CgoSIPUser;

// CLASS DECLARATION

/**
*  CgoSIPChatUserListContainer  container control class.
*  
*/
class CgoSIPChatUserListContainer : public CCoeControl, MCoeControlObserver
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
        ~CgoSIPChatUserListContainer();

    public: // New functions
        void InviteUsers();

    public: // Functions from base classes

       /**
        * From CoeControl,SizeChanged.
        */
        void SizeChanged();

    private: // Functions from base classes

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
        TKeyResponse OfferKeyEventL(const TKeyEvent& aKeyEvent, TEventCode aType);        
    public: //data
		//CEikTextListBox* iList;          // example label        
        //CEikLabel* iLabel;          // example label
        //CEikLabel* iToDoLabel;      // example label
        //void AddUserToListBox(TBuf<256> buf);
        //void GetGroupIndex();
        CAknSingleStyleListBox* iListBox;
        CDesCArray* iListBoxArray;
        TInt iFamilyIndex;
        TInt iFriendIndex;
        TInt iWorkmateIndex;

    };

#endif

// End of File
