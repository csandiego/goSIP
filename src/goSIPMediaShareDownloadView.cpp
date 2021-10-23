/*
============================================================================
 Name        : CgoSIPMediaShareDownloadView from goSIPMediaShareDownloadView.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : CgoSIPMediaShareDownloadView implementation
============================================================================
*/

// INCLUDE FILES
#include  <aknviewappui.h>
#include  <avkon.hrh>
// TODO: Change the following include directive to point to the correct
// resource header file. The current value should be correct if the project
// was created using one of the templates provided by Nokia.
#include  <goSIP.rsg>
#include  "goSIPMediaShareDownloadView.h"
#include  "goSIPMediaShareDownloadContainer.h"

// ================= MEMBER FUNCTIONS =======================

// ---------------------------------------------------------
// CgoSIPMediaShareDownloadView::ConstructL(const TRect& aRect)
// EPOC two-phased constructor
// ---------------------------------------------------------
//
void CgoSIPMediaShareDownloadView::ConstructL()
    {
    BaseConstructL( R_GOSIP_GOSIPMEDIASHAREDOWNLOAD_VIEW );
    }

// ---------------------------------------------------------
// CgoSIPMediaShareDownloadView::~CgoSIPMediaShareDownloadView()
// destructor
// ---------------------------------------------------------
//
CgoSIPMediaShareDownloadView::~CgoSIPMediaShareDownloadView()
    {
    if ( iContainer )
        {
        AppUi()->RemoveFromViewStack( *this, iContainer );
        }

    delete iContainer;
    }

// ---------------------------------------------------------
// TUid CgoSIPMediaShareDownloadView::Id()
//
// ---------------------------------------------------------
//
TUid CgoSIPMediaShareDownloadView::Id() const
    {
    return KgoSIPMediaShareDownloadViewId;
    }

// ---------------------------------------------------------
// CgoSIPMediaShareDownloadView::HandleCommandL(TInt aCommand)
// takes care of view command handling
// ---------------------------------------------------------
//
void CgoSIPMediaShareDownloadView::HandleCommandL(TInt aCommand)
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
            AppUi()->HandleCommandL(EgoSIPCmdAppDownloadClose);
            break;
            }
        default:
            {
            AppUi()->HandleCommandL( aCommand );
            break;
            }
        }
    }

// ---------------------------------------------------------
// CgoSIPMediaShareDownloadView::HandleClientRectChange()
// ---------------------------------------------------------
//
void CgoSIPMediaShareDownloadView::HandleClientRectChange()
    {
    if ( iContainer )
        {
        iContainer->SetRect( ClientRect() );
        }
    }

// ---------------------------------------------------------
// CgoSIPMediaShareDownloadView::DoActivateL(...)
// 
// ---------------------------------------------------------
//
void CgoSIPMediaShareDownloadView::DoActivateL(
   const TVwsViewId& /*aPrevViewId*/,TUid /*aCustomMessageId*/,
   const TDesC8& /*aCustomMessage*/)
    {
    if (!iContainer)
        {
        iContainer = new (ELeave) CgoSIPMediaShareDownloadContainer;
        iContainer->SetMopParent(this);
        iContainer->ConstructL( ClientRect() );
        AppUi()->AddToStackL( *this, iContainer );
		iContainer->IncrementAndDrawBars();
        } 
   }

// ---------------------------------------------------------
// CgoSIPMediaShareDownloadView::DoDeactivate()
// 
// ---------------------------------------------------------
//
void CgoSIPMediaShareDownloadView::DoDeactivate()
    {
    if ( iContainer )
        {
        AppUi()->RemoveFromViewStack( *this, iContainer );
        }
    
    delete iContainer;
    iContainer = NULL;
    }

// End of File

