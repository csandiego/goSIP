/*
============================================================================
 Name        : CgoSIPMediaShareDownloadContainer from goSIPMediaShareDownloadContainer.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : CgoSIPMediaShareDownloadContainer implementation
============================================================================
*/

// INCLUDE FILES
#include "goSIPMediaShareDownloadContainer.h"

#include <eiklabel.h>  // for example label control


// ================= MEMBER FUNCTIONS =======================

// ---------------------------------------------------------
// CgoSIPMediaShareDownloadContainer::ConstructL(const TRect& aRect)
// EPOC two phased constructor
// ---------------------------------------------------------
//
void CgoSIPMediaShareDownloadContainer::ConstructL(const TRect& aRect)
    {
    CreateWindowL();

    iLabel = new (ELeave) CEikLabel;
    iLabel->SetContainerWindowL( *this );
    iLabel->SetTextL( _L("Download Page") );

	CEikProgressInfo::SInfo info;
    info.iHeight = KProgressBarHeight;
    info.iSplitsInBlock = KProgressBarSplitsInBlock;
	info.iTextType = EEikProgressTextNone;
	info.iWidth = KProgressBarWidth;
    info.iFinalValue = KProgressBarFinalValue;

	iPBar = new( ELeave ) CEikProgressInfo( info );
	iPBar->ConstructL();
	iEikonEnv->InfoMsg(_L("iPBar constructed"));
	iPBar->SetPosition(TPoint(10, 20));
	iPBar->SetContainerWindowL(*this);

    SetRect(aRect);
    ActivateL();
    }

// Destructor
CgoSIPMediaShareDownloadContainer::~CgoSIPMediaShareDownloadContainer()
{
    delete iLabel;
	delete iPBar;
}

// ---------------------------------------------------------
// CgoSIPMediaShareDownloadContainer::SizeChanged()
// Called by framework when the view size is changed
// ---------------------------------------------------------
//
void CgoSIPMediaShareDownloadContainer::SizeChanged()
    {
    // TODO: Add here control resize code etc.
    iLabel->SetExtent( TPoint(10,10), iLabel->MinimumSize() );
    }

// ---------------------------------------------------------
// CgoSIPMediaShareDownloadContainer::CountComponentControls() const
// ---------------------------------------------------------
//
TInt CgoSIPMediaShareDownloadContainer::CountComponentControls() const
    {
    return 2; // return nbr of controls inside this container
    }

// ---------------------------------------------------------
// CgoSIPMediaShareDownloadContainer::ComponentControl(TInt aIndex) const
// ---------------------------------------------------------
//
CCoeControl* CgoSIPMediaShareDownloadContainer::ComponentControl(TInt aIndex) const
    {
    switch ( aIndex )
        {
        case 0:
            return iLabel;
		case 1:
			return iPBar;
        default:
            return NULL;
        }
    }

// ---------------------------------------------------------
// CgoSIPMediaShareDownloadContainer::Draw(const TRect& aRect) const
// ---------------------------------------------------------
//
void CgoSIPMediaShareDownloadContainer::Draw(const TRect& aRect) const
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
// CgoSIPMediaShareDownloadContainer::HandleControlEventL(
//     CCoeControl* aControl,TCoeEvent aEventType)
// ---------------------------------------------------------
//
void CgoSIPMediaShareDownloadContainer::HandleControlEventL(
    CCoeControl* /*aControl*/,TCoeEvent /*aEventType*/)
    {
    // TODO: Add your control event handler code here
    }

	void CgoSIPMediaShareDownloadContainer::IncrementAndDrawBars()
	{
		TInt i = 0;
		while(i<10)
		{
			iPBar->IncrementAndDraw(1);
			i++;
		}
	}

// End of File  
