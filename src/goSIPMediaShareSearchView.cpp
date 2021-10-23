/*
============================================================================
 Name        : CgoSIPMediaShareSearchView from goSIPMediaShareSearchView.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : CgoSIPMediaShareSearchView implementation
============================================================================
*/

// INCLUDE FILES
#include  <aknviewappui.h>
#include  <avkon.hrh>
// TODO: Change the following include directive to point to the correct
// resource header file. The current value should be correct if the project
// was created using one of the templates provided by Nokia.
#include  <goSIP.rsg>
#include  "goSIPMediaShareSearchView.h"
#include  "goSIPMediaShareSearchContainer.h"
#include  "goSIPMediaShareDownloadView.h"
#include  "goSIPAppUi.h"
#include "goSIP.hrh"

// ================= MEMBER FUNCTIONS =======================

// ---------------------------------------------------------
// CgoSIPMediaShareSearchView::ConstructL(const TRect& aRect)
// EPOC two-phased constructor
// ---------------------------------------------------------
//
void CgoSIPMediaShareSearchView::ConstructL()
    {
    BaseConstructL( R_GOSIP_GOSIPMEDIASHARESEARCH_VIEW );
    }

// ---------------------------------------------------------
// CgoSIPMediaShareSearchView::~CgoSIPMediaShareSearchView()
// destructor
// ---------------------------------------------------------
//
CgoSIPMediaShareSearchView::~CgoSIPMediaShareSearchView()
    {
    if ( iContainer )
        {
        AppUi()->RemoveFromViewStack( *this, iContainer );
        }

    delete iContainer;
    }

// ---------------------------------------------------------
// TUid CgoSIPMediaShareSearchView::Id()
//
// ---------------------------------------------------------
//
TUid CgoSIPMediaShareSearchView::Id() const
    {
    return KgoSIPMediaShareSearchViewId;
    }

// ---------------------------------------------------------
// CgoSIPMediaShareSearchView::HandleCommandL(TInt aCommand)
// takes care of view command handling
// ---------------------------------------------------------
//
void CgoSIPMediaShareSearchView::HandleCommandL(TInt aCommand)
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
            AppUi()->HandleCommandL(EgoSIPCmdAppSearchFilesClose);
            break;
            }
		case EgoSIPMediaShareSearch:
            {
			iContainer->SearchFileL();
			break;
            }
/*		case EgoSIPMediaShareConfirm:
            {
			CAknQueryDialog* iQueryDialog = CAknQueryDialog::NewL(CAknQueryDialog::ENoTone);
			if(iQueryDialog->ExecuteLD(R_AKNEXQUERY_CONFIRMATION_NO_ICON_QUERY))
			{
				AppUi()->ActivateLocalViewL(KgoSIPMediaShareDownloadViewId);
				AppUi()->iTabGroup->SetActiveTabById(EgoSIPMediaShareDownloadTab);
			}
		    
			iQueryDialog = NULL;
			break;
            }*/
		default:
            {
            AppUi()->HandleCommandL( aCommand );
            break;
            }
        }
    }

// ---------------------------------------------------------
// CgoSIPMediaShareSearchView::HandleClientRectChange()
// ---------------------------------------------------------
//
void CgoSIPMediaShareSearchView::HandleClientRectChange()
    {
    if ( iContainer )
        {
        iContainer->SetRect( ClientRect() );
        }
    }

// ---------------------------------------------------------
// CgoSIPMediaShareSearchView::DoActivateL(...)
// 
// ---------------------------------------------------------
//
void CgoSIPMediaShareSearchView::DoActivateL(
   const TVwsViewId& /*aPrevViewId*/,TUid /*aCustomMessageId*/,
   const TDesC8& /*aCustomMessage*/)
    {
    if (!iContainer)
        {
        iContainer = new (ELeave) CgoSIPMediaShareSearchContainer;
        iContainer->SetMopParent(this);
        iContainer->ConstructL( ClientRect() );
		iContainer->SearchFileL();
        AppUi()->AddToStackL( *this, iContainer );
        } 
   }

// ---------------------------------------------------------
// CgoSIPMediaShareSearchView::DoDeactivate()
// 
// ---------------------------------------------------------
//
void CgoSIPMediaShareSearchView::DoDeactivate()
    {
    if ( iContainer )
        {
        AppUi()->RemoveFromViewStack( *this, iContainer );
        }
    
    delete iContainer;
    iContainer = NULL;
    }

// End of File

