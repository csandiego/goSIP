/*
============================================================================
 Name        : CgoSIPAddUserView from goSIPAddUserView.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Declares view for application.
============================================================================
*/

#ifndef GOSIPADDUSERVIEW_H
#define GOSIPADDUSERVIEW_H

// INCLUDES
#include <aknview.h>
//query
#include <aknnavide.h>
#include <aknquerydialog.h>

#include "goSIP.hrh"


// CONSTANTS
// UID of view
const TUid KAddUserViewId = {EgoSIPAddUserTab};
//setting list
const TInt KgoSIPAddUserTitleBufLength = 256;

// FORWARD DECLARATIONS
class CgoSIPAddUserContainer;
//AddUser class addition
class CgoSIPAppUi;
//setting list
class CgoSIPAddUserContainer;
class CgoSIPAddUserListBox;
class CgoSIPAddUserItemData;

// CLASS DECLARATION

/**
*  CgoSIPView view class.
* 
*/
class CgoSIPAddUserView : public CAknView
    {
    public: // Constructors and destructor
		CgoSIPAddUserView();

        /**
        * EPOC default constructor.
        */
        void ConstructL(/*CgoSIPAppUi* igoSIPAppUi*/);

        /**
        * Destructor.
        */
        ~CgoSIPAddUserView();

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
		//AddUser methods 
		//from MEikMenuObserver for dynamic menu
		void DynInitMenuPaneL(TInt aResourceId, CEikMenuPane* aMenuPane);
		
		void CgoSIPAddUserView::changeNaviLabel(TInt aResourceId);
		//form
		void IndicateTitlePaneTextL( TInt aCommand );
		void DisplayFormL(TInt aResourceId);
		//setting list
		//void SwapContainerL( TBool aActiveContainer );
		void CreateListBoxL( TInt aResourceId );
		//end AddUser methods
		
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
        CgoSIPAddUserContainer* iContainer;
		//CgoSIPAppUi*	igoSIPAppUi;
		CAknNavigationDecorator* iNaviDecorator;
		//TInt iCurrentOutline;
		//setting list
		TBool iActiveContainer;
		CgoSIPAddUserItemData*      iData;
	public:
		CgoSIPAddUserListBox*       iListBox;
		TKeyEvent key;
    };
#endif
