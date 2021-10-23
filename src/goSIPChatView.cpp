/*
============================================================================
 Name        : CgoSIPChatView from goSIPChatView.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : CgoSIPChatView implementation
============================================================================
*/

// INCLUDE FILES
#include  <aknviewappui.h>
#include  <avkon.hrh>
// TODO: Change the following include directive to point to the correct
// resource header file. The current value should be correct if the project
// was created using one of the templates provided by Nokia.
#include  <goSIP.rsg>
#include  "goSIPChatView.h"
#include  "goSIPChatContainer.h"

// My includes
#include <aknquerydialog.h>
#include "goSIP.hrh"
#include <eikmenub.h>


// ================= MEMBER FUNCTIONS =======================

// ---------------------------------------------------------
// CgoSIPChatView::ConstructL(const TRect& aRect)
// EPOC two-phased constructor
// ---------------------------------------------------------
//
void CgoSIPChatView::ConstructL()
    {
    BaseConstructL( R_GOSIP_GOSIPCHAT_VIEW );
    iBuffer = NULL;
    TBool iDisplayUserList = EFalse;
    }

// ---------------------------------------------------------
// CgoSIPChatView::~CgoSIPChatView()
// destructor
// ---------------------------------------------------------
//
CgoSIPChatView::~CgoSIPChatView()
    {
    if ( iContainer )
        {
        AppUi()->RemoveFromViewStack( *this, iContainer );
        }

    delete iContainer;
    delete iBuffer;
    }

// ---------------------------------------------------------
// TUid CgoSIPChatView::Id()
//
// ---------------------------------------------------------
//
TUid CgoSIPChatView::Id() const
    {
    return KgoSIPChatViewId;
    }

// ---------------------------------------------------------
// CgoSIPChatView::HandleCommandL(TInt aCommand)
// takes care of view command handling
// ---------------------------------------------------------
//
void CgoSIPChatView::HandleCommandL(TInt aCommand)
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
				if(iDisplayUserList)
				{
					MenuBar()->SetMenuTitleResourceId(R_GOSIP_GOSIPCHAT_MENUBAR);
					iDisplayUserList = EFalse;
					break;
				}
			}
		case EgoSIPChatCmdClose:
            {
			CAknQueryDialog* quitDialog = CAknQueryDialog::NewL();
			CleanupStack::PushL(quitDialog);
			quitDialog->SetPromptL(_L("Close chat?"));
			CleanupStack::Pop();
			if(quitDialog->ExecuteLD(R_GOSIP_GOSIPCHAT_CLOSE_DIALOG))
				{
				CAknQueryDialog* saveDialog = CAknQueryDialog::NewL();
				CleanupStack::PushL(saveDialog);
				saveDialog->SetPromptL(_L("Save chat?"));
				CleanupStack::Pop();
				if(saveDialog->ExecuteLD(R_GOSIP_GOSIPCHAT_SAVE_DIALOG))
					{
					TBuf<256> filename;
					CAknTextQueryDialog* filenameQuery = CAknTextQueryDialog::NewL(filename);
					CleanupStack::PushL(filenameQuery);
					filenameQuery->SetPromptL(_L("Filename"));
					CleanupStack::Pop();
					if(filenameQuery->ExecuteLD(R_GOSIP_GOSIPCHAT_SAVEFILENAME_DIALOG))
						{
                         iContainer->SaveToFileL(filename);
						}
					}
	            AppUi()->HandleCommandL(EgoSIPCmdAppChatClose);
				}
            break;
            }
		case EgoSIPChatCmdWriteMessage:
			{
			iContainer->WriteMessageL();
			break;
			}
        case EgoSIPChatCmdDisplayUserList:
			{
            
				// Try to change the view menu
				MenuBar()->SetMenuTitleResourceId(R_GOSIP_GOSIPCHATUSERLIST_MENUBAR);
				iDisplayUserList = ETrue;
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
// CgoSIPChatView::HandleClientRectChange()
// ---------------------------------------------------------
//
void CgoSIPChatView::HandleClientRectChange()
    {
    if ( iContainer )
        {
        iContainer->SetRect( ClientRect() );
        }
    }

// ---------------------------------------------------------
// CgoSIPChatView::DoActivateL(...)
// 
// ---------------------------------------------------------
//
void CgoSIPChatView::DoActivateL(
   const TVwsViewId& /*aPrevViewId*/,TUid /*aCustomMessageId*/,
   const TDesC8& /*aCustomMessage*/)
    {
    if (!iContainer)
    {
        //for ChatContainer
        iContainer = new (ELeave) CgoSIPChatContainer;
        iContainer->SetMopParent(this);
        iContainer->ConstructL( ClientRect() );
		if(iBuffer)
		{
			iContainer->LoadFromBufferL(*iBuffer);
			delete iBuffer;
			iBuffer = NULL;
		}
        AppUi()->AddToStackL( *this, iContainer );
        }
     }

// ---------------------------------------------------------
// CgoSIPChatView::DoDeactivate()
// 
// ---------------------------------------------------------
//
void CgoSIPChatView::DoDeactivate()
    {
    if ( iContainer )
        {
        AppUi()->RemoveFromViewStack( *this, iContainer );
		if(!iBuffer) 
			{
			iBuffer = iContainer->SaveToHBufL();
			}
        }
    
    delete iContainer;
    iContainer = NULL;
    }

// End of File
