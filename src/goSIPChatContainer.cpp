/*
============================================================================
 Name        : CgoSIPChatContainer from goSIPChatContainer.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : CgoSIPChatContainer implementation
============================================================================
*/

// INCLUDE FILES
#include "goSIPChatContainer.h"

#include <eiklabel.h>  // for example label control

//My includes
#include <aknquerydialog.h>
#include <goSIP.rsg>
#include <s32file.h>

// ================= MEMBER FUNCTIONS =======================

// ---------------------------------------------------------
// CgoSIPChatContainer::ConstructL(const TRect& aRect)
// EPOC two phased constructor
// ---------------------------------------------------------
//
void CgoSIPChatContainer::ConstructL(const TRect& aRect)
    {
    CreateWindowL();
/*
    iLabel = new (ELeave) CEikLabel;
    iLabel->SetContainerWindowL( *this );
    iLabel->SetTextL( _L("Example View Chat View") );

    iToDoLabel = new (ELeave) CEikLabel;
    iToDoLabel->SetContainerWindowL( *this );
    iToDoLabel->SetTextL( _L("Add Your controls\n here") );
*/

	iEdwin = new (ELeave) CEikEdwin;
	iEdwin->ConstructL(CEikEdwin::EReadOnly, 13, 256, 7);
	iEdwin->SetContainerWindowL(*this);
	iEdwin->SetExtent(TPoint(0, 0), iEdwin->MinimumSize());
	iEdwin->SetFocus(EFalse);
	
    SetRect(aRect);
    ActivateL();
    }

// Destructor
CgoSIPChatContainer::~CgoSIPChatContainer()
    {
/*
    delete iLabel;
    delete iToDoLabel;
*/
	delete iEdwin;
    }

// ---------------------------------------------------------
// CgoSIPChatContainer::SizeChanged()
// Called by framework when the view size is changed
// ---------------------------------------------------------
//
void CgoSIPChatContainer::SizeChanged()
    {
/*
    // TODO: Add here control resize code etc.
    iLabel->SetExtent( TPoint(10,10), iLabel->MinimumSize() );
    iToDoLabel->SetExtent( TPoint(10,100), iToDoLabel->MinimumSize() );
*/
    }

// ---------------------------------------------------------
// CgoSIPChatContainer::CountComponentControls() const
// ---------------------------------------------------------
//
TInt CgoSIPChatContainer::CountComponentControls() const
    {
    //return 2; // return nbr of controls inside this container
	return 1;
    }

// ---------------------------------------------------------
// CgoSIPChatContainer::ComponentControl(TInt aIndex) const
// ---------------------------------------------------------
//
CCoeControl* CgoSIPChatContainer::ComponentControl(TInt aIndex) const
    {
    switch ( aIndex )
        {
/*
        case 0:
            return iLabel;
        case 1:
            return iToDoLabel;
*/
		case 0:
			return iEdwin;
        default:
            return NULL;
        }
    }

// ---------------------------------------------------------
// CgoSIPChatContainer::Draw(const TRect& aRect) const
// ---------------------------------------------------------
//
void CgoSIPChatContainer::Draw(const TRect& aRect) const
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
// CgoSIPChatContainer::HandleControlEventL(
//     CCoeControl* aControl,TCoeEvent aEventType)
// ---------------------------------------------------------
//
void CgoSIPChatContainer::HandleControlEventL(
    CCoeControl* /*aControl*/,TCoeEvent /*aEventType*/)
    {
    // TODO: Add your control event handler code here
    }

void CgoSIPChatContainer::WriteMessageL()
	{
	// Prepare Write Message Dialog
	TBuf<256> message;
	CAknTextQueryDialog* messageQuery = CAknTextQueryDialog::NewL(message);
	CleanupStack::PushL(messageQuery);
	messageQuery->SetPromptL(_L("Write Message"));
	CleanupStack::Pop(messageQuery);
	if(messageQuery->ExecuteLD(R_GOSIP_GOSIPCHAT_WRITEMESSAGE_DIALOG))
		{
		// Append new message to iEdwin's PlainText object
		CPlainText* buffer = iEdwin->Text();
		if(buffer->DocumentLength())
			{
			buffer->InsertL(buffer->DocumentLength(), CEditableText::ELineBreak);
			}
		buffer->InsertL(buffer->DocumentLength(), _L("Me: "));
		buffer->InsertL(buffer->DocumentLength(), message);
		iEdwin->HandleTextChangedL();
		iEdwin->SetCursorPosL(iEdwin->TextLength(), EFalse);
		}
	}

void CgoSIPChatContainer::LoadFromBufferL(const TDesC& aBuffer)
{
	iEdwin->SetTextL(&aBuffer);
}

HBufC* CgoSIPChatContainer::SaveToHBufL() const
{
	return iEdwin->GetTextInHBufL();
}

void CgoSIPChatContainer::SaveToFileL(const TDesC& aFilename) const
{
	TBuf<1024> absPath = KSaveDir;
	absPath.Append('\\');
	absPath.Insert(absPath.Length(), aFilename);

	RFs fs;
	User::LeaveIfError(fs.Connect());

	RFileWriteStream ws;
	ws.PushL();
	User::LeaveIfError(ws.Replace(fs, absPath, EFileWrite));

	iEdwin->Text()->ExternalizeL(ws);
	ws.CommitL();
	CleanupStack::PopAndDestroy();
	fs.Close();
}

TKeyResponse CgoSIPChatContainer::OfferKeyEventL(const TKeyEvent& aKeyEvent, TEventCode aType)
	{
	switch(aKeyEvent.iCode)
		{
		case 0x30:
		case 0x31:
		case 0x32:
		case 0x33:
		case 0x34:
		case 0x35:
		case 0x36:
		case 0x37:
		case 0x38:
		case 0x39:
			{
			WriteMessageL();
			return EKeyWasConsumed;
			break;
			}
		case EKeyLeftArrow:
		case EKeyRightArrow:
			{
			break;
			}
		case EKeyUpArrow:
			{
			//iEditor->MoveCursorL(TCursorPosition::EFPageUp, EFalse);
			iEdwin->MoveCursorL(TCursorPosition::EFPageUp, EFalse);
			return EKeyWasConsumed;
			}
		case EKeyDownArrow:
			{
			//iEditor->MoveCursorL(TCursorPosition::EFPageDown, EFalse);
			iEdwin->MoveCursorL(TCursorPosition::EFPageDown, EFalse);
			return EKeyWasConsumed;
			}
		default:
			break;
		}
	return EKeyWasNotConsumed;
	}
// End of File  
