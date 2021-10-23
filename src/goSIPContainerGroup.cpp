/*
============================================================================
Name		 : goSIPContainerGroup.cpp
Author		 : 
Version	 :
Copyright	 : Your	copyright notice
Description : goSIPContainerGroup.cpp - source	file
============================================================================
*/

// INCLUDE FILES
// Class include
//#include "goSIPContainerGroup.h"
// System includes
//#include <e32base.h>	// For CBase, link against euser.lib
//#include <ResourceFile.rsg>
// User	includes
//#include "MyHeaderFile.h"

// ================= MEMBER	FUNCTIONS =======================

// End of File
/*
============================================================================
Name		 : CgoSIPContainer from	goSIPContainer.h
Author		 : 
Version	 :
Copyright	 : Your	copyright notice
Description : Container control implementation
============================================================================
*/

// INCLUDE FILES
#include "goSIPContainerGroup.h"
#include <bautils.h>
_LIT(KFileName,	"C:\\goSIP\\grouplist.dat");

//#include <eiklabel.h>	 //	for	example	label control


// ================= MEMBER	FUNCTIONS =======================

// ---------------------------------------------------------
// CgoSIPContainer::ConstructL(const TRect&	aRect)
// EPOC	two	phased constructor
// ---------------------------------------------------------
//
void CgoSIPContainerGroup::ConstructL(const	TRect& aRect)
{
    CreateWindowL();

    /*iLabel = new (ELeave)	CEikLabel;
    iLabel->SetContainerWindowL( *this );
    iLabel->SetTextL( _L("Group	View") );

    iToDoLabel = new (ELeave) CEikLabel;
    iToDoLabel->SetContainerWindowL( *this );
    iToDoLabel->SetTextL( _L("Add Your groups\n	here") );*/

    //my add

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



    User::LeaveIfError(iFsSession.Connect());
    BaflUtils tmpItem;
    if(tmpItem.FileExists(iFsSession, KFileName))
    {
        OpenList();
    }
    else{
        CreateList();
    }

    CleanupStack::Pop();    // iListBoxArray

    GetGroupIndex();

    iListBox->Model()->SetItemTextArray(iListBoxArray);

    SetRect(aRect);

    ActivateL();

}

// Destructor
CgoSIPContainerGroup::~CgoSIPContainerGroup()
{
    /*delete iLabel;
    delete iToDoLabel;*/
    delete iListBox;
}

// ---------------------------------------------------------
// CgoSIPContainer::SizeChanged()
// Called by framework when	the	view size is changed
// ---------------------------------------------------------
//
void CgoSIPContainerGroup::SizeChanged()
{
    // TODO: Add here control resize code etc.
    /*iLabel->SetExtent( TPoint(10,10),	iLabel->MinimumSize() );
    iToDoLabel->SetExtent( TPoint(10,100), iToDoLabel->MinimumSize() );*/
    iListBox->SetExtent(TPoint(0,0),iListBox->MinimumSize());
}

// ---------------------------------------------------------
// CgoSIPContainer::CountComponentControls() const
// ---------------------------------------------------------
//
TInt CgoSIPContainerGroup::CountComponentControls()	const
{
    return 1; // return	nbr	of controls	inside this	container
}

// ---------------------------------------------------------
// CgoSIPContainer::ComponentControl(TInt aIndex) const
// ---------------------------------------------------------
//
CCoeControl* CgoSIPContainerGroup::ComponentControl(TInt aIndex) const
{
    switch(	aIndex )
    {
    case 0:	
        return iListBox;
    default:
        return NULL;
    }
    /*switch ( aIndex )
    {
    case 0:
    return iLabel;
    case 1:
    return iToDoLabel;
    default:
    return NULL;
    }*/
}

// ---------------------------------------------------------
// CgoSIPContainer::Draw(const TRect& aRect) const
// ---------------------------------------------------------
//
void CgoSIPContainerGroup::Draw(const TRect& aRect)	const
{
    CWindowGc& gc =	SystemGc();
    // TODO: Add your drawing code here
    // example code...
    gc.SetPenStyle(	CGraphicsContext::ENullPen );
    gc.SetBrushColor( KRgbGray );
    gc.SetBrushStyle( CGraphicsContext::ESolidBrush	);
    gc.DrawRect( aRect );
}

// ---------------------------------------------------------
// CgoSIPContainer::HandleControlEventL(
//	   CCoeControl*	aControl,TCoeEvent aEventType)
// ---------------------------------------------------------
//
void CgoSIPContainerGroup::HandleControlEventL(
    CCoeControl* /*aControl*/,TCoeEvent	/*aEventType*/)
{
    // TODO: Add your control event	handler	code here
}

//my add
TKeyResponse CgoSIPContainerGroup::OfferKeyEventL(const	TKeyEvent& aKeyEvent,TEventCode	aType)
{
    // See if we have a	selection
    TInt code =	aKeyEvent.iCode;
    if ( aKeyEvent.iCode ==	EKeyDownArrow || aKeyEvent.iCode ==	EKeyUpArrow	)
    {
        return iListBox->OfferKeyEventL(aKeyEvent, aType);
        //return iTabGroup->OfferKeyEventL(	aKeyEvent, aType );
    }
    else
    {
        return EKeyWasNotConsumed;
    }
}

//my function add
void CgoSIPContainerGroup::GetGroupIndex()
{
    /*document->iListBoxArray->Find(_L("\tFamily"),iFamilyIndex);
    document->iListBoxArray->Find(_L("\tFriends"),iFriendIndex);
    document->iListBoxArray->Find(_L("\tWorkmates"),iWorkmateIndex);*/
    iListBoxArray->Find(_L("\tFamily"),iFamilyIndex);
    iListBoxArray->Find(_L("\tFriends"),iFriendIndex);
    iListBoxArray->Find(_L("\tWorkmates"),iWorkmateIndex);
}


void CgoSIPContainerGroup::CreateList()
{

    iListBoxArray->AppendL(_L("\tFamily"));
    iListBoxArray->AppendL(_L("\t Dad"));
    iListBoxArray->AppendL(_L("\t Mom"));
    iListBoxArray->AppendL(_L("\tFriends"));
    iListBoxArray->AppendL(_L("\t Jack"));
    iListBoxArray->AppendL(_L("\t James"));
    iListBoxArray->AppendL(_L("\tWorkmates"));
    iListBoxArray->AppendL(_L("\t Connie"));
    iListBoxArray->AppendL(_L("\t Amy"));

    SaveList();
}

void CgoSIPContainerGroup::OpenList()
{
    readstream.PushL();
    User::LeaveIfError(readstream.Open(iFsSession, KFileName, EFileRead));


    TBuf<8>	count;
    TInt i;
    TInt counter;
    //iEikonEnv->InfoMsg(_L("convert num"));
    readstream >> count;
    //iEikonEnv->InfoMsg(count);
    TBuf<256> buf;
    TLex input(count);
    input.Val(counter);

    for(i=0;i<counter;i++)
    {
        readstream >> buf;
        iListBoxArray->AppendL(buf);
    }

    CleanupStack::PopAndDestroy(); //readstream
}

void CgoSIPContainerGroup::SaveList()
{
    writestream.PushL();
    User::LeaveIfError(writestream.Replace(iFsSession, KFileName, EFileWrite));

    TInt i;
    TInt n = iListBoxArray->Count();
    TBuf<8>	num;
    num.AppendNum(n);
    //iEikonEnv->InfoMsg(num);
    writestream	<< num;

    TBuf8<100> buf;
    buf.Delete(0,buf.Length());
    for(TInt i=0; i<iListBoxArray->Count();	i++)
    {
        buf.Append((*iListBoxArray)[i]);
        writestream	<< buf;
        buf.Delete(0,buf.Length());
    }


    writestream.CommitL();
    CleanupStack::PopAndDestroy(); //writestream
}

void CgoSIPContainerGroup::CloseList()
{
    SaveList();
    iFsSession.Close();
}

/*void CgoSIPContainerGroup::SetDocument(CgoSIPDocument* doc)
{
document = doc;
}*/
