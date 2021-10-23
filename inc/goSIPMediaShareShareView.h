/*
============================================================================
 Name        : CgoSIPMediaShareShareView from goSIPMediaShareShareView.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : CgoSIPMediaShareShareView declaration
============================================================================
*/

#ifndef GOSIPMEDIASHARESHAREVIEW_H
#define GOSIPMEDIASHARESHAREVIEW_H

// INCLUDES
#include <aknview.h>

#include <MAknMemorySelectionObserver.h>
#include <CAknFileSelectionDialog.h>
#include <CAknMemorySelectionDialog.h>
#include <AknQueryDialog.h>
//#include <aknlists.h>

#include <pathinfo.h>
#include <mmgfetchverifier.h> 
#include <mediafiletypes.hrh>
#include <maknfileselectionobserver.h> 

#include "goSIP.hrh"

// CONSTANTS
// UID of view
const TUid KgoSIPMediaShareShareViewId = {EgoSIPMediaShareShareTab};

// FORWARD DECLARATIONS
class CgoSIPMediaShareShareContainer;

// CLASS DECLARATION

/**
*  CgoSIPMediaShareShareView view class.
* 
*/
class CgoSIPMediaShareShareView : public CAknView, MMGFetchVerifier, MAknFileSelectionObserver
    {
    public: // Constructors and destructor

        /**
        * EPOC default constructor.
        */
        void ConstructL();

        /**
        * Destructor.
        */
        ~CgoSIPMediaShareShareView();

    public: // Functions from base classes
                        
		/**
        * From CAknView returns Uid of View
        * @return TUid uid of the view
        */
        TUid Id() const;

        /**
        * From MEikMenuObserver delegate commands from the menu
        * @param aCommand a command emitted by the menu 
        * @return void
        */
        void HandleCommandL(TInt aCommand);

        /**
        * From CAknView reaction if size change
        * @return void
        */
        void HandleClientRectChange();

		void BrowseFilesL(TMediaFileType aMediaType);

		void BrowseAudio(const TFileName& aPath);

    private:

		TBool VerifySelectionL (const MDesCArray *aSelectedFiles); 

		TBool OkToExitL (const TDesC &aDriveAndPath, const TEntry &aEntry);

        /**
        * From CAknView activate the view
        * @param aPrevViewId 
        * @param aCustomMessageId 
        * @param aCustomMessage 
        * @return void
        */
        void DoActivateL(const TVwsViewId& aPrevViewId,TUid aCustomMessageId,
            const TDesC8& aCustomMessage);

        /**
        * From CAknView deactivate the view (free resources)
        * @return void
        */
        void DoDeactivate();

    private: // Data
        CgoSIPMediaShareShareContainer* iContainer;
    };

#endif

// End of File
