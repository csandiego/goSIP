/*
============================================================================
 Name        : goSIPViewGroup.cpp
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : goSIPViewGroup.cpp - source file
============================================================================
*/

// INCLUDE FILES
// Class include
//#include "goSIPViewGroup.h"
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
#include  "goSIPViewGroup.h"
#include  "goSIPContainerGroup.h" 
#include "goSIPAppUi.h"

// ================= MEMBER FUNCTIONS =======================

// ---------------------------------------------------------
// CgoSIPView::ConstructL(const TRect& aRect)
// EPOC two-phased constructor
// ---------------------------------------------------------
//
void CgoSIPViewGroup::ConstructL()
    {
    BaseConstructL( R_GOSIP_VIEWGROUP );
    }

// ---------------------------------------------------------
// CgoSIPView::~CgoSIPView()
// destructor
// ---------------------------------------------------------
//
CgoSIPViewGroup::~CgoSIPViewGroup()
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
TUid CgoSIPViewGroup::Id() const
    {
    return KViewGroupId;
    }

// ---------------------------------------------------------
// CgoSIPView::HandleCommandL(TInt aCommand)
// takes care of view command handling
// ---------------------------------------------------------
//
void CgoSIPViewGroup::HandleCommandL(TInt aCommand)
    {   
    switch ( aCommand )
        {
        case EAknSoftkeyOk:
            {
            break;
            }
        case EAknSoftkeyBack:
            {
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
void CgoSIPViewGroup::HandleClientRectChange()
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
void CgoSIPViewGroup::DoActivateL(
   const TVwsViewId& /*aPrevViewId*/,TUid /*aCustomMessageId*/,
   const TDesC8& /*aCustomMessage*/)
    {
    if (!iContainer)
        {
        iContainer = new (ELeave) CgoSIPContainerGroup;
        iContainer->SetMopParent(this);
        iContainer->ConstructL( ClientRect() );
        AppUi()->AddToStackL( *this, iContainer );
        }
   }

// ---------------------------------------------------------
// CgoSIPView::DoDeactivate()
// 
// ---------------------------------------------------------
//
void CgoSIPViewGroup::DoDeactivate()
    {
    if ( iContainer )
        {
        AppUi()->RemoveFromViewStack( *this, iContainer );
        }
    
    delete iContainer;
    iContainer = NULL;
    }

//my add xxxxxx

CgoSIPContainerGroup* CgoSIPViewGroup::GetContainer()
    {
    return iContainer;
    }

	// my add 050923

	/**
	 * Available only when online: Chat, Set Appointment, Search phonebooks,
	 * search files, add user to group list, go online 
	 */
void CgoSIPViewGroup::DynInitMenuPaneL(TInt aResourceId,CEikMenuPane* aMenuPane)
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
