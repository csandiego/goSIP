/* 
============================================================================
 Name        : CgoSIPAppointContainer from goSIPAppointContainer.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Container control implementation
============================================================================
*/

// INCLUDE FILES

//Appoint
#include <eiklabel.h> // for label
#include <goSIP.rsg>
#include "goSIP.hrh"
#include "goSIPAppointView.h"
#include "goSIPAppointContainer.h"
//Appoint Setting list

// ================= MEMBER FUNCTIONS =======================

CgoSIPAppointContainer::CgoSIPAppointContainer( CgoSIPAppointView* aView )
											: iView( aView ), iLabel( NULL )
    {
    }

	// Destructor
CgoSIPAppointContainer::~CgoSIPAppointContainer()
    {
    delete iLabel;
    }

TKeyResponse CgoSIPAppointContainer::OfferKeyEventL( 
    const TKeyEvent& aKeyEvent, TEventCode aType )
    {
    if ( aType != EEventKey ) // Is not key event?
        {
        return EKeyWasNotConsumed;
        }
    switch ( aKeyEvent.iCode ) // The code of key event is...
        {
        case EKeySpace: // Space key.
            {
            // Requires to display next outline screen.
			//iView->DisplayL();
			DrawNow();
            break;
            }
		/*case EKeyLeftArrow:
			{
			iEikonEnv->InfoMsg(_L("left"));
			}
		case EKeyRightArrow:
			{
			iEikonEnv->InfoMsg(_L("right"));
			break;
			}*/
        default:
            return EKeyWasNotConsumed;
        }
    return EKeyWasConsumed;
    }

	void CgoSIPAppointContainer::SetTextToLabelL( TInt aResourceId )
    {
    TBuf<124> messageString( NULL );
    iCoeEnv->ReadResource( messageString, aResourceId );
    iLabel->SetTextL( messageString );
    }
void CgoSIPAppointContainer::DisplayFormL( TInt aResourceId )
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
void CgoSIPAppointContainer::CreateLabelL()
    {
    if ( !iLabel )
        {
        iLabel = new( ELeave ) CEikLabel;
        iLabel->SetContainerWindowL( *this );
        iLabel->SetAlignment( EHCenterVCenter );
#ifdef __AVKON_APAC__
        iLabel->SetFont( ApacPlain16());
#else
        iLabel->SetFont( LatinBold19());
#endif
        }
    //SetTextToLabelL( R_AKNEXFORM_TEXT_LABEL_TITLE );
    }

// ---------------------------------------------------------
// CgoSIPAppointContainer::ConstructL(const TRect& aRect)
// EPOC two phased constructor
// ---------------------------------------------------------
//
void CgoSIPAppointContainer::ConstructL(const TRect& aRect)
    {
    CreateWindowL();

    iLabel = new (ELeave) CEikLabel;
    iLabel->SetContainerWindowL( *this );
    iLabel->SetTextL( _L("Set Appointment View") );

	SetRect(aRect);
    ActivateL();
	}


// ---------------------------------------------------------
// CgoSIPAppointContainer::SizeChanged()
// Called by framework when the view size is changed
// ---------------------------------------------------------
// 
void CgoSIPAppointContainer::SizeChanged()
    {
    // TODO: Add here control resize code etc.
    iLabel->SetExtent( TPoint(10,10), iLabel->MinimumSize() );	
    }

// ---------------------------------------------------------
// CgoSIPAppointContainer::CountComponentControls() const
// ---------------------------------------------------------
//
TInt CgoSIPAppointContainer::CountComponentControls() const
    {
		TInt count = 0;
		if ( iLabel )
        {
        count++;
        }
		return count; // return nbr of controls inside this container
    }

// ---------------------------------------------------------
// CgoSIPAppointContainer::ComponentControl(TInt aIndex) const
// ---------------------------------------------------------
//
CCoeControl* CgoSIPAppointContainer::ComponentControl(TInt aIndex) const
    {
    switch ( aIndex )
        {
        case 0:
            return iLabel;
        default:
            return NULL;
        }
    }

// ---------------------------------------------------------
// CgoSIPAppointContainer::Draw(const TRect& aRect) const
// ---------------------------------------------------------
//
void CgoSIPAppointContainer::Draw(const TRect& aRect) const
    {
    CWindowGc& gc = SystemGc();
    // TODO: Add your drawing code here
    // example code...
    gc.SetPenStyle( CGraphicsContext::ENullPen );
    gc.SetBrushColor( KRgbGray );
    gc.SetBrushStyle( CGraphicsContext::ESolidBrush );
    gc.DrawRect( aRect );
    }
/*
// ---------------------------------------------------------
// CgoSIPAppointContainer::HandleControlEventL(
//     CCoeControl* aControl,TCoeEvent aEventType)
// ---------------------------------------------------------
//
void CgoSIPAppointContainer::HandleControlEventL(
    CCoeControl* aControl,TCoeEvent aEventType)
    {
    // TODO: Add your control event handler code here
    }*/