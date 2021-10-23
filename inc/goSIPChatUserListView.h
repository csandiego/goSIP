/*
============================================================================
 Name        : CgoSIPChatUserListView from goSIPChatUserListView.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : CgoSIPChatUserListView declaration
============================================================================
*/

#ifndef GOSIPCHATUSERLISTVIEW_H
#define GOSIPCHATUSERLISTVIEW_H

// INCLUDES
#include <aknview.h>
#include "goSIP.hrh"

// CONSTANTS
// UID of view
const TUid KgoSIPChatUserListViewId = {EgoSIPChatUserListTab};

// FORWARD DECLARATIONS
class CgoSIPChatUserListContainer;
class CgoSIPChatView;

// CLASS DECLARATION

/**
*  CgoSIPChatUserListView view class.
* 
*/
class CgoSIPChatUserListView : public CAknView
    {
    public: // Constructors and destructor

        /**
        * EPOC default constructor.
        */
        void ConstructL();

        /**
        * Destructor.
        */
        ~CgoSIPChatUserListView();

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
		void InviteUsers();
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
        CgoSIPChatUserListContainer* iContainer;
        CgoSIPChatView* arrayViewSource;

    public:
        CgoSIPChatUserListContainer* GetContainer();
        void SetViewSource(CgoSIPChatView* arrayViewSource);
    };

#endif

// End of File
