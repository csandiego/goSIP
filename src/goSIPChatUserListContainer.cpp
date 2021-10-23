/*
============================================================================
 Name        : CgoSIPChatUserListContainer from goSIPChatUserListContainer.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : CgoSIPChatUserListContainer implementation
============================================================================
*/

// INCLUDE FILES

#include <eiklabel.h>  // for example label control
#include <goSIP.rsg>

#include "goSIPChatUserListContainer.h"
#include "goSIPUser.h"

// ================= MEMBER FUNCTIONS =======================

// ---------------------------------------------------------
// CgoSIPChatUserListContainer::ConstructL(const TRect& aRect)
// EPOC two phased constructor
// ---------------------------------------------------------
//
void CgoSIPChatUserListContainer::ConstructL(const TRect& aRect)
    {
	CreateWindowL();

	/*iList = new (ELeave) CAknSingleStyleListBox;
	iList->SetContainerWindowL(*this);

	TResourceReader reader;               //r_gosip_gosipchatuserlist_sample_user_list
	iCoeEnv->CreateResourceReaderLC(reader, R_GOSIP_GOSIPCHATUSERLIST_SAMPLE_USER_LIST);
	iList->ConstructFromResourceL(reader);
	CleanupStack::PopAndDestroy();

	iList->CreateScrollBarFrameL(ETrue);
	iList->ScrollBarFrame()->SetScrollBarVisibilityL(CEikScrollBarFrame::EOff,
													CEikScrollBarFrame::EAuto);*/

    iListBox = new (ELeave)	CAknSingleStyleListBox();
    iListBox->ConstructL( this,	EAknListBoxMarkableList	);
    iListBox->SetContainerWindowL( *this );

    iListBox->CreateScrollBarFrameL(ETrue);
    iListBox->ScrollBarFrame()->SetScrollBarVisibilityL( CEikScrollBarFrame::EOn, CEikScrollBarFrame::EOn);

    iListBox->Model()->SetOwnershipType(ELbmOwnsItemArray);
    iListBox->ActivateL();


    iListBoxArray =	new	(ELeave) CDesCArrayFlat(1);
    //iListBoxArray	= static_cast<CDesCArray*>(iListBox->Model()->ItemTextArray());

    CleanupStack::PushL(iListBoxArray);


	// check if file exists
    //User::LeaveIfError(iFsSession.Connect());
    //BaflUtils tmpItem;
    /*if(tmpItem.FileExists(iFsSession, KFileName))
    {
        OpenList();
    }
    else{
        CreateList();
    }*/
    CleanupStack::Pop();    // iListBoxArray
    //GetGroupIndex();
    iListBox->Model()->SetItemTextArray(iListBoxArray);


    SetRect(aRect);
    ActivateL();

    /*CreateWindowL();

    iLabel = new (ELeave) CEikLabel;
    iLabel->SetContainerWindowL( *this );
    iLabel->SetTextL( _L("Example View") );

    iToDoLabel = new (ELeave) CEikLabel;
    iToDoLabel->SetContainerWindowL( *this );
    iToDoLabel->SetTextL( _L("Add Your controls\n here") );

    SetRect(aRect);
    ActivateL();*/
    }

// Destructor
CgoSIPChatUserListContainer::~CgoSIPChatUserListContainer()
    {
    delete iListBox;
	//delete iList;
    //delete iLabel;
    //delete iToDoLabel;
    }

// ---------------------------------------------------------
// CgoSIPChatUserListContainer::SizeChanged()
// Called by framework when the view size is changed
// ---------------------------------------------------------
//
void CgoSIPChatUserListContainer::SizeChanged()
    {
    // TODO: Add here control resize code etc.
    iListBox->SetRect(Rect());
    //iList->SetRect(Rect());
    //iLabel->SetExtent( TPoint(10,10), iLabel->MinimumSize() );
    //iToDoLabel->SetExtent( TPoint(10,100), iToDoLabel->MinimumSize() );
    }

// ---------------------------------------------------------
// CgoSIPChatUserListContainer::CountComponentControls() const
// ---------------------------------------------------------
//
TInt CgoSIPChatUserListContainer::CountComponentControls() const
    {
    return 1; // return nbr of controls inside this container
    }

// ---------------------------------------------------------
// CgoSIPChatUserListContainer::ComponentControl(TInt aIndex) const
// ---------------------------------------------------------
//
CCoeControl* CgoSIPChatUserListContainer::ComponentControl(TInt aIndex) const
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
// CgoSIPChatUserListContainer::Draw(const TRect& aRect) const
// ---------------------------------------------------------
//
void CgoSIPChatUserListContainer::Draw(const TRect& aRect) const
    {
    CWindowGc& gc = SystemGc();
    // TODO: Add your drawing code here
    // example code...
    gc.SetPenStyle( CGraphicsContext::ENullPen );
    gc.SetBrushColor( KRgbGray );
    gc.SetBrushStyle( CGraphicsContext::ESolidBrush );
    gc.DrawRect( aRect );
    }
TKeyResponse CgoSIPChatUserListContainer::OfferKeyEventL(const TKeyEvent& aKeyEvent, TEventCode aType)
	{
	switch(aKeyEvent.iCode) 
		{
		case EKeyLeftArrow:
		case EKeyRightArrow:
			break;
		case EKeyUpArrow:
		case EKeyDownArrow:
			return iListBox->OfferKeyEventL(aKeyEvent, aType);
		}
	return EKeyWasNotConsumed;
	}

void CgoSIPChatUserListContainer::InviteUsers()
	{
		TInt index = -1;
		CAknListQueryDialog* invite;
		invite = new (ELeave) CAknListQueryDialog(&index);
						   //r_gosip_gosipchatuserlist_list_query
		if(invite->ExecuteLD(R_GOSIP_GOSIPCHATUSERLIST_LIST_QUERY))
		{
			if(index==0)
            {
				iEikonEnv->InfoMsg(_L("User Selected."));
			}
			else
			{
				iEikonEnv->InfoMsg(_L("Test."));
			}
		}
	}

// ---------------------------------------------------------
// CgoSIPChatUserListContainer::HandleControlEventL(
//     CCoeControl* aControl,TCoeEvent aEventType)
// ---------------------------------------------------------
//
void CgoSIPChatUserListContainer::HandleControlEventL(
    CCoeControl* /*aControl*/,TCoeEvent /*aEventType*/)
    {
    // TODO: Add your control event handler code here
    }

//hardey add
/*void CgoSIPChatUserListContainer::AddUserToListBox(TBuf<256> buf)
    {
    iListBoxArray->AppendL(buf);
    iListBoxArray->Compress();
    //HandleModelChangeL();
    }*/

/*void CgoSIPChatUserListContainer::GetGroupIndex()
{
    iListBoxArray->Find(_L("\tFamily"),iFamilyIndex);
    iListBoxArray->Find(_L("\tFriends"),iFriendIndex);
    iListBoxArray->Find(_L("\tWorkmates"),iWorkmateIndex);
}*/

// End of File  
