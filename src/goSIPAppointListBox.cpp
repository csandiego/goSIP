/* Copyright (c) 2004, Nokia. All rights reserved */


// INCLUDE FILES
#include "goSIPAppointListbox.h"
#include "goSIPAppointItemData.h"
#include "goSIP.hrh"
#include "goSIPAppointView.h"



// ========================= MEMBER FUNCTIONS ==================================

// ----------------------------------------------------------------------------
// CgoSIPAppointListbox::CreateSettingItemL()
// Updates descripter array for list box
// ----------------------------------------------------------------------------
//
CAknSettingItem* CgoSIPAppointListbox::CreateSettingItemL( TInt aIdentifier  )
    {

    CAknSettingItem* settingItem = NULL;

    switch ( aIdentifier )
    {
	case EAppointSettingSubj:
		{
		settingItem = new ( ELeave ) CAknTextSettingItem( aIdentifier, iData->iSubject );
        break;
		}
	case EAppointSettingLoc:
		{
		settingItem = new ( ELeave ) CAknTextSettingItem( aIdentifier, iData->iLocation );
        break;
		}
	case EAppointSettingDate:
		{
			settingItem = new ( ELeave ) CAknTimeOrDateSettingItem( aIdentifier,CAknTimeOrDateSettingItem::EDate, iData->iDate );
        break;
		}
	case EAppointSettingTime:
		{
			settingItem = new ( ELeave ) CAknTimeOrDateSettingItem( aIdentifier,CAknTimeOrDateSettingItem::ETime, iData->iTime);
        break;
		}

    /*case EAknExSettingText:
        settingItem = new ( ELeave ) CAknTextSettingItem( aIdentifier, 
                                                          iData->iTextBuf );
        break;

	case EAknExSettingVolume:
        settingItem = new ( ELeave ) CAknVolumeSettingItem( aIdentifier,
                                                            iData->iVolume );
        break;

    case EAknExSettingEnumText:
        settingItem = new ( ELeave ) CAknEnumeratedTextPopupSettingItem( 
                                             aIdentifier,iData->iLanguageCode );
        break;

    case EAknExSettingSlider:
        settingItem = new ( ELeave ) CAknSliderSettingItem(
                                             aIdentifier, iData->iSliderValue );
        break;

    case EAknExSettingDate:
        settingItem = new ( ELeave ) CAknTimeOrDateSettingItem( 
                  aIdentifier, CAknTimeOrDateSettingItem::EDate, iData->iDate );
        break;

    case EAknExSettingTime:
        settingItem = new ( ELeave ) CAknTimeOrDateSettingItem(
                  aIdentifier, CAknTimeOrDateSettingItem::ETime, iData->iTime );
        break;

    case EAknExSettingBinary:
        settingItem = new ( ELeave ) CAknBinaryPopupSettingItem( 
                                                  aIdentifier, iData->iBinary );
        break;

    case EAknExSettingPassAlph:
        settingItem = new ( ELeave ) CAknPasswordSettingItem( 
                     aIdentifier, CAknPasswordSettingItem::EAlpha, iData->iPw );
        break;

    case EAknExSettingPassNumber:
        settingItem = new ( ELeave ) CAknPasswordSettingItem(
                  aIdentifier, CAknPasswordSettingItem::ENumeric, iData->iPin );
        break;

    case EAknExSettingIpAddress:
        settingItem = new ( ELeave ) CAknIpFieldSettingItem(
                                               aIdentifier, iData->iIpAddress );
        break;
*/
    default:
        break;
        }
    return settingItem;
    }

// ------------------------------------------------------------------------------
// CgoSIPAppointListbox::SetData()
// Set ListItem data
// ------------------------------------------------------------------------------
//
void CgoSIPAppointListbox::SetData( CgoSIPAppointItemData* aData )
    {
    iData = aData;
    }

// ------------------------------------------------------------------------------
// CgoSIPAppointListbox::SetView()
// Set ListItem view
// ------------------------------------------------------------------------------
//
void CgoSIPAppointListbox::SetView( CgoSIPAppointView* aView )
    {
    iView = aView;
    }

// ------------------------------------------------------------------------------
// TKeyResponse CgoSIPAppointListbox::OfferKeyEventL()
// Handles the key events.
// ------------------------------------------------------------------------------
//
TKeyResponse CgoSIPAppointListbox::OfferKeyEventL( const TKeyEvent& aKeyEvent, TEventCode aType  )
    {
     // Is not key event?
    if ( aType != EEventKey )
        {
        return EKeyWasNotConsumed;
        }

    // The code of key event is...
    switch ( aKeyEvent.iCode ) 
        {
        case EKeySpace: // Space key.
        case EKeyRightArrow:
			iEikonEnv->InfoMsg(_L("list right"));
			iView->HandleCommandL(EKeyRightArrow);
            // Display next outline screen.
            //iView->SetCurrentOutlineId ( iView->CurrentOutlineId() ) ;
            //iView->DisplayNextOutlineL();
            break;
        case EKeyLeftArrow:
			iEikonEnv->InfoMsg(_L("list left"));
			iView->HandleCommandL(EKeyLeftArrow);
			// Display previous outline screen.
            //iView->SetCurrentOutlineId ( iView->CurrentOutlineId() ) ;
            //iView->DisplayPreviousOutlineL();
            break;
        default:
            //if OK
			CAknSettingItemList::OfferKeyEventL( aKeyEvent, aType );
            break;
        }
    return EKeyWasConsumed;
    }

// -----------------------------------------------------------------------------
// CgoSIPAppointListbox::SizeChanged()
// Called by framework when the view size is changed.
// -----------------------------------------------------------------------------
//
void CgoSIPAppointListbox::SizeChanged()
    {
    if (ListBox() ) 
        {
        ListBox()->SetRect(Rect() );
        }
    }

// End of File
