/*
============================================================================
 Name        : CgoSIPAppointView from goSIPAppointView.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Declares view for application.
============================================================================
*/

#ifndef GOSIPVIEWAPPOINT_H
#define GOSIPVIEWAPPOINT_H

// INCLUDES
#include <aknview.h>
//query
#include <aknnavide.h>
#include <aknquerydialog.h>

#include "goSIP.hrh"

// CONSTANTS
// UID of view
const TUid KAppointViewId = {EgoSIPAppointTab};
//setting list
const TInt KgoSIPAppointTitleBufLength = 256;

// FORWARD DECLARATIONS
class CgoSIPAppointContainer;
//appoint class addition
class CgoSIPAppUi;
//setting list
class CgoSIPAppointContainer;
class CgoSIPAppointListbox;
class CgoSIPAppointItemData;

// CLASS DECLARATION

/**
*  CgoSIPView view class.
* 
*/
class CgoSIPAppointView : public CAknView
    {
    public: // Constructors and destructor
		CgoSIPAppointView();

        /**
        * EPOC default constructor.
        */
        void ConstructL(/*CgoSIPAppUi* igoSIPAppUi*/);

        /**
        * Destructor.
        */
        ~CgoSIPAppointView();

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
		//appoint methods 
		//from MEikMenuObserver for dynamic menu
		void DynInitMenuPaneL(TInt aResourceId, CEikMenuPane* aMenuPane);
		void DynInitMenuBarL(TInt aResourceId, CEikMenuPane* aMenuPane);
		TBool DimAppointMenu();
		void QuitAppointDialog();
		void CgoSIPAppointView::changeNaviLabel(TInt aResourceId);
		//form
		void IndicateTitlePaneTextL( TInt aCommand );
		void DisplayFormL(TInt aResourceId);
		//setting list
		//void SwapContainerL( TBool aActiveContainer );
		void CreateListBoxL( TInt aResourceId );
		//end appoint methods
		
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
		//dynamic setting list
		void PopulateModelL() const;

		void SaveIntoCalendar();
    private: // Data
        CgoSIPAppointContainer* iContainer;
		//appoint variables
		TBool			createSession;
		TBool			confirmed;
		//CgoSIPAppUi*	igoSIPAppUi;
		CAknNavigationDecorator* iNaviDecorator;
		//TInt iCurrentOutline;
		//setting list
		TBool iActiveContainer;
		CgoSIPAppointItemData*      iData;
	public:
		CgoSIPAppointListbox*       iListBox;
		TKeyEvent key;
    };
#endif
