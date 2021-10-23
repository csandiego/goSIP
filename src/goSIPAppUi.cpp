/*
============================================================================
Name        : CgoSIPAppUi from goSIPAppui.cpp
Author      : 
Version     :
Copyright   : Your copyright notice
Description : CgoSIPAppUi implementation
============================================================================
*/

#include "goSIPAppui.h"

#include <goSIP.rsg>
#include "goSIP.hrh"
#include "goSIPDocument.h"


#include <avkon.hrh>


// admin headers
#include "goSIPGroupView.h"
#include "goSIPGroupContainer.h" 
#include "goSIPAddUserView.h"

//container header
#include "goSIPChatUserListContainer.h"
#include "goSIPChatContainer.h"
#include "goSIPChatView.h"

//view header
#include "goSIPChatUserListView.h"

// appoint headers
#include "goSIPAppointView.h"

// media share headers
#include "goSIPMediashareSearchView.h"
#include "goSIPMediashareShareView.h"
#include "goSIPMediashareDownloadView.h"
#include "goSIPMediashareUploadView.h"

// phonebook
#include "goSIPPhonebookView.h"
#include "goSIPPhonebookView2.h"

// ================= MEMBER FUNCTIONS =======================
//
// ----------------------------------------------------------
// CgoSIPAppUi::ConstructL()
// 
// ----------------------------------------------------------
//
void CgoSIPAppUi::ConstructL()
{
	BaseConstructL();
	// my add 050923
	online = EFalse;

	// Show tabs for main views from resources
	CEikStatusPane* sp = StatusPane();

	// Fetch pointer to the default navi pane control
	iNaviPane = (CAknNavigationControlContainer*)sp->ControlL( 
		TUid::Uid(EEikStatusPaneUidNavi));

	// Tabgroup has been read from resource and it were pushed to the navi pane. 
	// Get pointer to the navigation decorator with the ResourceDecorator() function. 
	// Application owns the decorator and it has responsibility to delete the object.
	iDecoratedTabGroup = iNaviPane->ResourceDecorator();
	if (iDecoratedTabGroup)
	{
		iTabGroup = (CAknTabGroup*) iDecoratedTabGroup->DecoratedControl();
		iTabGroup->SetObserver( this );
	}

	groupView = new (ELeave) CgoSIPGroupView;

	CleanupStack::PushL( groupView );

	//groupView->SetDocument(GetDocument());

	groupView->ConstructL();
	AddViewL( groupView );      // transfer ownership to CAknViewAppUi
	CleanupStack::Pop();    // view1


//	iTabGroup->AddTabL(KGroupViewId.iUid,_L("Groups") );   // create tab(id,desc)
//	iTabGroup->SetActiveTabById(KGroupViewId.iUid);
	// my comment SetDefaultViewL(*view1);

	SetDefaultViewL(*groupView);
}

// ----------------------------------------------------
// CgoSIPAppUi::~CgoSIPAppUi()
// Destructor
// Frees reserved resources
// ----------------------------------------------------
//
CgoSIPAppUi::~CgoSIPAppUi()
{
	delete iDecoratedTabGroup;
}

// ------------------------------------------------------------------------------
// CgoSIPAppUi::DynInitMenuPaneL(TInt aResourceId,CEikMenuPane* aMenuPane)
//  This function is called by the EIKON framework just before it displays
//  a menu pane. Its default implementation is empty, and by overriding it,
//  the application can set the state of menu items dynamically according
//  to the state of application data.
// ------------------------------------------------------------------------------
//
void CgoSIPAppUi::DynInitMenuPaneL(
								   TInt /*aResourceId*/,CEikMenuPane* /*aMenuPane*/)
{
}

// ----------------------------------------------------
// CgoSIPAppUi::HandleKeyEventL(
//     const TKeyEvent& aKeyEvent,TEventCode /*aType*/)
// takes care of key event handling
// ----------------------------------------------------
//
TKeyResponse CgoSIPAppUi::HandleKeyEventL(
	const TKeyEvent& aKeyEvent,TEventCode aType)
{
	if ( iTabGroup == NULL )
	{
		return EKeyWasNotConsumed;
	}

	if ( aKeyEvent.iCode == EKeyLeftArrow || aKeyEvent.iCode == EKeyRightArrow )
	{
		return iTabGroup->OfferKeyEventL( aKeyEvent, aType );
	}
	else
	{
		return EKeyWasNotConsumed;
	}
}

// ----------------------------------------------------
// CgoSIPAppUi::HandleCommandL(TInt aCommand)
// takes care of command handling
// ----------------------------------------------------
//
void CgoSIPAppUi::HandleCommandL(TInt aCommand)
{
	switch ( aCommand )
	{
	case EEikCmdExit:
		{
			groupView->GetContainer()->CloseList();
			Exit();
			break;
		}
		// admin add
	case EgoSIPCmdAppAddUser:
		{
			if( iTabGroup->TabIndexFromId(KAddUserViewId.iUid) == -1){
				CgoSIPAddUserView* viewAddUser = new (ELeave) CgoSIPAddUserView;  // create view
				CleanupStack::PushL( viewAddUser );
				viewAddUser->ConstructL();
				AddViewL( viewAddUser );      // transfer ownership to CAknViewAppUi
				CleanupStack::Pop();    // adduser
				iTabGroup->AddTabL(KAddUserViewId.iUid,_L("Add User") );   // create tab(id,desc)
			}
			// switch to the view, activate the tab
			ActivateLocalViewL(KAddUserViewId);
			iTabGroup->SetActiveTabById(KAddUserViewId.iUid);
			break;
		}
	case EgoSIPCmdAppDeleteUser:
		{
			if(groupView->GetContainer()->iListBox->CurrentItemIndex() != groupView->GetContainer()->iFamilyIndex
				&& groupView->GetContainer()->iListBox->CurrentItemIndex() != groupView->GetContainer()->iFriendIndex
				&& groupView->GetContainer()->iListBox->CurrentItemIndex() != groupView->GetContainer()->iWorkmateIndex)
			    {
				//groupView->GetContainer()->document->iListBoxArray->Delete(groupView->GetContainer()->iListBox->CurrentItemIndex());
				//if(groupView->GetContainer()->iListBoxArray)
				//{
					groupView->GetContainer()->iListBoxArray->Delete(groupView->GetContainer()->iListBox->CurrentItemIndex());
					groupView->GetContainer()->GetGroupIndex();
					groupView->GetContainer()->iListBoxArray->Compress();
                    groupView->GetContainer()->userArray.Remove(groupView->GetContainer()->iListBox->CurrentItemIndex());
                    groupView->GetContainer()->userArray.Compress();
					HandleModelChangeL();
					groupView->GetContainer()->SaveList();
				/*}
				else
				{
					iEikonEnv->InfoMsg(_L("null"));
				}*/
				//iEikonEnv->InfoMsg(_L("delete"));
                }
			break;
		}
	case EgoSIPCmdAddUserClose:
		{
			// Delete tab and view
			iTabGroup->DeleteTabL(KAddUserViewId.iUid);

			CAknView* temp = NULL;
			temp = View(KAddUserViewId);
			DeactivateActiveViewL();
			DeregisterView(*temp);
			//delete temp;

			// Activate the Group view and tab
			ActivateLocalViewL(KGroupViewId);
			iTabGroup->SetActiveTabById(KGroupViewId.iUid);
			break;
		}
		// MYADD chat command
     case EgoSIPCmdUserListViewClose:
		    {
			    // Delete tab and view
			    iTabGroup->DeleteTabL(KgoSIPChatUserListViewId.iUid);

			    CAknView* temp = NULL;
			    temp = View(KgoSIPChatUserListViewId);
			    DeactivateActiveViewL();
			    DeregisterView(*temp);
			    //delete temp;

			    // Activate the Group view and tab
			    ActivateLocalViewL(KgoSIPChatViewId);
			    iTabGroup->SetActiveTabById(KgoSIPChatViewId.iUid);
			    break;
            }
	case EgoSIPCmdAppChat:
		{
        
			CgoSIPChatView* chatview = new (ELeave) CgoSIPChatView;
			CleanupStack::PushL(chatview);
			chatview->ConstructL();
            //chatview->SetContainer(GetGroupContainer());
			AddViewL(chatview);
			CleanupStack::Pop();

    		iTabGroup->AddTabL(KgoSIPChatViewId.iUid,_L("Chat") );   // create tab(id,desc)
			ActivateLocalViewL(KgoSIPChatViewId);
			iTabGroup->SetActiveTabById(KgoSIPChatViewId.iUid);
            
            /*if( groupView->GetContainer() ){
                User::InfoPrint( _L("not null"));
                }else{
User::InfoPrint(_L("is null"));
                    }*/
            break;
		}
    case EgoSIPCmdAppChatClose:
		{
			// Delete tab and view
			iTabGroup->DeleteTabL(KgoSIPChatViewId.iUid);

			CAknView* temp = NULL;
			temp = View(KgoSIPChatViewId);
			DeactivateActiveViewL();
			DeregisterView(*temp);
			//delete temp;

			// Activate the Group view and tab
			ActivateLocalViewL(KGroupViewId);
			iTabGroup->SetActiveTabById(KGroupViewId.iUid);
			break;
		}
	// MYADD mediashare command
	case EgoSIPCmdAppSearchFiles:
		{

			CgoSIPMediaShareSearchView* searchView = new (ELeave) CgoSIPMediaShareSearchView;
			CleanupStack::PushL( searchView );
			searchView->ConstructL();
			AddViewL( searchView );      // transfer ownership to CAknViewAppUi
			CleanupStack::Pop();         // view1
			iTabGroup->AddTabL(KgoSIPMediaShareSearchViewId.iUid,_L("Search Files") );   // create tab(id,desc)

			// which tab to activate
			ActivateLocalViewL(KgoSIPMediaShareSearchViewId);
			iTabGroup->SetActiveTabById(KgoSIPMediaShareSearchViewId.iUid);
			break;
		}
        case EgoSIPCmdAppSearchFilesClose:
		{
			// Delete tab and view
			iTabGroup->DeleteTabL(KgoSIPMediaShareSearchViewId.iUid);

			CAknView* temp = NULL;
			temp = View(KgoSIPMediaShareSearchViewId);
			DeactivateActiveViewL();
			DeregisterView(*temp);
			//delete temp;

			// Activate the Group view and tab
			ActivateLocalViewL(KGroupViewId);
			iTabGroup->SetActiveTabById(KGroupViewId.iUid);
			break;
		}
	case EgoSIPCmdAppShareFiles:
		{
			CgoSIPMediaShareShareView* shareView = new (ELeave) CgoSIPMediaShareShareView;
			CleanupStack::PushL( shareView );
			shareView->ConstructL();
			AddViewL( shareView );      // transfer ownership to CAknViewAppUi
			CleanupStack::Pop();        // view2
			iTabGroup->AddTabL(KgoSIPMediaShareShareViewId.iUid,_L("Share Files") );   // create tab(id,desc)

			// which tab to activate
			ActivateLocalViewL(KgoSIPMediaShareShareViewId);
			iTabGroup->SetActiveTabById(KgoSIPMediaShareShareViewId.iUid);
			break;
		}
    case EgoSIPCmdAppShareFilesClose:
		{
			// Delete tab and view
			iTabGroup->DeleteTabL(KgoSIPMediaShareShareViewId.iUid);

			CAknView* temp = NULL;
			temp = View(KgoSIPMediaShareShareViewId);
			DeactivateActiveViewL();
			DeregisterView(*temp);
			//delete temp;

			// Activate the Group view and tab
			ActivateLocalViewL(KGroupViewId);
			iTabGroup->SetActiveTabById(KGroupViewId.iUid);
			break;
		}
		// MYADD appointment cmd
	case EgoSIPCmdAppSetAppointment:
		{
			// if tab of address set appointment is not found, create it
			if( iTabGroup->TabIndexFromId(KAppointViewId.iUid) == -1){
				CgoSIPAppointView* appview = new (ELeave) CgoSIPAppointView;  // create view
				CleanupStack::PushL( appview );
				appview->ConstructL(/*this*/);
				AddViewL( appview );      
				CleanupStack::Pop();    // view2
				iTabGroup->AddTabL(KAppointViewId.iUid,_L("Set Appointment") );   // create tab(id,desc)
			}
			// switch to the view, activate the tab
			ActivateLocalViewL(KAppointViewId);
			iTabGroup->SetActiveTabById(KAppointViewId.iUid);
			break;
		}

    case EgoSIPCmdAppSetAppointmentClose:
		{
			// Delete tab and view
			iTabGroup->DeleteTabL(KAppointViewId.iUid);

			CAknView* temp = NULL;
			temp = View(KAppointViewId);
			DeactivateActiveViewL();
			DeregisterView(*temp);
			//delete temp;

			// Activate the Group view and tab
			ActivateLocalViewL(KGroupViewId);
			iTabGroup->SetActiveTabById(KGroupViewId.iUid);
			break;
		}
        // MY ADD phonebook cmd
    case EgoSIPCmdAppSearchPhonebooks:
        {
            if( iTabGroup->TabIndexFromId(KPhonebookViewId.iUid) == -1){
				CgoSIPPhonebookView* view = new (ELeave) CgoSIPPhonebookView;  // create view
				CleanupStack::PushL( view );
				view->ConstructL(/*this*/);
				AddViewL( view );      
				CleanupStack::Pop();    // view2
				iTabGroup->AddTabL(KPhonebookViewId.iUid,_L("Search Phonebook") );   // create tab(id,desc)
			}
			// switch to the view, activate the tab
			ActivateLocalViewL(KPhonebookViewId);
			iTabGroup->SetActiveTabById(KPhonebookViewId.iUid);
            break;
        }
    case EgoSIPCmdAppSearchPhonebooksClose:
		{
			// Delete tab and view
			iTabGroup->DeleteTabL(KPhonebookViewId.iUid);

			CAknView* temp = NULL;
			temp = View(KPhonebookViewId);
			DeactivateActiveViewL();
			DeregisterView(*temp);
			//delete temp;

			// Activate the Group view and tab
			ActivateLocalViewL(KGroupViewId);
			iTabGroup->SetActiveTabById(KGroupViewId.iUid);
			break;
		}
    case EgoSIPCmdAppSharePhonebook:
        {
            if( iTabGroup->TabIndexFromId(KPhonebook2ViewId.iUid) == -1){
				CgoSIPPhonebookView2* view = new (ELeave) CgoSIPPhonebookView2;  // create view
				CleanupStack::PushL( view );
				view->ConstructL(/*this*/);
				AddViewL( view );      
				CleanupStack::Pop();    // view2
				iTabGroup->AddTabL(KPhonebook2ViewId.iUid,_L("Share Phonebook") );   // create tab(id,desc)
			}
			// switch to the view, activate the tab
			ActivateLocalViewL(KPhonebook2ViewId);
			iTabGroup->SetActiveTabById(KPhonebook2ViewId.iUid);
            break;
        }

           case EgoSIPCmdAppSharePhonebookClose:
		{
			// Delete tab and view
			iTabGroup->DeleteTabL(KPhonebook2ViewId.iUid);

			CAknView* temp = NULL;
			temp = View(KPhonebook2ViewId);
			DeactivateActiveViewL();
			DeregisterView(*temp);
			//delete temp;

			// Activate the Group view and tab
			ActivateLocalViewL(KGroupViewId);
			iTabGroup->SetActiveTabById(KGroupViewId.iUid);
			break;
		}
	case EgoSIPCmdAppGoOnline:
		{
			online = true;
			break;
		}
	case EgoSIPCmdAppGoOffline:
		{
			online = false;
			break;
		}

	default:
		break;      
	}
}

// ----------------------------------------------------
// CgoSIPAppUi::TabChangedL(TInt aIndex)
// This method gets called when CAknTabGroup active 
// tab has changed.
// ----------------------------------------------------
//
void CgoSIPAppUi::TabChangedL(TInt aIndex)
{
	ActivateLocalViewL(TUid::Uid(iTabGroup->TabIdFromIndex(aIndex)));
}

// ---------------------------------------------------------
// CgoSIPAppUI::GetDocument()
// Pass this argument for each view
// if that view needs to use CgoSIPDocument
// CgoSIPDocument made for CgoSIPGroupView for now
// ---------------------------------------------------------
//
/*CgoSIPDocument* CgoSIPAppUi::GetDocument()
{
return static_cast<CgoSIPDocument*>( Document() );
}*/

CgoSIPGroupView* CgoSIPAppUi::GetGroupView()
    {
        return groupView;
    }

CgoSIPUser* CgoSIPAppUi::GetHighlightedUser()
    {
        return groupView->GetHighlightedUser();
    }

CgoSIPGroupContainer* CgoSIPAppUi::GetGroupContainer()
    {
    return groupView->GetContainer();
    }