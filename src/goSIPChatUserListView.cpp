/*
============================================================================
 Name        : CgoSIPChatUserListView from goSIPChatUserListView.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : CgoSIPChatUserListView implementation
============================================================================
*/

// INCLUDE FILES
#include  <aknviewappui.h>
#include  <avkon.hrh>
// TODO: Change the following include directive to point to the correct
// resource header file. The current value should be correct if the project
// was created using one of the templates provided by Nokia.
#include  <goSIP.rsg>
#include  "goSIPChatUserListView.h"
#include  "goSIPChatUserListContainer.h"
#include  "goSIPAppUi.h"
#include  <aknlistquerydialog.h>
#include "goSIP.hrh"
#include  "goSIPChatView.h"

// ================= MEMBER FUNCTIONS =======================

// ---------------------------------------------------------
// CgoSIPChatUserListView::ConstructL(const TRect& aRect)
// EPOC two-phased constructor
// ---------------------------------------------------------
//
void CgoSIPChatUserListView::ConstructL()
    {             //  r_gosip_gosipchatuserlist_view
    BaseConstructL( R_GOSIP_GOSIPCHATUSERLIST_VIEW);
    }

// ---------------------------------------------------------
// CgoSIPChatUserListView::~CgoSIPChatUserListView()
// destructor
// ---------------------------------------------------------
//
CgoSIPChatUserListView::~CgoSIPChatUserListView()
    {
    if ( iContainer )
        {
        AppUi()->RemoveFromViewStack( *this, iContainer );
        }

    delete iContainer;
    }

// ---------------------------------------------------------
// TUid CgoSIPChatUserListView::Id()
//
// ---------------------------------------------------------
//
TUid CgoSIPChatUserListView::Id() const
    {
    return KgoSIPChatUserListViewId;
    }

// ---------------------------------------------------------
// CgoSIPChatUserListView::HandleCommandL(TInt aCommand)
// takes care of view command handling
// ---------------------------------------------------------
//
void CgoSIPChatUserListView::HandleCommandL(TInt aCommand)
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
            // TODO: CLOSE THIS VIEW
            AppUi()->HandleCommandL(EgoSIPCmdUserListViewClose);
            //break;
            }
        //transferred to chatview
        /*case EgoSIPChatCmdInviteUsers:
            {
            iEikonEnv->InfoMsg( _L("Select Users") );
			InviteUsers();
            break;
            }*/
        default:
            {
            AppUi()->HandleCommandL( aCommand );
            break;
            }
        }
    }
//transferred to ChatUserListContainer
/*void CgoSIPChatUserListView::InviteUsers()
	{
		TInt index = -1;
		CAknListQueryDialog* invite;
		invite = new (ELeave) CAknListQueryDialog(&index);
						   //r_gosip_gosipchatuserlist_list_query
		if(invite->ExecuteLD(R_GOSIP_GOSIPCHATUSERLIST_LIST_QUERY))
		{
			if(index==0)
            {
				iEikonEnv->InfoMsg(_L("User Selected."));
			}
			else
			{
				iEikonEnv->InfoMsg(_L("Test."));
			}
		}
	}*/

// ---------------------------------------------------------
// CgoSIPChatUserListView::HandleClientRectChange()
// ---------------------------------------------------------
//
void CgoSIPChatUserListView::HandleClientRectChange()
    {
    if ( iContainer )
        {
        iContainer->SetRect( ClientRect() );
        }
    }

// ---------------------------------------------------------
// CgoSIPChatUserListView::DoActivateL(...)
// 
// ---------------------------------------------------------
//
void CgoSIPChatUserListView::DoActivateL(
   const TVwsViewId& /*aPrevViewId*/,TUid /*aCustomMessageId*/,
   const TDesC8& /*aCustomMessage*/)
    {
    if (!iContainer)
        {
        iContainer = new (ELeave) CgoSIPChatUserListContainer;
        iContainer->SetMopParent(this);
        iContainer->ConstructL( ClientRect() );
        AppUi()->AddToStackL( *this, iContainer );
		/*
        if(arrayViewSource->GetArray())
            {
            iContainer->iListBoxArray = arrayViewSource->GetArray();
            iContainer->iListBox->Model()->SetItemTextArray(iContainer->iListBoxArray);
            iContainer->SizeChanged();
            }
        else
            {
            iEikonEnv->InfoMsg( _L("null arr_src") );
            }*/
        } 
   }

// ---------------------------------------------------------
// CgoSIPChatUserListView::DoDeactivate()
// 
// ---------------------------------------------------------
//
void CgoSIPChatUserListView::DoDeactivate()
    {
    if ( iContainer )
        {
        AppUi()->RemoveFromViewStack( *this, iContainer );
        }
    
    delete iContainer;
    iContainer = NULL;
    }

CgoSIPChatUserListContainer* CgoSIPChatUserListView::GetContainer()
    {
    return iContainer;
    }

void CgoSIPChatUserListView::SetViewSource(CgoSIPChatView* view)
    {
    arrayViewSource = view;
    }
// End of File

