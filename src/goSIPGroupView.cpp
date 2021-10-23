/*
============================================================================
 Name        : goSIPGroupView.cpp
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : goSIPGroupView.cpp - source file
============================================================================
*/

// INCLUDE FILES
// Class include
//#include "goSIPGroupView.h"
// System includes
//#include <e32base.h>  // For CBase, link against euser.lib
//#include <ResourceFile.rsg>
// User includes
//#include "MyHeaderFile.h"

// ================= MEMBER FUNCTIONS =======================

// End of File


/*
============================================================================
 Name        : CgoSIPView from goSIPView.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : CgoSIPView implementation
============================================================================
*/

// INCLUDE FILES
#include <eikmenup.h>
#include  <aknviewappui.h>
#include  <avkon.hrh>
#include  <goSIP.rsg>
#include "goSIP.hrh"
#include  "goSIPGroupView.h"
#include  "goSIPGroupContainer.h" 
#include "goSIPAppUi.h"

// ================= MEMBER FUNCTIONS =======================

// ---------------------------------------------------------
// CgoSIPView::ConstructL(const TRect& aRect)
// EPOC two-phased constructor
// ---------------------------------------------------------
//
void CgoSIPGroupView::ConstructL()
    {
    BaseConstructL( R_GOSIP_VIEWGROUP );
    }

// ---------------------------------------------------------
// CgoSIPView::~CgoSIPView()
// destructor
// ---------------------------------------------------------
//
CgoSIPGroupView::~CgoSIPGroupView()
    {
    if ( iContainer )
        {
        AppUi()->RemoveFromViewStack( *this, iContainer );
        }

    delete iContainer;
    }

// ---------------------------------------------------------
// TUid CgoSIPView::Id()
//
// ---------------------------------------------------------
//
TUid CgoSIPGroupView::Id() const
    {
    return KGroupViewId;
    }

// ---------------------------------------------------------
// CgoSIPView::HandleCommandL(TInt aCommand)
// takes care of view command handling
// ---------------------------------------------------------
//
void CgoSIPGroupView::HandleCommandL(TInt aCommand)
    {   
    switch ( aCommand )
        {
        case EAknSoftkeyOk:
            {
            break;
            }
        case EAknSoftkeyBack:
            {
            //iContainer->CloseList();
            AppUi()->HandleCommandL(EEikCmdExit);
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
// CgoSIPView::HandleClientRectChange()
// ---------------------------------------------------------
//
void CgoSIPGroupView::HandleClientRectChange()
    {
    if ( iContainer )
        {
        iContainer->SetRect( ClientRect() );
        }
    }

// ---------------------------------------------------------
// CgoSIPView::DoActivateL(...)
// 
// ---------------------------------------------------------
//
void CgoSIPGroupView::DoActivateL(
   const TVwsViewId& /*aPrevViewId*/,TUid /*aCustomMessageId*/,
   const TDesC8& /*aCustomMessage*/)
    {
    if (!iContainer)
        {
        iContainer = new (ELeave) CgoSIPGroupContainer;
        iContainer->SetMopParent(this);
        iContainer->ConstructL( ClientRect() );
        AppUi()->AddToStackL( *this, iContainer );
        //iContainer->SizeChanged();
        //iEikonEnv->InfoMsg((*(iContainer->iListBoxArray))[0]);
        }
   }

// ---------------------------------------------------------
// CgoSIPView::DoDeactivate()
// 
// ---------------------------------------------------------
//
void CgoSIPGroupView::DoDeactivate()
    {
    if ( iContainer )
        {
        AppUi()->RemoveFromViewStack( *this, iContainer );
        }

    //delete iContainer;
    //iContainer = NULL;
    }

//my add xxxxxx

CgoSIPGroupContainer* CgoSIPGroupView::GetContainer()
    {
    return iContainer;
    }

	// my add 050923

	/**
	 * Available only when online: Chat, Set Appointment, Search phonebooks,
	 * search files, add user to group list, go online 
	 */


void CgoSIPGroupView::DynInitMenuPaneL(TInt aResourceId,CEikMenuPane* aMenuPane)
    {
        if( aResourceId == R_GOSIP_VIEWGROUP_MENU )
		{
            TBool online = ((CgoSIPAppUi *)CEikonEnv::Static()->EikAppUi())->online;
    		aMenuPane->SetItemDimmed(EgoSIPCmdAppChat,!online);
			aMenuPane->SetItemDimmed(EgoSIPCmdAppSetAppointment,!online);
			aMenuPane->SetItemDimmed(EgoSIPCmdAppSearchPhonebooks,!online);
			aMenuPane->SetItemDimmed(EgoSIPCmdAppSearchFiles,!online);
			aMenuPane->SetItemDimmed(EgoSIPCmdAppAddUser,!online);
            aMenuPane->SetItemDimmed(EgoSIPCmdAppGoOnline,online);
			aMenuPane->SetItemDimmed(EgoSIPCmdAppGoOffline,!online);
		}
    }


// another add 
CgoSIPUser* CgoSIPGroupView::GetHighlightedUser() const
    {
       //chatuserlistview->GetContainer()->AddUserToListBox(groupView->GetContainer()->iListBoxArray[groupView->GetContainer()->iListBox->CurrentItemIndex()]);
            //chatuserlistview->GetContainer()->AddUserToListBox(groupView->GetContainer()->iListBoxArray->MdcaPoint(groupView->GetContainer()->iListBox->CurrentItemIndex()));
            //iEikonEnv->InfoMsg( groupView->GetContainer()->iListBoxArray->MdcaPoint(groupView->GetContainer()->iListBox->CurrentItemIndex()) );

/*
            if(groupView->GetContainer() != 0)
                iEikonEnv->InfoMsg( groupView->GetContainer()->iListBox->CurrentItemIndex() );
            else
                iEikonEnv->InfoMsg(_L("null groupview->container") );
*/

    /*_LIT(kName, "Dad");
    _LIT(kSIPAddress,"Dad@realm");
    TBuf<256> name;
    name.Copy(kName);
    TBuf<256> sipAddress;
    sipAddress.Copy(kSIPAddress);*/

    return (CgoSIPUser*)iContainer->userArray[iContainer->iListBox->CurrentItemIndex()];

    }
