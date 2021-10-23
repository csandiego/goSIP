/*
============================================================================
 Name        : CgoSIPView from goSIPView.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Declares view for application.
============================================================================
*/

#ifndef GOSIPVIEWGROUP_H
#define GOSIPVIEWGROUP_H

// INCLUDES
#include <aknview.h>


// CONSTANTS
// UID of view
const TUid KViewGroupId = {100};

// FORWARD DECLARATIONS
class CgoSIPContainerGroup;
//class CgoSIPDocument;

// CLASS DECLARATION

/**
*  CgoSIPView view class.
* 
*/
class CgoSIPViewGroup : public CAknView
    {
    public: // Constructors and destructor

        /**
        * EPOC default constructor.
        */
        void ConstructL();

        /**
        * Destructor.
        */
        ~CgoSIPViewGroup();

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
        CgoSIPContainerGroup* iContainer;

		// my add 050923
		void DynInitMenuPaneL(TInt aResourceId,CEikMenuPane* aMenuPane);

    //my add
    public:
        CgoSIPContainerGroup* GetContainer();

        /*CgoSIPDocument* document;
        void SetDocument(CgoSIPDocument* doc);*/
    };

#endif


