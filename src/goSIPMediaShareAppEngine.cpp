/*
============================================================================
 Name        : goSIPMediaShareAppEngine.cpp
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : goSIPMediaShareAppEngine.cpp - source file
============================================================================
*/

// INCLUDE FILES
// Class include
#include "goSIPMediaShareAppEngine.h"
#include "goSIP.hrh"
#include "eikenv.h"
// System includes
//#include <e32base.h>  // For CBase, link against euser.lib
//#include <ResourceFile.rsg>
// User includes
//#include "MyHeaderFile.h"
#include <eiklabel.h>

// Number, name and file size
_LIT(KStringSize,"%d\t%S\t%d bytes");
// Number, name and date modified
_LIT(KStringDate,"%d\t%S\t%S"); 
// Directory for Sounds
_LIT(KDirSounds,"c:\\Nokia\\Sounds\\Digital\\");
// Directory for Pictures
_LIT(KDirPictures,"c:\\Nokia\\Images\\");
// Directory for Videos
_LIT(KDirVideos,"c:\\Nokia\\Videos\\");

_LIT(KFileName, "C:\\sharedfiles");
//TBool created = EFalse;

CgoSIPMediaShareAppEngine::~CgoSIPMediaShareAppEngine()
{
	delete iDirList;
	writestream.Close();
}

/*CgoSIPMediaShareAppEngine* CgoSIPMediaShareAppEngine::NewLC()
{
	CgoSIPMediaShareAppEngine* self = new (ELeave)CgoSIPMediaShareAppEngine();
	CleanupStack::PushL(self);
	self->ConstructL();
	return self;
}

CgoSIPMediaShareAppEngine* CgoSIPMediaShareAppEngine::NewL()
{
	CgoSIPMediaShareAppEngine* self=CgoSIPMediaShareAppEngine::NewLC();
	CleanupStack::Pop(); // self;
	return self;
}*/

void CgoSIPMediaShareAppEngine::ConstructL()
{

}

TInt CgoSIPMediaShareAppEngine::StartFileList()
{
    if (iDirList)
    {        
        delete iDirList;
        iDirList = 0;
    }    
   
    TInt error = KErrNone;

    // Connect to fileserver
    User::LeaveIfError(iFsSession.Connect()); 

    switch (iDirectory)
    {
        // Get dir. KEntryAttNormal means that no hidden files or directories are included
        case ESoundList:
            error = iFsSession.GetDir(KDirSounds,KEntryAttNormal,ESortByName,iDirList);
            break;
        case EImageList:
            error = iFsSession.GetDir(KDirPictures,KEntryAttNormal,ESortByName,iDirList);
            break;
        case EVideoList:
            error = iFsSession.GetDir(KDirVideos,KEntryAttNormal,ESortByName,iDirList);
            break;
        default:
            error = iFsSession.GetDir(KDirPictures,KEntryAttNormal,ESortByName,iDirList);
            break;
    }

    return error;

}

TInt CgoSIPMediaShareAppEngine::StartFileAdd(TDesC* aName)
{
	if (iDirList)
    {        
        delete iDirList;
        iDirList = 0;
    }    
   
    TInt error = KErrNone;

    // Connect to fileserver
    User::LeaveIfError(iFsSession.Connect()); 

	//iEikonEnv->InfoMsg(_L("Connected"));
	//iEikonEnv->InfoMsg(aName);
	//_LIT(tux,"c:\\Nokia\\Images\\Tux.jpg");
	//iEikonEnv->InfoMsg(tux);
	error = iFsSession.GetDir(*aName,KEntryAttNormal,ESortByName,iDirList);
	//iEikonEnv->InfoMsg(error);

	return error;
}

void CgoSIPMediaShareAppEngine::AddItem(CDesCArray* aItems)
{
	if(!iDirList)
	{
		//iEikonEnv->InfoMsg(_L("No Fetch"));
		return;
	}

	TFileName filename = NULL;
	//iEikonEnv->InfoMsg(iDirList->Count());
	//for(TInt i=0;i<iDirList->Count();i++)
	{
		filename.Format(KStringSize,1,&(*iDirList)[0].iName,(*iDirList)[0].iSize);
	}

	TInt index;

	/*writestream.PushL();
	if(!created)
	{
		iEikonEnv->InfoMsg(_L("Creating file"));
		User::LeaveIfError(writestream.Create(iFsSession, KFileName, EFileWrite));
		created = ETrue;
	}
	else
	{
		iEikonEnv->InfoMsg(_L("Opening file"));
		User::LeaveIfError(writestream.Open(iFsSession, KFileName, EFileWrite));
	}*/
	if(aItems->Find(filename,index))
	{
		//iEikonEnv->InfoMsg(_L("Writing to file"));
		aItems->AppendL(filename);
		/*writestream << filename;
		writestream.CommitL();
		CleanupStack::PopAndDestroy();*/
	}
}



void CgoSIPMediaShareAppEngine::GetFileListItems(CDesCArray* aItems)
{
    if(!iDirList)
        return;
                       
    for (TInt i=0;i<iDirList->Count();i++)
    {
        TFileName filename = NULL;
        if(iSizeDate==EFileListSize)
        {
            // Show file size
            filename.Format(KStringSize,i+1,&(*iDirList)[i].iName,(*iDirList)[i].iSize);
        }
        else
        {
            // Fix the date and time string of last modification
            TBuf<30> dateString; 
            _LIT(KDateString,"%D%M%Y%/0%1%/1%2%/2%3%/3 %-B%:0%J%:1%T%:2%S%:3%+B");
            (*iDirList)[i].iModified.FormatL(dateString,KDateString); 

            // Show date modified
            filename.Format(KStringDate,i+1,&(*iDirList)[i].iName,&dateString);
        }
        aItems->AppendL(filename);
    }
        
}

void CgoSIPMediaShareAppEngine::SetDirectory(TInt aDirectory)
{
    if (aDirectory!=EFileListDirNoChange)
        iDirectory=aDirectory;
}

/*void CFileListEngine::LaunchCurrent(TInt aPosition)
    {

    if(!iDirList)
        return;

     //Launch current item in the list
 
    CDocumentHandler* handler = CDocumentHandler::NewL(NULL);
    CleanupStack::PushL(handler);
    TFileName descr;
    // Use appropriate directory path for launching file
    switch (iDirectory)
        {   
        case EFileListSounds:
            descr.Append(KDirSounds);
            break;
        case EFileListPictures:
            descr.Append(KDirPictures);
            break;
        case EFileListVideos:
            descr.Append(KDirVideos);
            break;
        default:
            descr.Append(KDirSounds);
            break;
        }
    // Add filename to be launched
    descr.Append((*iDirList)[aPosition].iName);
    // Create nullType. This makes the DocumentHandler to figure out the posfix for us.
    TDataType nullType;
    // Launch the appropriate application for this file
    handler->OpenFileL(descr,nullType);
    CleanupStack::PopAndDestroy(); // handler
    };*/

TBool CgoSIPMediaShareAppEngine::RemoveItems(CDesCArray* aItems)
{
    if(iDirList)
        {        
        if (iDirList->Count())
            {
            aItems->Delete(0,(iDirList->Count()));
            return ETrue;
            }
        }    
    return EFalse;
};

void CgoSIPMediaShareAppEngine::SetSizeDate(TInt aSizeDate)
{
    if (aSizeDate==EFileListToggle)
        if (iSizeDate==EFileListSize)
            iSizeDate=EFileListDate;
        else
            iSizeDate=EFileListSize;
    else
        if (aSizeDate!=EFileListSizeDateNoChange)
            iSizeDate=aSizeDate;
};

void CgoSIPMediaShareAppEngine::EndFileList()
{
    // Close the file server session
    iFsSession.Close();
};

void CgoSIPMediaShareAppEngine::SaveItemsL(CDesCArray* aItems)
{
	writestream.PushL();
	User::LeaveIfError(iFsSession.Connect());
	User::LeaveIfError(writestream.Replace(iFsSession, KFileName, EFileWrite));

	TInt i;
	TInt n = aItems->MdcaCount();
	TBuf<8> num;
	num.AppendNum(n);
	iEikonEnv->InfoMsg(num);
	writestream << num;

	for(i=0;i<aItems->MdcaCount();i++)
	{
		writestream << static_cast<TFileName>(aItems->MdcaPoint(i));
	}

	writestream.CommitL();
	CleanupStack::PopAndDestroy(); //writestream
	iFsSession.Close();
}

void CgoSIPMediaShareAppEngine::LoadItemsL(CDesCArray* aItems)
{
	readstream.PushL();
	User::LeaveIfError(iFsSession.Connect());
	User::LeaveIfError(readstream.Open(iFsSession, KFileName, EFileRead));

	TBuf<8> count;
	TInt i;
	TInt counter;
	iEikonEnv->InfoMsg(_L("convert num"));
	readstream >> count;
	iEikonEnv->InfoMsg(count);
	TBuf<256> buf;
	TLex input(count);
	input.Val(counter);

	for(i=0;i<counter;i++)
	{
		readstream >> buf;
		//iEikonEnv->InfoMsg(buf);
		aItems->AppendL(buf);
	}

	CleanupStack::PopAndDestroy(); //readstream
	iFsSession.Close();
}

void CgoSIPMediaShareAppEngine::SearchAndLoadItemsL(CDesCArray* aSearchResult, TBuf<256> aFilename )
{
	readstream.PushL();
	User::LeaveIfError(iFsSession.Connect());
	User::LeaveIfError(readstream.Open(iFsSession, KFileName, EFileRead));

	TBuf<8> count;
	TInt i;
	TInt counter;
	TInt index;
	readstream >> count;
	TBuf<256> buf;
	TLex input(count);
	input.Val(counter);
	iEikonEnv->InfoMsg(_L("beforeloop"));
	
	aSearchResult->Reset();

	for(i=0;i<counter;i++)
	{
		readstream >> buf;
		iEikonEnv->InfoMsg(buf);
		
		TBuf16<256> pattern;
		pattern.Append('*');
		pattern.Append(aFilename);
		pattern.Append('*');
		
		TInt matcher = buf.MatchF(pattern);
		iEikonEnv->InfoMsg(pattern);
		
		if(matcher != KErrNotFound)
		{
			aSearchResult->AppendL(buf);
		}
		//aItems->AppendL(buf);	

		//iEikonEnv->InfoMsg(_L("appenditems"));
	}

	//iEikonEnv->InfoMsg(aItems->MdcaPoint(0));
	//iEikonEnv->InfoMsg(aFilename);
	/*if(!(aItems->Find(aFilename,index)))
	{   
		//iEikonEnv->InfoMsg(index);
		iEikonEnv->InfoMsg(_L("adding result"));
		aSearchResult->AppendL(aFilename);
	}*/

	CleanupStack::PopAndDestroy(); //readstream
	iFsSession.Close();
}

// ================= MEMBER FUNCTIONS =======================

// End of File
