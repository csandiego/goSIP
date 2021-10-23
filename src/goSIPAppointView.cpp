/*
============================================================================
 Name        : CgoSIPAppointView from goSIPAppointView.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : CgoSIPAppointView implementation
============================================================================
*/

// INCLUDE FILES
#include  <aknviewappui.h>
#include  <avkon.hrh>
#include  <goSIP.rsg>
#include  "goSIPAppointView.h"
#include  "goSIPAppointContainer.h" 

//additional view appoint 
#include "goSIP.hrh"
#include <eikmenup.h>
#include <akndialog.h>
#include <barsread.h> 
//setting list
#include <avkon.rsg>
#include <akntitle.h>
#include "goSIPAppointListBox.h"
#include "goSIPAppointItemData.h"
//dynamic setting list
#include "goSIPDocument.h"

//for appointment saving
#include <apparc.h>
#include <txtrich.h>
#include <e32cons.h>

#include <agmmiter.h>
#include <agmcallb.h>


/*//additional for appoint form
#include <akntitle.h>
#include <eikmfne.h>
#include <eikedwin.h>
#include <eikcapc.h>
#include <aknform.h>  // for form control
#include "goSIPAppointSaveForm.h"

*/
// ================= MEMBER FUNCTIONS =======================
CgoSIPAppointView::CgoSIPAppointView()
: iContainer( NULL )
{
}
// ---------------------------------------------------------
// CgoSIPAppointView::ConstructL(const TRect& aRect)
// EPOC two-phased constructor
// ---------------------------------------------------------
//
void CgoSIPAppointView::ConstructL(/*CgoSIPAppUi* appUi*/)
    {
    BaseConstructL( R_GOSIP_APPOINT_VIEW1 );
	//appointmnet variable instantiation
	createSession = false;
	confirmed = false;
	//	igoSIPAppUi = appUi;
	//iCurrentOutline = EAppointFormView1;
	}

// ---------------------------------------------------------
// CgoSIPAppointView::~CgoSIPAppointView()
// destructor
// ---------------------------------------------------------
//
CgoSIPAppointView::~CgoSIPAppointView()
    {
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
// TUid CgoSIPAppointView::Id()
//
// ---------------------------------------------------------
//
TUid CgoSIPAppointView::Id() const
    {
    return KAppointViewId;
    }

// ---------------------------------------------------------
// CgoSIPAppointView::HandleCommandL(TInt aCommand)
// takes care of view command handling
// ---------------------------------------------------------
//
void CgoSIPAppointView::HandleCommandL(TInt aCommand)
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
			QuitAppointDialog();	
            //AppUi()->HandleCommandL(EEikCmdExit);
            //break;
            }
		//view appointment commands
		case EAppointAddDTime:
			{
			iEikonEnv->InfoMsg(_L("add date"));
			
			break;
			}
		case EAppointDelDTime:
			{
			iEikonEnv->InfoMsg(_L("delete date"));

			break;
			}
		case EAppointDisplayUL:
			{
			iEikonEnv->InfoMsg(_L("user list"));
				//just testing
			//iCurrentOutline = aCommand;
            //IndicateTitlePaneTextL( aCommand );
            //iContainer->SetTextToLabelL( R_AKNEXFORM_TEXT_LABEL_OPERATION );
            //iContainer->DisplayFormL( R_GOSIP_APPOINT_VIEW1_DIALOG );
			break;
			}
		case EAppointStartReq:
			{
				createSession = true;
				//set all forms to not editable
				iEikonEnv->InfoMsg(_L("Waiting for confirmation"));
				//change navigation label
				//changeNaviLabel(R_GOSIP_APPOINT_NAVI_LABEL);
				break;
			}
		case EAppointCmdExit:
            {
			QuitAppointDialog();
			//AppUi()->HandleCommandL(EEikCmdExit);
			//iContainer->replaceTabL(KViewId, KAppointViewId);
            break;
            }
		//view appointment form 
		case EAppointFormView1:
			{
			iEikonEnv->InfoMsg(_L("set appointment"));
			break;
			}
		case EKeyLeftArrow:
		case EKeyRightArrow:
			{
				//key.iCode = aCommand;
			    AppUi()->HandleCommandL( aCommand );
			}
        default:
            {
            AppUi()->HandleCommandL( aCommand );
            break;
            }
        }
    }

void CgoSIPAppointView::IndicateTitlePaneTextL( TInt aCommand )
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
// CgoSIPAppointView::HandleClientRectChange()
// ---------------------------------------------------------
//
void CgoSIPAppointView::HandleClientRectChange()
    {
		iEikonEnv->InfoMsg(_L("view set appointment"));
		if ( iContainer )
        {
          iContainer->SetRect( ClientRect() );
        }
    }

// ---------------------------------------------------------
// CgoSIPAppointView::DoActivateL(...)
// 
// ---------------------------------------------------------
//
void CgoSIPAppointView::DoActivateL(
   const TVwsViewId& /*aPrevViewId*/,TUid /*aCustomMessageId*/,
   const TDesC8& /*aCustomMessage*/)
    {
		iEikonEnv->InfoMsg(_L("activate L"));
		if (!iContainer)
        {
        iContainer = new (ELeave) CgoSIPAppointContainer(this);
        iContainer->SetMopParent(this);
        iContainer->ConstructL( ClientRect() );
        AppUi()->AddToStackL( *this, iContainer );
		
		//iContainer->MakeVisible( EFalse );
        //AppUi()->RemoveFromStack( iContainer );
		CreateListBoxL( R_GOSIP_APPOINT_SETTING_LIST_VIEW1 );
        
		// Requires to display the default screen.
        //iContainer->DisplayLabelL( R_goSIPAppoint_TEXT_LABEL_TITLE );
        //iContainer->MakeVisible( ETrue );        
		}
   }
//for setting list
	//create this already from the start no need to call it more than once.
// ------------------------------------------------------------------------------
// CgoSIPAppointView::CreateListBoxL
// Creates listBox controll
// ------------------------------------------------------------------------------
//
void CgoSIPAppointView::CreateListBoxL( TInt aResourceId )
    {
    if ( iListBox )
        {
        AppUi()->RemoveFromStack( iListBox );
        }
    delete iListBox;
    iListBox = NULL;

    delete iData;
    iData = CgoSIPAppointItemData::NewL();

    iListBox = new ( ELeave ) CgoSIPAppointListbox;
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

// ---------------------------------------------------------
// CgoSIPAppointView::DoDeactivate()
// 
// ---------------------------------------------------------
//
void CgoSIPAppointView::DoDeactivate()
    {
    if ( iContainer )
        {
        AppUi()->RemoveFromViewStack( *this, iContainer );
        }
    delete iContainer;
    iContainer = NULL;
    }

void CgoSIPAppointView::DynInitMenuPaneL(TInt aResourceId, CEikMenuPane* aMenuPane)
{
	if (R_GOSIP_APPOINT_VIEW1_MENU == aResourceId) {
		aMenuPane->SetItemDimmed(EAppointAddDTime, DimAppointMenu());
		aMenuPane->SetItemDimmed(EAppointDelDTime, DimAppointMenu());
		aMenuPane->SetItemDimmed(EAppointStartReq, DimAppointMenu());
	}

}
void CgoSIPAppointView::DynInitMenuBarL(TInt aResourceId, CEikMenuPane* aMenuPane)
{
}
//Appoint methods
TBool CgoSIPAppointView::DimAppointMenu()
{
	return createSession;
}
void CgoSIPAppointView::QuitAppointDialog()
{
	CAknQueryDialog* dlg = CAknQueryDialog::NewL();
	if (createSession && confirmed)
		AppUi()->HandleCommandL(EEikCmdExit);
	else if (createSession)
		dlg->SetPromptL(_L("Session will be cancelled. Are you sure you want to exit?"));
	else
		dlg->SetPromptL(_L("Session not created. Are you sure you want to exit?"));
	if(dlg->ExecuteLD(R_GOSIP_APPOINT_EXIT_QUERY))
	{	
		if (createSession)
		{
			//send to everyone appointment is cancelled
		}
		AppUi()->HandleCommandL(EEikCmdExit);
	}
}
void CgoSIPAppointView::changeNaviLabel(TInt aResourceId)
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
void CgoSIPAppointView::PopulateModelL() const
{
	
}
void CgoSIPAppointView::DisplayFormL(TInt aResourceId)
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

void CgoSIPAppointView::SaveIntoCalendar()
{
/*
	RAgendaServ* iAgendaServer;
	iAgendaServer = RAgendaServ::NewL();
	iAgendaServer->Connect();*/
/*	CAgnModel* iModel;
	iModel = CAgnModel::NewL(this);
    iModel->SetServer(iAgendaServer);
	iModel->SetMode(CAgnEntryModel::EClient);*/
}

