/*
============================================================================
 Name        : CgoSIPMediaShareUploadView from goSIPMediaShareUploadView.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : CgoSIPMediaShareUploadView implementation
============================================================================
*/

// INCLUDE FILES
#include  <aknviewappui.h>
#include  <avkon.hrh>
// TODO: Change the following include directive to point to the correct
// resource header file. The current value should be correct if the project
// was created using one of the templates provided by Nokia.
#include  <goSIP.rsg>
#include  "goSIPMediaShareUploadView.h"
#include  "goSIPMediaShareUploadContainer.h"

// ================= MEMBER FUNCTIONS =======================

// ---------------------------------------------------------
// CgoSIPMediaShareUploadView::ConstructL(const TRect& aRect)
// EPOC two-phased constructor
// ---------------------------------------------------------
//
void CgoSIPMediaShareUploadView::ConstructL()
    {
    BaseConstructL( R_GOSIP_GOSIPMEDIASHAREUPLOAD_VIEW );
    }

// ---------------------------------------------------------
// CgoSIPMediaShareUploadView::~CgoSIPMediaShareUploadView()
// destructor
// ---------------------------------------------------------
//
CgoSIPMediaShareUploadView::~CgoSIPMediaShareUploadView()
    {
    if ( iContainer )
        {
        AppUi()->RemoveFromViewStack( *this, iContainer );
        }

    delete iContainer;
    }

// ---------------------------------------------------------
// TUid CgoSIPMediaShareUploadView::Id()
//
// ---------------------------------------------------------
//
TUid CgoSIPMediaShareUploadView::Id() const
    {
    return KgoSIPMediaShareUploadViewId;
    }

// ---------------------------------------------------------
// CgoSIPMediaShareUploadView::HandleCommandL(TInt aCommand)
// takes care of view command handling
// ---------------------------------------------------------
//
void CgoSIPMediaShareUploadView::HandleCommandL(TInt aCommand)
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
            AppUi()->HandleCommandL(EgoSIPCmdAppUploadClose);
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
// CgoSIPMediaShareUploadView::HandleClientRectChange()
// ---------------------------------------------------------
//
void CgoSIPMediaShareUploadView::HandleClientRectChange()
    {
    if ( iContainer )
        {
        iContainer->SetRect( ClientRect() );
        }
    }

// ---------------------------------------------------------
// CgoSIPMediaShareUploadView::DoActivateL(...)
// 
// ---------------------------------------------------------
//
void CgoSIPMediaShareUploadView::DoActivateL(
   const TVwsViewId& /*aPrevViewId*/,TUid /*aCustomMessageId*/,
   const TDesC8& /*aCustomMessage*/)
    {
    if (!iContainer)
        {
        iContainer = new (ELeave) CgoSIPMediaShareUploadContainer;
        iContainer->SetMopParent(this);
        iContainer->ConstructL( ClientRect() );
        AppUi()->AddToStackL( *this, iContainer );
        } 
   }

// ---------------------------------------------------------
// CgoSIPMediaShareUploadView::DoDeactivate()
// 
// ---------------------------------------------------------
//
void CgoSIPMediaShareUploadView::DoDeactivate()
    {
    if ( iContainer )
        {
        AppUi()->RemoveFromViewStack( *this, iContainer );
        }
    
    delete iContainer;
    iContainer = NULL;
    }

// End of File

