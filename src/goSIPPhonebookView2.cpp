/*
============================================================================
 Name        : CgoSIPPhonebookView2 from goSIPPhonebookView2.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : CgoSIPPhonebookView2 implementation
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
//#include <goSIP.mbm>
#include "goSIPPhonebookView2.h"
#include "goSIPPhonebookContainer2.h" 

#include "goSIP.hrh"


// ================= MEMBER FUNCTIONS =======================

// ---------------------------------------------------------
// CgoSIPPhonebookView2::ConstructL(const TRect& aRect)
// EPOC two-phased constructor
// ---------------------------------------------------------
//
void CgoSIPPhonebookView2::ConstructL()
    {
    BaseConstructL( R_GOSIP_PHONEBOOK_VIEW2 );
    }

// ---------------------------------------------------------
// CgoSIPPhonebookView2::~CgoSIPPhonebookView2()
// destructor
// ---------------------------------------------------------
//
CgoSIPPhonebookView2::~CgoSIPPhonebookView2()
    {
    if ( iContainer )
        {
        AppUi()->RemoveFromViewStack( *this, iContainer );
        }

    delete iContainer;
    }

// ---------------------------------------------------------
// TUid CgoSIPPhonebookView2::Id()
// 
// ---------------------------------------------------------
//
TUid CgoSIPPhonebookView2::Id() const
    {
    return KPhonebook2ViewId;
    }

// ---------------------------------------------------------
// CgoSIPPhonebookView2::HandleCommandL(TInt aCommand)
// takes care of view command handling
// ---------------------------------------------------------
//
void CgoSIPPhonebookView2::HandleCommandL(TInt aCommand)
    {   
    switch ( aCommand )
        {
        case EAknSoftkeyOk:
            {
            iEikonEnv->InfoMsg( _L("view2 ok") );
            break;
            }
        case EAknSoftkeyBack:
            {
            AppUi()->HandleCommandL(EgoSIPCmdAppSharePhonebookClose);
            break;
            }
		case EShareContact:
			iEikonEnv->InfoMsg(_L("Sharing..."));
			break;
		case EShowContacts:
            iContainer->ShowContactsL();
            break;
		case EAknCmdMark:
		case EAknCmdUnmark:
			iContainer->HandleMarkCommandL(aCommand);
			break;
        default:
            {
            AppUi()->HandleCommandL( aCommand );
            break;
            }
        }
    }

// ---------------------------------------------------------
// CgoSIPPhonebookView2::HandleClientRectChange()
// ---------------------------------------------------------
//
void CgoSIPPhonebookView2::HandleClientRectChange()
    {
    if ( iContainer )
        {
        iContainer->SetRect( ClientRect() );
        }
    }

// ---------------------------------------------------------
// CgoSIPPhonebookView2::DoActivateL(...)
// 
// ---------------------------------------------------------
//
void CgoSIPPhonebookView2::DoActivateL(
   const TVwsViewId& /*aPrevViewId*/,TUid /*aCustomMessageId*/,
   const TDesC8& /*aCustomMessage*/)
    {
    if (!iContainer)
        {
        iContainer = new (ELeave) CgoSIPPhonebookContainer2;
        iContainer->SetMopParent(this);
        iContainer->ConstructL( ClientRect() );
		iContainer->OpenDefaultDatabaseL();
        AppUi()->AddToStackL( *this, iContainer );
        }
   }

// ---------------------------------------------------------
// CgoSIPPhonebookView2::DoDeactivate()
// 
// ---------------------------------------------------------
//
void CgoSIPPhonebookView2::DoDeactivate()
    {
    if ( iContainer )
        {
        AppUi()->RemoveFromViewStack( *this, iContainer );
        }
    
    delete iContainer;
    iContainer = NULL;
    }

