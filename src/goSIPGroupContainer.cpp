/*
============================================================================
Name		 : goSIPGroupContainer.cpp
Author		 : 
Version	 :
Copyright	 : Your	copyright notice
Description : goSIPGroupContainer.cpp - source	file
============================================================================
*/

// INCLUDE FILES
// Class include
//#include "goSIPGroupContainer.h"
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
#include "goSIPGroupContainer.h"
#include "goSIPUser.h"
#include <bautils.h>
_LIT(KFileName,	"C:\\goSIP\\grouplist.dat");

//#include <eiklabel.h>	 //	for	example	label control


// ================= MEMBER	FUNCTIONS =======================

// ---------------------------------------------------------
// CgoSIPContainer::ConstructL(const TRect&	aRect)
// EPOC	two	phased constructor
// ---------------------------------------------------------
//
void CgoSIPGroupContainer::ConstructL(const	TRect& aRect)
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


	// check if file exists
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
CgoSIPGroupContainer::~CgoSIPGroupContainer()
{
    /*delete iLabel;
    delete iToDoLabel;*/

    userArray.ResetAndDestroy();
    delete iListBox;
}

// ---------------------------------------------------------
// CgoSIPContainer::SizeChanged()
// Called by framework when	the	view size is changed
// ---------------------------------------------------------
//

void CgoSIPGroupContainer::SizeChanged()
{
    // TODO: Add here control resize code etc.
    /*iLabel->SetExtent( TPoint(10,10),	iLabel->MinimumSize() );
    iToDoLabel->SetExtent( TPoint(10,100), iToDoLabel->MinimumSize() );*/
	
    //MY DEL 1003 iListBox->SetExtent(TPoint(0,0),iListBox->MinimumSize());
	
	iListBox->SetRect(Rect()); // MY ADD 1003
}

// ---------------------------------------------------------
// CgoSIPContainer::CountComponentControls() const
// ---------------------------------------------------------
//
TInt CgoSIPGroupContainer::CountComponentControls()	const
{
    return 1; // return	nbr	of controls	inside this	container
}

// ---------------------------------------------------------
// CgoSIPContainer::ComponentControl(TInt aIndex) const
// ---------------------------------------------------------
//
CCoeControl* CgoSIPGroupContainer::ComponentControl(TInt aIndex) const
{
    switch(	aIndex )
    {
    case 0:	
        return iListBox;
    default:
        return NULL;
    }
}

// ---------------------------------------------------------
// CgoSIPContainer::Draw(const TRect& aRect) const
// ---------------------------------------------------------
//
void CgoSIPGroupContainer::Draw(const TRect& aRect)	const
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
void CgoSIPGroupContainer::HandleControlEventL(
    CCoeControl* /*aControl*/,TCoeEvent	/*aEventType*/)
{
    // TODO: Add your control event	handler	code here
}

//my add
TKeyResponse CgoSIPGroupContainer::OfferKeyEventL(const	TKeyEvent& aKeyEvent,TEventCode	aType)
{
    // See if we have a	selection
	/* MY DEL 1003
    TInt code =	aKeyEvent.iCode;
    if ( aKeyEvent.iCode ==	EKeyDownArrow || aKeyEvent.iCode ==	EKeyUpArrow	)
    {
        return iListBox->OfferKeyEventL(aKeyEvent, aType);
        //return iTabGroup->OfferKeyEventL(	aKeyEvent, aType );
    }
    else
    {
        return EKeyWasNotConsumed;
    }*/

	// MY ADD 1003
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

//my function add
void CgoSIPGroupContainer::GetGroupIndex()
{
    /*document->iListBoxArray->Find(_L("\tFamily"),iFamilyIndex);
    document->iListBoxArray->Find(_L("\tFriends"),iFriendIndex);
    document->iListBoxArray->Find(_L("\tWorkmates"),iWorkmateIndex);*/
    iListBoxArray->Find(_L("\tFamily"),iFamilyIndex);
    iListBoxArray->Find(_L("\tFriends"),iFriendIndex);
    iListBoxArray->Find(_L("\tWorkmates"),iWorkmateIndex);
}

//------------------------
// do this when file not found/list empty
//------------------
void CgoSIPGroupContainer::CreateList()
{
    iListBoxArray->AppendL(_L("\tFamily"));
    TBuf<256> name, sip;
    name.Append(_L("\tFamily"));
    sip.Append(_L("---"));
    name.Delete(0,name.Length());
    sip.Delete(0,sip.Length());
    userArray.Append(new CgoSIPUser( name , sip ));

    /*iListBoxArray->AppendL(_L("\t Dad"));
    iListBoxArray->AppendL(_L("\t Mom"));*/
    iListBoxArray->AppendL(_L("\tFriends"));
    name.Append(_L("\tFriends"));
    sip.Append(_L("---"));
    name.Delete(0,name.Length());
    sip.Delete(0,sip.Length());
    userArray.Append(new CgoSIPUser( name , sip ));

    iListBoxArray->AppendL(_L("\t weh"));
    name.Append(_L("\t weh"));
    sip.Append(_L("sip:weh@realm"));
    name.Delete(0,name.Length());
    sip.Delete(0,sip.Length());
    userArray.Append(new CgoSIPUser( name , sip ));

    iListBoxArray->AppendL(_L("\t Gwaposiaids"));
    name.Append(_L("\t Gwaposiaids"));
    sip.Append(_L("sip:Gwaposiaids@realm"));
    name.Delete(0,name.Length());
    sip.Delete(0,sip.Length());
    userArray.Append(new CgoSIPUser( name , sip ));

    /*iListBoxArray->AppendL(_L("\t Jack"));
    iListBoxArray->AppendL(_L("\t James"));*/

    iListBoxArray->AppendL(_L("\tWorkmates"));
    name.Append(_L("\tWorkmates"));
    sip.Append(_L("---"));
    name.Delete(0,name.Length());
    sip.Delete(0,sip.Length());
    userArray.Append(new CgoSIPUser( name , sip ));
    
    /*iListBoxArray->AppendL(_L("\t Connie"));
    iListBoxArray->AppendL(_L("\t Amy"));*/

    SaveList();
}

void CgoSIPGroupContainer::OpenList()
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
    TBuf<256> sipbuf;
    TLex input(count);
    input.Val(counter);

    for(i=0;i<counter;i++)
    {
        readstream >> buf;
        iListBoxArray->AppendL(buf);
        readstream >> sipbuf;
        CgoSIPUser*  usertmp =  new CgoSIPUser( buf , sipbuf );
        userArray.Append(usertmp);
    }

    CleanupStack::PopAndDestroy(); //readstream

    iFsSession.Close();
}

void CgoSIPGroupContainer::SaveList()
{
    User::LeaveIfError(iFsSession.Connect());
    writestream.PushL();
    User::LeaveIfError(writestream.Replace(iFsSession, KFileName, EFileWrite));

    TInt i;
    TInt n = iListBoxArray->Count();
    TBuf<8>	num;
    num.AppendNum(n);
    //iEikonEnv->InfoMsg(num);
    writestream	<< num;

    TBuf<256> buf;
    TBuf<256> sipbuf;
    buf.Delete(0,buf.Length());
    for(TInt i=0; i<iListBoxArray->Count();	i++)
    {
        buf.Append((*iListBoxArray)[i]);
        writestream << buf;
        /*if(!buf.Compare(_L("\tFamily")) && !buf.Compare(_L("\tFriends")) && !buf.Compare(_L("\tWorkmates")))
            {*/
        sipbuf.Append(userArray[i]->GetSIPAddress());
        writestream << sipbuf;
            /*}
        else
            {
            sipbuf.Append(_L("---"));
            writestream << sipbuf;
            }*/
        sipbuf.Delete(0,sipbuf.Length());
        buf.Delete(0,buf.Length());
    }

    writestream.CommitL();
    CleanupStack::PopAndDestroy(); //writestream
    iFsSession.Close();    
}

void CgoSIPGroupContainer::CloseList()
{
    SaveList();
}
