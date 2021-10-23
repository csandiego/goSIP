/*
============================================================================
 Name        : CgoSIPDocument from goSIPDocument.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : CgoSIPDocument implementation
============================================================================
*/

// INCLUDE FILES
#include <stringloader.h>
#include "goSIPDocument.h"
//#include "goSIPGroupContainer.h"
#include "goSIPAppui.h"

// ================= MEMBER FUNCTIONS =======================

// constructor
CgoSIPDocument::CgoSIPDocument(CEikApplication& aApp)
: CEikDocument(aApp)    
    {
    }

// destructor
CgoSIPDocument::~CgoSIPDocument()
    {
    }

// EPOC default constructor can leave.
void CgoSIPDocument::ConstructL()
    {
    }

// Two-phased constructor.
CgoSIPDocument* CgoSIPDocument::NewL(
        CEikApplication& aApp)     // CgoSIPApp reference
    {
    CgoSIPDocument* self = new (ELeave) CgoSIPDocument( aApp );
    CleanupStack::PushL( self );
    self->ConstructL();
    CleanupStack::Pop();

    return self;
    }
    
// ----------------------------------------------------
// CgoSIPDocument::CreateAppUiL()
// constructs CgoSIPAppUi
// ----------------------------------------------------
//
CEikAppUi* CgoSIPDocument::CreateAppUiL()
    {
    return new (ELeave) CgoSIPAppUi;
    }

// ---------------------------------------------------------
// CShoppingListDocument::OpenFileL()
// ---------------------------------------------------------
//
/*CFileStore* CgoSIPDocument::OpenFileL( TBool aDoOpen, const TDesC& aFilename, RFs& aFs )
    {
    return CEikDocument::OpenFileL( aDoOpen, aFilename, aFs );
    }

// ---------------------------------------------------------
// CShoppingListDocument::StoreL()
// ---------------------------------------------------------
//
/*void CgoSIPDocument::StoreL( CStreamStore& aStore, 
                                    CStreamDictionary& aStreamDic ) const
    {
    RStoreWriteStream stream;

    TStreamId id = stream.CreateLC( aStore );

    TInt count = iListBoxArray->Count();

    stream.WriteInt16L( static_cast<TInt16>( count ) );

    TBuf8<100> buf;

    for(TInt index = 0; index < count; ++index)
        {
        buf.Append((*iListBoxArray)[index]);
        stream.WriteL(buf);
        buf.Delete(0,buf.Length());
        }

    for ( TInt index = 0; index < count; ++index )
        {
        iArray[index]->ExternalizeL( stream );
        }
        */
    /*
    if ( iName )
        {
        aStream << *iName;
        }
    else
        {
        aStream << KNullDesC;
        }
    aStream.WriteInt32L( iFlags );



    stream.CommitL();

    aStreamDic.AssignL( Application()->AppDllUid(), id );
    CleanupStack::PopAndDestroy(); // stream
        
    }*/

// ---------------------------------------------------------
// CShoppingListDocument::RestoreL()
// ---------------------------------------------------------
//
/*void CgoSIPDocument::RestoreL( const CStreamStore& aStore, 
                                      const CStreamDictionary& aStreamDic )
    {
    /*TBuf8<40> buf;

    for (;;)
        {
        User::LeaveIfError(file.Read(buf));
        const TDesC8& aText = buf;
        TLex8 aLex(aText);
        aLex.Mark();
        while(aLex.Peek() != '\n') aLex.Inc();
        TPtrC8 aStr = aLex.MarkedToken();
        aLex.Inc();
        array->AppendL(aStr);
        if (buf.Length() != 40)
        break;
        }*/

    /*TStreamId id = aStreamDic.At( Application()->AppDllUid() );
    RStoreReadStream stream;
    stream.OpenLC( aStore, id );

    TInt count = stream.ReadInt16L();

    //TDes8 buf;
    //iEikonEnv->InfoMsg(buf);
    
    TBuf16<100> buf;

    for ( TInt index = 0; index < count; ++index )
        {
        stream.ReadL(buf);
        const TDesC16& abuf = buf;
        /*TLex8 aLex(abuf);
        aLex.Mark();
        while(aLex.Peek() != '\0') aLex.Inc();
        TPtrC8 aS*/
        //iListBoxArray.Append(abuf);
        //buf.Delete(0,buf.Length());
        /*CShoppingItem* item = CShoppingItem::NewL();
        CleanupStack::PushL( item );
        item->InternalizeL( stream );
        User::LeaveIfError( iItemList.Append( item ) );
        CleanupStack::Pop( item );*/
        /*}

    CleanupStack::PopAndDestroy();  // stream*/
//    }
