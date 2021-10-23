/*
============================================================================
 Name        : CgoSIPView from goSIPView.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Declares view for application.
============================================================================
*/

#ifndef GOSIPGROUPVIEW_H
#define GOSIPGROUPVIEW_H

// INCLUDES
#include <aknview.h>
#include "goSIPUser.h"
#include "goSIP.hrh"

// CONSTANTS
// UID of view
const TUid KGroupViewId = {EgoSIPGroupTab};

// FORWARD DECLARATIONS
class CgoSIPGroupContainer;
//class CgoSIPDocument;

// CLASS DECLARATION

/**
*  CgoSIPView view class.
* 
*/
class CgoSIPGroupView : public CAknView
    {
    public: // Constructors and destructor

        /**
        * EPOC default constructor.
        */
        void ConstructL();

        /**
        * Destructor.
        */
        ~CgoSIPGroupView();

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

		// my add 050923
		void DynInitMenuPaneL(TInt aResourceId,CEikMenuPane* aMenuPane);

    //my add
    public:
        CgoSIPGroupContainer* GetContainer();
        CgoSIPUser* GetHighlightedUser() const;
        CgoSIPGroupContainer* iContainer;
        /*CgoSIPDocument* document;
        void SetDocument(CgoSIPDocument* doc);*/
    };

#endif


