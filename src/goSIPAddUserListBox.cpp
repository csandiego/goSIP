/*
============================================================================
 Name        : goSIPAddUserListBox.cpp
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : goSIPAddUserListBox.cpp - source file
============================================================================
*/

// INCLUDE FILES
// Class include
//#include "goSIPAddUserListBox.h"
// System includes
//#include <e32base.h>  // For CBase, link against euser.lib
//#include <ResourceFile.rsg>
// User includes
//#include "MyHeaderFile.h"

// ================= MEMBER FUNCTIONS =======================

/* Copyright (c) 2004, Nokia. All rights reserved */


// INCLUDE FILES
#include "goSIPAddUserListBox.h"
#include "goSIPAddUserItemData.h"
#include "goSIP.hrh"
#include "goSIPAddUserView.h"



// ========================= MEMBER FUNCTIONS ==================================

// ----------------------------------------------------------------------------
// CgoSIPAddUserListBox::CreateSettingItemL()
// Updates descripter array for list box
// ----------------------------------------------------------------------------
//
CAknSettingItem* CgoSIPAddUserListBox::CreateSettingItemL( TInt aIdentifier  )
    {

    CAknSettingItem* settingItem = NULL;

    switch ( aIdentifier )
    {
        case EgoSIPSettingItemAddUserSIPAddress:
		{
		settingItem = new ( ELeave ) CAknTextSettingItem( aIdentifier, iData->iSIPAddress );
        break;
		}
        case EgoSIPSettingItemAddUserAddToGroup:
		{
		settingItem = new ( ELeave ) CAknTextSettingItem( aIdentifier, iData->iGroupName );
        break;
		}
    default:
        break;
        }
    return settingItem;
    }

// ------------------------------------------------------------------------------
// CgoSIPAddUserListBox::SetData()
// Set ListItem data
// ------------------------------------------------------------------------------
//
void CgoSIPAddUserListBox::SetData( CgoSIPAddUserItemData* aData )
    {
    iData = aData;
    }

// ------------------------------------------------------------------------------
// CgoSIPAddUserListBox::SetView()
// Set ListItem view
// ------------------------------------------------------------------------------
//
void CgoSIPAddUserListBox::SetView( CgoSIPAddUserView* aView )
    {
    iView = aView;
    }

// ------------------------------------------------------------------------------
// TKeyResponse CgoSIPAddUserListBox::OfferKeyEventL()
// Handles the key events.
// ------------------------------------------------------------------------------
//
TKeyResponse CgoSIPAddUserListBox::OfferKeyEventL( const TKeyEvent& aKeyEvent, TEventCode aType  )
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

			iView->HandleCommandL(EKeyRightArrow);
            // Display next outline screen.
            //iView->SetCurrentOutlineId ( iView->CurrentOutlineId() ) ;
            //iView->DisplayNextOutlineL();
            break;
        case EKeyLeftArrow:

			iView->HandleCommandL(EKeyLeftArrow);
			// Display previous outline screen.
            //iView->SetCurrentOutlineId ( iView->CurrentOutlineId() ) ;
            //iView->DisplayPreviousOutlineL();
            break;

            
        default:
            //if OK
//mysub			CAknSettingItemList::OfferKeyEventL( aKeyEvent, aType );
            			iView->HandleCommandL(aKeyEvent.iCode);
            break;
        }
    return EKeyWasConsumed;
    }

// -----------------------------------------------------------------------------
// CgoSIPAddUserListBox::SizeChanged()
// Called by framework when the view size is changed.
// -----------------------------------------------------------------------------
//
void CgoSIPAddUserListBox::SizeChanged()
    {
    if (ListBox() ) 
        {
        ListBox()->SetRect(Rect() );
        }
    }

// End of File
