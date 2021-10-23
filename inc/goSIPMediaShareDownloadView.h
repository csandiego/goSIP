/*
============================================================================
 Name        : CgoSIPMediaShareDownloadView from goSIPMediaShareDownloadView.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : CgoSIPMediaShareDownloadView declaration
============================================================================
*/

#ifndef GOSIPMEDIASHAREDOWNLOADVIEW_H
#define GOSIPMEDIASHAREDOWNLOADVIEW_H

// INCLUDES
#include <aknview.h>
#include "eikenv.h"
#include "goSIP.hrh"


// CONSTANTS
// UID of view
const TUid KgoSIPMediaShareDownloadViewId = {EgoSIPMediaShareDownloadTab};

// FORWARD DECLARATIONS
class CgoSIPMediaShareDownloadContainer;

// CLASS DECLARATION

/**
*  CgoSIPMediaShareDownloadView view class.
* 
*/
class CgoSIPMediaShareDownloadView : public CAknView
    {
    public: // Constructors and destructor

        /**
        * EPOC default constructor.
        */
        void ConstructL();

        /**
        * Destructor.
        */
        ~CgoSIPMediaShareDownloadView();

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

    private:

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
        CgoSIPMediaShareDownloadContainer* iContainer;
    };

#endif

// End of File
