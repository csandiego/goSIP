/*
============================================================================
Name        : CgoSIPAddUserView from goSIPAddUserView.h
Author      : 
Version     :
Copyright   : Your copyright notice
Description : CgoSIPAddUserView implementation
============================================================================
*/

// INCLUDE FILES
#include  <aknviewappui.h>
#include  <avkon.hrh>
#include  <goSIP.rsg>
#include  "goSIPAddUserView.h"
#include  "goSIPAddUserContainer.h" 

#include "goSIPAppUI.h"

//additional view AddUser 
#include "goSIP.hrh"
#include <eikmenup.h>
#include <barsread.h> 
//setting list
#include <avkon.rsg>
#include <akntitle.h>
#include "goSIPAddUserListBox.h"
#include "goSIPAddUserItemData.h"

//dynamic setting list
#include "goSIPDocument.h"

//for AddUserment saving
#include <apparc.h>
#include <txtrich.h>
#include <e32cons.h>

#include <agmmiter.h>
#include <agmcallb.h>


// ================= MEMBER FUNCTIONS =======================
CgoSIPAddUserView::CgoSIPAddUserView()
: iContainer( NULL )
    {
    }
// ---------------------------------------------------------
// CgoSIPAddUserView::ConstructL(const TRect& aRect)
// EPOC two-phased constructor
// ---------------------------------------------------------
//
void CgoSIPAddUserView::ConstructL(/*CgoSIPAppUi* appUi*/)
    {
    BaseConstructL( R_GOSIP_VIEWADDUSER );

    //	igoSIPAppUi = appUi;

    }

// ---------------------------------------------------------
// CgoSIPAddUserView::~CgoSIPAddUserView()
// destructor
// ---------------------------------------------------------
//
CgoSIPAddUserView::~CgoSIPAddUserView()
    {

    // TODO debug destructor
    if ( iContainer )
        {
        AppUi()->RemoveFromViewStack( *this, iContainer );
        }
    delete iContainer;
    if ( iListBox )
        {
        AppUi()->RemoveFromStack( iListBox );
        }

    delete iListBox;
    delete iData;
    }
// ---------------------------------------------------------
// TUid CgoSIPAddUserView::Id()
//
// ---------------------------------------------------------
//
TUid CgoSIPAddUserView::Id() const
    {
    return KAddUserViewId;
    }

// ---------------------------------------------------------
// CgoSIPAddUserView::HandleCommandL(TInt aCommand)
// takes care of view command handling
// ---------------------------------------------------------
//
void CgoSIPAddUserView::HandleCommandL(TInt aCommand)
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
            AppUi()->HandleCommandL(EgoSIPCmdAddUserClose);
            //break;
            }
        case EKeyLeftArrow:
             {
             			iEikonEnv->InfoMsg(_L("list left"));
            //key.iCode = aCommand;
            AppUi()->HandleCommandL( aCommand );
            break;
            }
        case EKeyRightArrow:
            {
            iEikonEnv->InfoMsg(_L("list right"));
            //key.iCode = aCommand;
            AppUi()->HandleCommandL( aCommand );
            break;
            }
        default:
            {
            AppUi()->HandleCommandL( aCommand );
            break;
            }
        }
    }

void CgoSIPAddUserView::IndicateTitlePaneTextL( TInt aCommand )
    {
    /*    TBool useDefaultText( EFalse );
    TInt resourceId( 124 );
    switch ( aCommand )
    {
    case EAknExFormCmdEmptyOutline:
    useDefaultText = ETrue;
    break;
    case EAknExFormCmdOutline02:
    resourceId = R_AKNEXFORM_TEXT_STATUS_PANE_TITLE02;
    break;
    default:
    useDefaultText = ETrue;
    break;
    }
    CAknTitlePane* titlePane = static_cast<CAknTitlePane*>
    ( StatusPane()->ControlL( TUid::Uid( EEikStatusPaneUidTitle ) ) );
    if ( useDefaultText )
    {
    titlePane->SetTextToDefaultL();
    }
    else
    {
    TBuf<124> titleText( NULL );
    iEikonEnv->ReadResource( titleText, resourceId );
    titlePane->SetTextL( titleText );
    }
    */
    }
// ---------------------------------------------------------
// CgoSIPAddUserView::HandleClientRectChange()
// ---------------------------------------------------------
//
void CgoSIPAddUserView::HandleClientRectChange()
    {
    iEikonEnv->InfoMsg(_L("view set AddUser"));
    if ( iContainer )
        {
        iContainer->SetRect( ClientRect() );
        }
    }

// ---------------------------------------------------------
// CgoSIPAddUserView::DoActivateL(...)
// 
// ---------------------------------------------------------
//
void CgoSIPAddUserView::DoActivateL(
                                    const TVwsViewId& /*aPrevViewId*/,TUid /*aCustomMessageId*/,
                                    const TDesC8& /*aCustomMessage*/)
    {
    iEikonEnv->InfoMsg(_L("activate L"));
    if (!iContainer)
        {
        iContainer = new (ELeave) CgoSIPAddUserContainer(this);
        iContainer->SetMopParent(this);
        iContainer->ConstructL( ClientRect() );
        AppUi()->AddToStackL( *this, iContainer );

        //iContainer->MakeVisible( EFalse );
        //AppUi()->RemoveFromStack( iContainer );
        CreateListBoxL( R_GOSIP_ADDUSER_SETTINGS_LIST );

        // Requires to display the default screen.
        //iContainer->DisplayLabelL( R_GOSIPADDUSER_TEXT_LABEL_TITLE );
        //iContainer->MakeVisible( ETrue );        
        }
    }
//for setting list
//create this already from the start no need to call it more than once.
// ------------------------------------------------------------------------------
// CgoSIPAddUserView::CreateListBoxL
// Creates listBox controll
// ------------------------------------------------------------------------------
//
void CgoSIPAddUserView::CreateListBoxL( TInt aResourceId )
    {
    if ( iListBox )
        {
        AppUi()->RemoveFromStack( iListBox );
        }
    delete iListBox;
    iListBox = NULL;

    delete iData;
    iData = CgoSIPAddUserItemData::NewL();

    iListBox = new ( ELeave ) CgoSIPAddUserListBox;
    iListBox->SetData( iData );
    iListBox->SetView( this );
    iListBox->SetMopParent( this );
    iListBox->ConstructFromResourceL( aResourceId );

    AppUi()->AddToStackL( *this, iListBox );
    iListBox->MakeVisible( ETrue );
    iListBox->SetRect( ClientRect() );
    iListBox->ActivateL();
    iListBox->DrawNow();
    //IndicateTitlePaneTextL( iCurrentOutlineId );
    }

void CgoSIPAddUserView::DisplayFormL(TInt aResourceId)
    {
    /*CgoSIPAppointSaveForm* form = CgoSIPAppointSaveForm::NewL();

    if ( aResourceId == R_GOSIP_APPOINT_VIEW1_DIALOG )
    {
    form->PrepareLC( aResourceId );
    TBuf<64> edwinString( NULL );
    iCoeEnv->ReadResource( edwinString, R_GOSIP_APPOINT_EDWIN_TEXT);
    CEikEdwin* myEdwin = static_cast<CEikEdwin*> ( form->ControlOrNull( EAppointCtrlIdView1Subj ) );
    if ( myEdwin )
    {
    myEdwin->SetTextL( &edwinString );
    }

    myEdwin = static_cast<CEikEdwin*> 
    ( form->ControlOrNull( EAppointCtrlIdView1Subj ) ) ;
    if ( myEdwin )
    {
    myEdwin->SetTextL( &edwinString );
    }
    form->RunLD();
    }
    else
    {
    form->ExecuteLD( aResourceId );
    }*/
    }


// ---------------------------------------------------------
// CgoSIPAddUserView::DoDeactivate()
// 
// ---------------------------------------------------------
//
void CgoSIPAddUserView::DoDeactivate()
    {
    if ( iContainer )
        {
        AppUi()->RemoveFromViewStack( *this, iContainer );
        }
    delete iContainer;
    iContainer = NULL;
    }

void CgoSIPAddUserView::changeNaviLabel(TInt aResourceId)
    {
    //changes the navigaion label
    TUid naviPaneUid;
    naviPaneUid.iUid = EEikStatusPaneUidNavi;
    CEikStatusPane* statusPane = StatusPane();
    CEikStatusPaneBase::TPaneCapabilities subPane = statusPane->PaneCapabilities(naviPaneUid);
    if (subPane.IsPresent() && subPane.IsAppOwned())
        {
        CAknNavigationControlContainer* naviPane = (CAknNavigationControlContainer *) statusPane->ControlL(naviPaneUid);
        TResourceReader reader;
        iCoeEnv->CreateResourceReaderLC(reader,aResourceId);
        if (iNaviDecorator)
            {
            delete iNaviDecorator;
            iNaviDecorator = NULL;
            }
        iNaviDecorator = naviPane->CreateNavigationLabelL(reader);
        CleanupStack::PopAndDestroy();
        naviPane->PushL(*iNaviDecorator);
        }
    }


// MY ADD to AddUser

void CgoSIPAddUserView::DynInitMenuPaneL(TInt aResourceId,CEikMenuPane* aMenuPane)
    {
    if( aResourceId == R_GOSIP_VIEWADDUSER_MENU )
        {
        TBool online = ((CgoSIPAppUi *)CEikonEnv::Static()->EikAppUi())->online;
        aMenuPane->SetItemDimmed(EgoSIPCmdAddUserRequest,!online);
        }
    }

