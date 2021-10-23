/*
============================================================================
 Name        : CgoSIPMediaShareUploadView from goSIPMediaShareUploadView.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : CgoSIPMediaShareUploadView declaration
============================================================================
*/

#ifndef GOSIPMEDIASHAREUPLOADVIEW_H
#define GOSIPMEDIASHAREUPLOADVIEW_H

// INCLUDES
#include <aknview.h>

#include "goSIP.hrh"

// CONSTANTS
// UID of view
const TUid KgoSIPMediaShareUploadViewId = {EgoSIPMediaShareUploadTab};

// FORWARD DECLARATIONS
class CgoSIPMediaShareUploadContainer;

// CLASS DECLARATION

/**
*  CgoSIPMediaShareUploadView view class.
* 
*/
class CgoSIPMediaShareUploadView : public CAknView
    {
    public: // Constructors and destructor

        /**
        * EPOC default constructor.
        */
        void ConstructL();

        /**
        * Destructor.
        */
        ~CgoSIPMediaShareUploadView();

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
        CgoSIPMediaShareUploadContainer* iContainer;
    };

#endif

// End of File
