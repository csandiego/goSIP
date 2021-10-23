/* 
============================================================================
 Name        : CgoSIPAddUserContainer from goSIPAddUserContainer.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Container control implementation
============================================================================
*/

// INCLUDE FILES

//Add User
#include <eiklabel.h> // for label
#include <goSIP.rsg>
#include "goSIP.hrh"
#include "goSIPAddUserView.h"
#include "goSIPAddUserContainer.h"
//AddUser Setting list

// ================= MEMBER FUNCTIONS =======================

CgoSIPAddUserContainer::CgoSIPAddUserContainer( CgoSIPAddUserView* aView )
											: iView( aView ), iLabel( NULL )
    {
    }

	// Destructor
CgoSIPAddUserContainer::~CgoSIPAddUserContainer()
    {
    delete iLabel;
    }

TKeyResponse CgoSIPAddUserContainer::OfferKeyEventL( 
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

	void CgoSIPAddUserContainer::SetTextToLabelL( TInt aResourceId )
    {
    TBuf<124> messageString( NULL );
    iCoeEnv->ReadResource( messageString, aResourceId );
    iLabel->SetTextL( messageString );
    }
void CgoSIPAddUserContainer::DisplayFormL( TInt aResourceId )
    {
    }

void CgoSIPAddUserContainer::CreateLabelL()
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
// CgoSIPAddUserContainer::ConstructL(const TRect& aRect)
// EPOC two phased constructor
// ---------------------------------------------------------
//
void CgoSIPAddUserContainer::ConstructL(const TRect& aRect)
    {
    CreateWindowL();

    iLabel = new (ELeave) CEikLabel;
    iLabel->SetContainerWindowL( *this );
    iLabel->SetTextL( _L("Add User View") );

	SetRect(aRect);
    ActivateL();
	}


// ---------------------------------------------------------
// CgoSIPAddUserContainer::SizeChanged()
// Called by framework when the view size is changed
// ---------------------------------------------------------
// 
void CgoSIPAddUserContainer::SizeChanged()
    {
    // TODO: Add here control resize code etc.
    iLabel->SetExtent( TPoint(10,10), iLabel->MinimumSize() );	
    }

// ---------------------------------------------------------
// CgoSIPAddUserContainer::CountComponentControls() const
// ---------------------------------------------------------
//
TInt CgoSIPAddUserContainer::CountComponentControls() const
    {
		TInt count = 0;
		if ( iLabel )
        {
        count++;
        }
		return count; // return nbr of controls inside this container
    }

// ---------------------------------------------------------
// CgoSIPAddUserContainer::ComponentControl(TInt aIndex) const
// ---------------------------------------------------------
//
CCoeControl* CgoSIPAddUserContainer::ComponentControl(TInt aIndex) const
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
// CgoSIPAddUserContainer::Draw(const TRect& aRect) const
// ---------------------------------------------------------
//
void CgoSIPAddUserContainer::Draw(const TRect& aRect) const
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
// CgoSIPAddUserContainer::HandleControlEventL(
//     CCoeControl* aControl,TCoeEvent aEventType)
// ---------------------------------------------------------
//
void CgoSIPAddUserContainer::HandleControlEventL(
    CCoeControl* aControl,TCoeEvent aEventType)
    {
    // TODO: Add your control event handler code here
    }*/