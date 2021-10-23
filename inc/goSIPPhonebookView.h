/*
============================================================================
 Name        : CgoSIPPhonebookView from goSIPPhonebookView.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Declares view for application.
============================================================================
*/

#ifndef goSIPPhonebookView_H
#define goSIPPhonebookView_H

// INCLUDES
#include <aknview.h>

#include <eikapp.h>
#include <eikdoc.h>
#include <e32std.h>
#include <coeccntx.h>
//#include <aknappui.h>

#include "goSIP.hrh"
// CONSTANTS *FROM CONTACTS S60 SAMPLE*
#include "constantcontacts.h"

// UID of view
const TUid KPhonebookViewId = {EgoSIPPhonebookTab};

// FORWARD DECLARATIONS
class CgoSIPPhonebookContainer;

// CLASS DECLARATION

/**
*  CgoSIPPhonebookView view class.
* 
*/
class CgoSIPPhonebookView : public CAknView
    {
    public: // Constructors and destructor

        /**
        * EPOC default constructor.
        */
        void ConstructL();

        /**
        * Destructor.
        */
        ~CgoSIPPhonebookView();

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
        CgoSIPPhonebookContainer* iContainer;

    };

#endif


