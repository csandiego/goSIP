/*
============================================================================
 Name        : CgoSIPPhonebookView from goSIPPhonebookView.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : CgoSIPPhonebookView implementation
============================================================================
*/

// INCLUDE FILES
#include <goSIP.rsg>
#include <aknviewappui.h>
#include <avkon.hrh>
#include <eikmenup.h>
#include <eikmenub.h>
#include <akntitle.h>
#include <stringloader.h>

#include "goSIPPhonebookView.h"
#include "goSIPPhonebookContainer.h" 

#include "goSIP.hrh"


// ================= MEMBER FUNCTIONS =======================

// ---------------------------------------------------------
// CgoSIPPhonebookView::ConstructL(const TRect& aRect)
// EPOC two-phased constructor
// ---------------------------------------------------------
//
void CgoSIPPhonebookView::ConstructL()
    {
    BaseConstructL( R_GOSIP_PHONEBOOK_VIEW1 );

    }

// ---------------------------------------------------------
// CgoSIPPhonebookView::~CgoSIPPhonebookView()
// destructor
// ---------------------------------------------------------
//
CgoSIPPhonebookView::~CgoSIPPhonebookView()
    {
    if ( iContainer )
        {
        AppUi()->RemoveFromViewStack( *this, iContainer );
        }

    delete iContainer;
    }

// ---------------------------------------------------------
// TUid CgoSIPPhonebookView::Id()
//
// ---------------------------------------------------------
//
TUid CgoSIPPhonebookView::Id() const
    {
    return KPhonebookViewId;
    }

// ---------------------------------------------------------
// CgoSIPPhonebookView::HandleCommandL(TInt aCommand)
// takes care of view command handling
// ---------------------------------------------------------
//
void CgoSIPPhonebookView::HandleCommandL(TInt aCommand)
    {   
    switch ( aCommand )
        {
        case EAknSoftkeyOk:
            {
            iEikonEnv->InfoMsg( _L("view1 ok") );
            break;
            }
        case EAknSoftkeyBack:
            {
            AppUi()->HandleCommandL(EgoSIPCmdAppSearchPhonebooksClose);
            break;
            }
		case ECallContact:
			iEikonEnv->InfoMsg(_L("Calling..."));
			break;
		case ESMSContact:
			iEikonEnv->InfoMsg(_L("Open SMS..."));
			break;
		case ECopyContact:
			iEikonEnv->InfoMsg(_L("Copying..."));
			break;
		case EShowContacts:
            iContainer->ShowContactsL();
            break;
        default:
            {
            AppUi()->HandleCommandL( aCommand );
            break;
            }
        }
    }

// ---------------------------------------------------------
// CgoSIPPhonebookView::HandleClientRectChange()
// ---------------------------------------------------------
//
void CgoSIPPhonebookView::HandleClientRectChange()
    {
    if ( iContainer )
        {
        iContainer->SetRect( ClientRect() );
        }
    }

// ---------------------------------------------------------
// CgoSIPPhonebookView::DoActivateL(...)
// 
// ---------------------------------------------------------
//
void CgoSIPPhonebookView::DoActivateL(
   const TVwsViewId& /*aPrevViewId*/,TUid /*aCustomMessageId*/,
   const TDesC8& /*aCustomMessage*/)
    {
    if (!iContainer)
        {
        iContainer = new (ELeave) CgoSIPPhonebookContainer;
        iContainer->SetMopParent(this);
        iContainer->ConstructL( ClientRect() );
		iContainer->OpenDefaultDatabaseL(); //fake
        AppUi()->AddToStackL( *this, iContainer );
        } 
   }

// ---------------------------------------------------------
// CgoSIPPhonebookView::DoDeactivate()
// 
// ---------------------------------------------------------
//
void CgoSIPPhonebookView::DoDeactivate()
    {
    if ( iContainer )
        {
        AppUi()->RemoveFromViewStack( *this, iContainer );
        }
    
    delete iContainer;
    iContainer = NULL;
    }



