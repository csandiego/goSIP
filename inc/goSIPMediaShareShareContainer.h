/*
============================================================================
 Name        : CgoSIPMediaShareShareContainer from goSIPMediaShareShareContainer.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Declares container control for application.
============================================================================
*/

#ifndef GOSIPMEDIASHARESHARECONTAINER_H
#define GOSIPMEDIASHARESHARECONTAINER_H

// INCLUDES
#include <coecntrl.h>
#include <aknlists.h>
//#include <aknselectionlist.h>
//#include <pathinfo.h>
//#include <mmgfetchverifier.h> 
//#include <mediafiletypes.hrh>
//#include <maknfileselectionobserver.h> 

#include <aknlistquerydialog.h>
#include <CAknFileSelectionDialog.h> 
#include "eiklbx.h"
#include "goSIPMediaShareAppEngine.h"
   
// FORWARD DECLARATIONS
class CEikLabel;        // for example labels

// CLASS DECLARATION

/**
*  CgoSIPMediaShareShareContainer  container control class.
*  
*/
class CgoSIPMediaShareShareContainer : public CCoeControl, MCoeControlObserver
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
        ~CgoSIPMediaShareShareContainer();

    public: // New functions

		void SetFileList(TInt aDirectory, TInt aSizeDate);
		void UpdateList(CgoSIPMediaShareAppEngine* aEngine);//(const TDesC aName, TInt aDirectory);
		void Save();
		void Load();
		void Unshare();

		//void BrowseFilesL(TMediaFileType aMediaType);

		//void BrowseAudio(const TFileName& aPath);

    public: // Functions from base classes

		TKeyResponse    OfferKeyEventL(const TKeyEvent& aKeyEvent,TEventCode aType);

    private: // Functions from base classes

       /**
        * From CoeControl,SizeChanged.
        */
        void SizeChanged();

		//TBool VerifySelectionL (const MDesCArray *aSelectedFiles); 

		//TBool OkToExitL (const TDesC &aDriveAndPath, const TEntry &aEntry);

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
        
    private: //data
        CgoSIPMediaShareAppEngine* iAppEngine;
		CAknDoubleStyleListBox* iListBox;


    };

#endif

// End of File
