/*
============================================================================
 Name        : CgoSIPAppUi from goSIPAppui.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Declares UI class for application.
============================================================================
*/

#ifndef GOSIPAPPUI_H
#define GOSIPAPPUI_H

// INCLUDES
//#include <aknappui.h>

#include <aknviewappui.h>
#include <akntabgrp.h>
#include <aknnavide.h>

#include <akntabobserver.h>

#include "goSIPGroupView.h"
#include "goSIPAddUserView.h"

// FORWARD DECLARATIONS
class CgoSIPContainer;
class CgoSIPGroupContainer;
class CgoSIPAddUserContainer;

// CLASS DECLARATION
class CgoSIPDocument;

/**
* Application UI class.
* Provides support for the following features:
* - EIKON control architecture
* - view architecture
* - status pane
* 
*/
class CgoSIPAppUi : public CAknViewAppUi, MAknTabObserver
    {
    public: // // Constructors and destructor

        /**
        * EPOC default constructor.
        */      
        void ConstructL();

        /**
        * Destructor.
        */      
        ~CgoSIPAppUi();
        
    public: // New functions
        TBool online;

    public: // Functions from base classes
		/**
        * From MAknTabObserver.
        * @param aIndex tab index
        */
		void TabChangedL(TInt aIndex);
        CgoSIPGroupView* GetGroupView();
        CgoSIPGroupContainer* GetGroupContainer();
        CAknTabGroup*           iTabGroup;
        CgoSIPUser* GetHighlightedUser();
            //my add
        CgoSIPGroupView* groupView;




    private:
        // From MEikMenuObserver
        void DynInitMenuPaneL(TInt aResourceId,CEikMenuPane* aMenuPane);

    private:
        /**
        * From CEikAppUi, takes care of command handling.
        * @param aCommand command to be handled
        */
        void HandleCommandL(TInt aCommand);

        /**
        * From CEikAppUi, handles key events.
        * @param aKeyEvent Event to handled.
        * @param aType Type of the key event. 
        * @return Response code (EKeyWasConsumed, EKeyWasNotConsumed). 
        */
        virtual TKeyResponse HandleKeyEventL(
            const TKeyEvent& aKeyEvent,TEventCode aType);
    private: //Data
        CAknNavigationControlContainer* iNaviPane;
        CAknNavigationDecorator* iDecoratedTabGroup;


        
        //CgoSIPDocument* GetDocument();
    };

#endif


