/*
============================================================================
 Name        : CgoSIPPhonebookView2 from goSIPPhonebookView2.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Declares view for application.
============================================================================
*/

#ifndef GOSIP_PHONEBOOKVIEW2_H
#define GOSIP_PHONEBOOKVIEW2_H

// INCLUDES
#include <aknview.h>

#include <eikapp.h>
#include <eikdoc.h>
#include <e32std.h>
#include <coeccntx.h>

//#include <aknappui.h>

// CONSTANTS
#include "constantcontacts.h"
#include "goSIP.hrh"

// UID of view
const TUid KPhonebook2ViewId = {EgoSIPPhonebook2Tab};

// FORWARD DECLARATIONS
class CgoSIPPhonebookContainer2;

// CLASS DECLARATION

/**
*  CgoSIPPhonebookView2 view class.
* 
*/
class CgoSIPPhonebookView2 : public CAknView
    {
    public: // Constructors and destructor

        /**
        * EPOC default constructor.
        */
        void ConstructL();

        /**
        * Destructor.
        */
        ~CgoSIPPhonebookView2();

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
        CgoSIPPhonebookContainer2* iContainer;

    };

#endif


