/*
============================================================================
 Name        : CgoSIPMediaShareShareContainer from goSIPMediaShareShareContainer.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : CgoSIPMediaShareShareContainer implementation
============================================================================
*/

// INCLUDE FILES
#include "goSIPMediaShareShareContainer.h"

#include "goSIP.hrh"
#include "goSIPDocument.h"
#include <goSIP.rsg>
#include <MGFetch.h>

//#include <eiklabel.h>  // for example label control

TBool moved = EFalse;


// ================= MEMBER FUNCTIONS =======================

// ---------------------------------------------------------
// CgoSIPMediaShareShareContainer::ConstructL(const TRect& aRect)
// EPOC two phased constructor
// ---------------------------------------------------------
//
void CgoSIPMediaShareShareContainer::ConstructL(const TRect& aRect)
    {
    CreateWindowL();

    /*iLabel = new (ELeave) CEikLabel;
    iLabel->SetContainerWindowL( *this );
    iLabel->SetTextL( _L("Share Files") );

    iToDoLabel = new (ELeave) CEikLabel;
    iToDoLabel->SetContainerWindowL( *this );
    iToDoLabel->SetTextL( _L("Add Your controls\n here") );
	*/

	iListBox = new (ELeave) CAknDoubleStyleListBox;

	iListBox->SetContainerWindowL( *this );
	iListBox->ConstructL( this, EAknListBoxSelectionList);

	// Create the scroll indicator
	iListBox->CreateScrollBarFrameL(ETrue);
	iListBox->ScrollBarFrame()->SetScrollBarVisibilityL( CEikScrollBarFrame::EOn, CEikScrollBarFrame::EOn);

    iListBox->Model()->SetOwnershipType( ELbmOwnsItemArray );
    iListBox->ActivateL();
	//iListBox-> SetListBoxObserver(this);

	iAppEngine = new (ELeave) CgoSIPMediaShareAppEngine;

	//SetFileList(EFileListDirNoChange, EFileListDate);

    SetRect(aRect);
    ActivateL();
    }

// Destructor
CgoSIPMediaShareShareContainer::~CgoSIPMediaShareShareContainer()
{
    //delete iLabel;
    //delete iToDoLabel;
	delete iAppEngine;
	iAppEngine = NULL;
	delete iListBox;
	iListBox = NULL;
}


	void CgoSIPMediaShareShareContainer::SetFileList(TInt aDirectory, TInt aSizeDate)
	{
		CDesCArray* items = static_cast<CDesCArray*>(iListBox->Model()->ItemTextArray());
		//CleanupStack::PushL(items);

		if (iAppEngine->RemoveItems(items)) 
        {
			// This makes changes to the actual listbox
			iListBox->HandleItemRemovalL();  
        }

		iAppEngine->SetDirectory(aDirectory);
		iAppEngine->SetSizeDate(aSizeDate);
		
		if(iAppEngine->StartFileList() == KErrNone)
        {        
        // Create FileList Items in the ListBox
			iAppEngine->GetFileListItems(items);
        }

		//iAppEngine->EndFileList();
		//iEikonEnv->InfoMsg(_L("End File List."));

		iListBox->HandleItemAdditionL();
		iListBox->SetCurrentItemIndex(0);
		iListBox->DrawNow();
		TInt openedItem = 0;

		//CAknSelectionListDialog* dialog = CAknSelectionListDialog::NewL(openedItem, items, R_SELECTIONLIST_MENUBAR);
		//TBuf<10> textData(NULL);
		
		/*CAknListQueryDialog* dialog = new(ELeave) CAknListQueryDialog(&openedItem);
		//CAknFileSelectionDialog* dialog = CAknFileSelectionDialog::NewL(ECFDDialogTypeSelect); 
		dialog->PrepareLC(R_SELECTION_LIST_DIALOG);
		dialog->SetItemTextArray(items);
		dialog->SetOwnershipType(ELbmDoesNotOwnItemArray);
		//dialog->ActivateL();*/
		iEikonEnv->InfoMsg(_L("Dialog prepared."));
		iEikonEnv->InfoMsg(_L("Items added."));

		//CleanupStack::PushL(dialog);
		//dialog->SetupFind(CAknSelectionListDialog::EPopupFind);
		//TBuf<10> aFileName(NULL);
		//_LIT(aFileName,"c:\\");
		//_LIT(KDirPictures,"c:\\"); 
		//MAknFileSelectionObserver*  aObserver = NULL; 
		//dialog->SetDefaultFolderL(_L("c:\\Nokia\\"));


		//if(dialog->RunLD())
		//if(dialog->RunDlgLD(aFileName, KDirPictures, aObserver))
		{
			iEikonEnv->InfoMsg(_L("Dialog ran."));
			//dialog->OkToExitL(openedItem);
			//this->SizeChanged();
		}
		//else
		{
		}
		//CleanupStack::Pop();
	}


	/*void CgoSIPMediaShareShareContainer::SetFileList(TInt aDirectory, TInt aSizeDate)
	{
		RFs &fs = CCoeEnv::Static()->FsSession();
		CDir *anEntryList = NULL;
		_LIT(KPath, "c:\\nokia\\Images\\");
		User::LeaveIfError(fs.GetDir(KPath, KEntryAttNormal, ESortByName, anEntryList));
						

		TInt count = anEntryList->Count();
		for(TInt i = 0;i<count;i++)
		{
			const TEntry &anEntry = (*anEntryList)[i];
			TBuf<100> name = anEntry.iName;
			TUint iAttributes = anEntry.iAtt;
			TInt iSize = anEntry.iSize;
			iEikonEnv->InfoMsg(name);
		}
		delete anEntryList;
		anEntryList = NULL;
	}*/


// ---------------------------------------------------------
// CgoSIPMediaShareShareContainer::SizeChanged()
// Called by framework when the view size is changed
// ---------------------------------------------------------
//
void CgoSIPMediaShareShareContainer::SizeChanged()
{
    // TODO: Add here control resize code etc.
    /*iLabel->SetExtent( TPoint(10,10), iLabel->MinimumSize() );
    iToDoLabel->SetExtent( TPoint(10,100), iToDoLabel->MinimumSize() );*/
	iListBox->SetExtent(TPoint(0,0),iListBox->MinimumSize());//TSize(176,160));
}


// ---------------------------------------------------------
// CgoSIPMediaShareShareContainer::CountComponentControls() const
// ---------------------------------------------------------
//
TInt CgoSIPMediaShareShareContainer::CountComponentControls() const
{
    return 1; // return nbr of controls inside this container
}

// ---------------------------------------------------------
// CgoSIPMediaShareShareContainer::ComponentControl(TInt aIndex) const
// ---------------------------------------------------------
//
CCoeControl* CgoSIPMediaShareShareContainer::ComponentControl(TInt aIndex) const
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
// CgoSIPMediaShareShareContainer::Draw(const TRect& aRect) const
// ---------------------------------------------------------
//
void CgoSIPMediaShareShareContainer::Draw(const TRect& aRect) const
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
// CgoSIPMediaShareShareContainer::HandleControlEventL(
//     CCoeControl* aControl,TCoeEvent aEventType)
// ---------------------------------------------------------
//
void CgoSIPMediaShareShareContainer::HandleControlEventL(
    CCoeControl* /*aControl*/,TCoeEvent /*aEventType*/)
{
    // TODO: Add your control event handler code here
}

TKeyResponse CgoSIPMediaShareShareContainer::OfferKeyEventL(const TKeyEvent& aKeyEvent,TEventCode aType)
{
    // See if we have a selection
    TInt code = aKeyEvent.iCode;
	if ( aKeyEvent.iCode == EKeyDownArrow)
    {
		moved = ETrue;
		CDesCArray* items = static_cast<CDesCArray*>(iListBox->Model()->ItemTextArray());
		TInt max = items->Count();
		if(iListBox->CurrentItemIndex() == max-1)
		{
			moved = EFalse;
		}
		return iListBox->OfferKeyEventL(aKeyEvent, aType);
        //return iTabGroup->OfferKeyEventL( aKeyEvent, aType );
    }
	else if(aKeyEvent.iCode == EKeyUpArrow)
	{
		moved = ETrue;
		if(iListBox->CurrentItemIndex() == 1)
		{
			moved = EFalse;
		}
		return iListBox->OfferKeyEventL(aKeyEvent, aType);
	}
    else
	{
        return EKeyWasNotConsumed;
    }
    /*switch(code)
    {
		// is navigator button pressed
    	case EKeyOK:
            //iAppEngine->LaunchCurrent(iListBox->CurrentItemIndex());
            return (EKeyWasConsumed);
            break;
		case 
        default:
            // Let Listbox take care of its key handling
            return (EKeyWasConsumed);//iListBox->OfferKeyEventL(aKeyEvent, aType);
            break;
    }*/
}


void CgoSIPMediaShareShareContainer::UpdateList(CgoSIPMediaShareAppEngine* aEngine)//(const TDesC aName, TInt aDirectory)
{
	CDesCArray* items = static_cast<CDesCArray*>(iListBox->Model()->ItemTextArray());
	//CleanupStack::PushL(items);
	
	/*if(iAppEngine->StartFileAdd(aName))
	{
		//iEikonEnv->InfoMsg(aName);
	}
	else
	{
		iEikonEnv->InfoMsg(_L("Error Start!"));
	}*/
	//iAppEngine->AddItem(items);
	aEngine->AddItem(items);

	iListBox->HandleItemAdditionL();
	iListBox->SetCurrentItemIndex(0);
	iListBox->DrawNow();

	//aEngine->EndFileList();
	//CleanupStack::PopAndDestroy(items);
}

void CgoSIPMediaShareShareContainer::Save()
{
	CDesCArray* items = static_cast<CDesCArray*>(iListBox->Model()->ItemTextArray());
	iAppEngine->SaveItemsL(items);
	//iEikonEnv->InfoMsg(_L("saves"));
	/*TRAPD(error, iAppEngine->SaveItemsL(items))
	if(error)
	{
		iEikonEnv->InfoMsg(_L("error save"));
	
	}*/
}

void CgoSIPMediaShareShareContainer::Load()
{
	CDesCArray* items = static_cast<CDesCArray*>(iListBox->Model()->ItemTextArray());
	iAppEngine->LoadItemsL(items);
	iListBox->HandleItemAdditionL();
	iListBox->SetCurrentItemIndex(0);
	iListBox->DrawNow();
}

void CgoSIPMediaShareShareContainer::Unshare()
{
	CDesCArray* items = static_cast<CDesCArray*>(iListBox->Model()->ItemTextArray());
	//iListBox->SetCurrentItemIndex(1);
	//iListBox->SetCurrentItemIndex(0);
	iEikonEnv->InfoMsg(_L("Get current item"));
	TInt currentItem;
	//TRAPD(error, iListBox->CurrentItemIndex());
	//if(error == KErrNone )
	if(moved)
	{
		currentItem = iListBox->CurrentItemIndex();
		//iAppEngine->RemoveItem(items, currentItem );
		//iAppEngine->UnshareItemsL(items, currentItem);
		iEikonEnv->InfoMsg(iListBox->CurrentItemIndex());
		items->Delete(currentItem,1);
	}
	else
	{
		iEikonEnv->InfoMsg(_L("Remove first item"));
		currentItem = 0;
		items->Delete(0);
	}
	iAppEngine->SaveItemsL(items);

	//iListBox->HandleItemRemovalL();
	AknListBoxUtils::HandleItemRemovalAndPositionHighlightL(iListBox, currentItem, ETrue);
	//iListBox->SetCurrentItemIndex(0);
	iListBox->DrawNow();

}
