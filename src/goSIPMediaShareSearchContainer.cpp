/*
============================================================================
 Name        : CgoSIPMediaShareSearchContainer from goSIPMediaShareSearchContainer.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : CgoSIPMediaShareSearchContainer implementation
============================================================================
*/

// INCLUDE FILES
#include "goSIPMediaShareSearchContainer.h"
#include <goSIP.rsg>
#include <eiklabel.h>  // for example label control
static TBuf<256> filename;


// ================= MEMBER FUNCTIONS =======================

// ---------------------------------------------------------
// CgoSIPMediaShareSearchContainer::ConstructL(const TRect& aRect)
// EPOC two phased constructor
// ---------------------------------------------------------
//
void CgoSIPMediaShareSearchContainer::ConstructL(const TRect& aRect)
    {
    CreateWindowL();

    iListBox = new (ELeave) CAknDoubleStyleListBox;

	iListBox->SetContainerWindowL( *this );
	iListBox->ConstructL( this, EAknListBoxSelectionList);

	// Create the scroll indicator
	iListBox->CreateScrollBarFrameL(ETrue);
	iListBox->ScrollBarFrame()->SetScrollBarVisibilityL( CEikScrollBarFrame::EOn, CEikScrollBarFrame::EOn);

    iListBox->Model()->SetOwnershipType( ELbmOwnsItemArray );
    iListBox->ActivateL();

	iAppEngine  = new (ELeave) CgoSIPMediaShareAppEngine;
	
	SetRect(aRect);
    ActivateL();
    }

// Destructor
CgoSIPMediaShareSearchContainer::~CgoSIPMediaShareSearchContainer()
    {
		delete iListBox;
		delete iAppEngine;
    }

// ---------------------------------------------------------
// CgoSIPMediaShareSearchContainer::SizeChanged()
// Called by framework when the view size is changed
// ---------------------------------------------------------
//
void CgoSIPMediaShareSearchContainer::SizeChanged()
{
    // TODO: Add here control resize code etc.
    //iLabel->SetExtent( TPoint(10,10), iLabel->MinimumSize() );
    //iToDoLabel->SetExtent( TPoint(10,100), iToDoLabel->MinimumSize() );
	iListBox->SetExtent(TPoint(0,0),iListBox->MinimumSize());
}

// ---------------------------------------------------------
// CgoSIPMediaShareSearchContainer::CountComponentControls() const
// ---------------------------------------------------------
//
TInt CgoSIPMediaShareSearchContainer::CountComponentControls() const
{
    return 1; // return nbr of controls inside this container
}

// ---------------------------------------------------------
// CgoSIPMediaShareSearchContainer::ComponentControl(TInt aIndex) const
// ---------------------------------------------------------
//
CCoeControl* CgoSIPMediaShareSearchContainer::ComponentControl(TInt aIndex) const
    {
    switch ( aIndex )
        {
        case 0:
            return iListBox;
        default:
            return NULL;
        }
    }

// ---------------------------------------------------------
// CgoSIPMediaShareSearchContainer::Draw(const TRect& aRect) const
// ---------------------------------------------------------
//
void CgoSIPMediaShareSearchContainer::Draw(const TRect& aRect) const
    {
    CWindowGc& gc = SystemGc();
    // TODO: Add your drawing code here
    // example code...
    gc.SetPenStyle( CGraphicsContext::ENullPen );
    gc.SetBrushColor( KRgbGray );
    gc.SetBrushStyle( CGraphicsContext::ESolidBrush );
    gc.DrawRect( aRect );
    }

// ---------------------------------------------------------
// CgoSIPMediaShareSearchContainer::HandleControlEventL(
//     CCoeControl* aControl,TCoeEvent aEventType)
// ---------------------------------------------------------
//
void CgoSIPMediaShareSearchContainer::HandleControlEventL(
    CCoeControl* aControl,TCoeEvent aEventType)
    {
    // TODO: Add your control event handler code 
    }

	TKeyResponse CgoSIPMediaShareSearchContainer::OfferKeyEventL(const TKeyEvent& aKeyEvent,TEventCode aType)
	{
		if ( aKeyEvent.iCode == EKeyDownArrow || aKeyEvent.iCode == EKeyUpArrow)
		{
			return iListBox->OfferKeyEventL(aKeyEvent, aType);
		}
        return EKeyWasNotConsumed;
	}

	void CgoSIPMediaShareSearchContainer::SearchFileL()
	{
		//TBuf<256> filename;
		CAknTextQueryDialog* filenameQuery = CAknTextQueryDialog::NewL(filename);
		//CAknTextQueryDialog::NewL(filename);
		CleanupStack::PushL(filenameQuery);
		
		//HBufC *prompt = (_L("Search file: "));
		filenameQuery->SetPromptL(_L("Search file: "));
		//filenameQuery->SetPromptL(*prompt);
		//CleanupStack::PopAndDestroy(prompt);
		CleanupStack::Pop(filenameQuery);

		if(filenameQuery->ExecuteLD(R_AKNEXQUERY_DATA_QUERY))
		{
			LoadL();
		}
		
		DrawNow();
	
	}

	void CgoSIPMediaShareSearchContainer::LoadL()
	{
		CAknDoubleStyleListBox* temp = new (ELeave) CAknDoubleStyleListBox;
		temp->ConstructL( this, EAknListBoxSelectionList);
		//CDesCArray* items = static_cast<CDesCArray*>(temp->Model()->ItemTextArray());
		CDesCArray* searchResult = static_cast<CDesCArray*>(iListBox->Model()->ItemTextArray());
		//items = NULL;
		//searchResult = NULL;
		iAppEngine->SearchAndLoadItemsL(searchResult,filename);
		iListBox->HandleItemAdditionL();
		iListBox->SetCurrentItemIndex(0);
		iListBox->DrawNow();
		
		delete temp;
	
	}
