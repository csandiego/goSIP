/*
============================================================================
 Name        : CgoSIPMediaShareShareView from goSIPMediaShareShareView.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : CgoSIPMediaShareShareView implementation
============================================================================
*/

// INCLUDE FILES
#include  <aknviewappui.h>
#include  <avkon.hrh>
// TODO: Change the following include directive to point to the correct
// resource header file. The current value should be correct if the project
// was created using one of the templates provided by Nokia.
#include  <goSIP.rsg>
#include  "goSIPMediaShareShareView.h"
#include  "goSIPMediaShareShareContainer.h"
#include "goSIP.hrh"
#include <MGFetch.h>

TBool add = EFalse;
TBool load = ETrue;

// ================= MEMBER FUNCTIONS =======================

// ---------------------------------------------------------
// CgoSIPMediaShareShareView::ConstructL(const TRect& aRect)
// EPOC two-phased constructor
// ---------------------------------------------------------
//
void CgoSIPMediaShareShareView::ConstructL()//(CSymbian1Container2* aContainer)
{
    BaseConstructL( R_GOSIP_GOSIPMEDIASHARESHARE_VIEW );
	//iContainer = aContainer;
}

// ---------------------------------------------------------
// CgoSIPMediaShareShareView::~CgoSIPMediaShareShareView()
// destructor
// ---------------------------------------------------------
//
CgoSIPMediaShareShareView::~CgoSIPMediaShareShareView()
{
    if ( iContainer )
    {
        AppUi()->RemoveFromViewStack( *this, iContainer );
    }

    delete iContainer;
	iContainer = NULL;

	//delete iMemorySelect;
	//delete iTypeChooser;
}

// ---------------------------------------------------------
// TUid CgoSIPMediaShareShareView::Id()
// 
// ---------------------------------------------------------
//
TUid CgoSIPMediaShareShareView::Id() const
{
    return KgoSIPMediaShareShareViewId;
}

// ---------------------------------------------------------
// CgoSIPMediaShareShareView::HandleCommandL(TInt aCommand)
// takes care of view command handling
// ---------------------------------------------------------
//
void CgoSIPMediaShareShareView::HandleCommandL(TInt aCommand)
{   
    switch ( aCommand )
    {
        case EAknSoftkeyOk:
        {
            iEikonEnv->InfoMsg( _L("view2 ok") );
            break;
        }
        case EAknSoftkeyBack:
        {
			
			/*TRAPD(error, iContainer->Save());
			
			if(error)
			{
				iEikonEnv->InfoMsg( _L("error") );
            }
			else
			{
				//iEikonEnv->InfoMsg( _L("no err") );
            
			}*/
			
			this->DoDeactivate();
            AppUi()->HandleCommandL(EgoSIPCmdAppShareFilesClose);
            break;
        }

		case EgoSIPMediaShareShare:
		{
				CAknMemorySelectionDialog* iMemorySelect = CAknMemorySelectionDialog::NewL(ECFDDialogTypeNormal, ETrue); 
				//CleanupStack::PushL(iMemorySelect);
				// = CAknMemorySelectionDialog::ConstructFromResourceL(0, ETrue);
				//MAknMemorySelectionObserver* obs = new (ELeave) MAknMemorySelectionObserver();
				//CAknFileSelectionDialog* file = CAknFileSelectionDialog::NewL(ECFDDialogTypeSelect );
				MAknMemorySelectionObserver *  aObserver = NULL; 
				//CleanupStack::PushL(aObserver);

				_LIT(iTitle, "Phone Memory");
				CAknMemorySelectionDialog::TMemory t = CAknMemorySelectionDialog::EPhoneMemory;
				//CleanupStack::PushL(iTypeChooser);
				
				if(iMemorySelect->RunDlgLD(t, iTitle, aObserver))
				{
					iEikonEnv->InfoMsg(_L("OK memory"));
					//CAknListQueryDialog* iTypeChooser = NULL;
					TInt index;
					CAknListQueryDialog* iTypeChooser = new (ELeave) CAknListQueryDialog(&index);
					if(iTypeChooser->ExecuteLD(R_GOSIP_MEDIASHARE_SELECT_DIRECTORY))
					{
						if(index==0)
						{
							iEikonEnv->InfoMsg(_L("Selected Images."));
							//iContainer->SetFileList(EImageList, EFileListSize);
							/*TRAPD(error, BrowseFilesL(EImageFile))
							if(error)
							{
							
							}*/
							BrowseFilesL(EImageFile);
						
						
						}
						else if(index==1)
						{
							iEikonEnv->InfoMsg(_L("Selected  Sounds."));
							//iContainer->SetFileList(ESoundList, EFileListSize);
							BrowseAudio(PathInfo::SoundsPath());
						}
						else if(index==2)
						{
							iEikonEnv->InfoMsg(_L("Selected Videos."));
							//iContainer->SetFileList(EVideoList, EFileListSize);
							BrowseFilesL(EVideoFile);
						}
						delete aObserver;
						aObserver = NULL;
						delete iMemorySelect;
						iMemorySelect = NULL;
					}
					else
					{
						//delete iTypeChooser;
						iTypeChooser = NULL;
						delete aObserver;
						aObserver = NULL;
						delete iMemorySelect;
						iMemorySelect = NULL;
						this->HandleCommandL(EgoSIPMediaShareShare);
					}
					//delete iTypeChooser;
					//iTypeChooser = NULL;
				}
				else
				{
					//CleanupStack::PopAndDestroy(iTypeChooser);
					delete aObserver;
					aObserver = NULL;
					delete iMemorySelect;
					iMemorySelect = NULL;
					iEikonEnv->InfoMsg(_L("Back"));
				}
				//CleanupStack::PopAndDestroy(aObserver);
				
				break;
		}
		case EgoSIPMediaShareUnshare:
		{
			iEikonEnv->InfoMsg(_L("Unshare" ));
			iContainer->Unshare();
			break;
		}

        default:
        {
            //AppUi()->HandleCommandL( aCommand );
            break;
        }
    }
}

// ---------------------------------------------------------
// CgoSIPMediaShareShareView::HandleClientRectChange()
// ---------------------------------------------------------
//
void CgoSIPMediaShareShareView::HandleClientRectChange()
{
    if ( iContainer )
    {
        iContainer->SetRect( ClientRect() );
    }
}

// ---------------------------------------------------------
// CgoSIPMediaShareShareView::DoActivateL(...)
// 
// ---------------------------------------------------------
//
void CgoSIPMediaShareShareView::DoActivateL(
   const TVwsViewId& /*aPrevViewId*/,TUid /*aCustomMessageId*/,
   const TDesC8& /*aCustomMessage*/)
{
    if (!iContainer)
    {
        iContainer = new (ELeave) CgoSIPMediaShareShareContainer;
        iContainer->SetMopParent(this);
        iContainer->ConstructL( ClientRect() );
        AppUi()->AddToStackL( *this, iContainer );
		if(load)
		{
			//AknListBoxUtils::HandleItemRemovalAndPositionHighlightL(iContainer->iListBox, 1, EFalse);
			//AknListBoxUtils::HandleItemRemovalAndPositionHighlightL(iContainer->iListBox, 0, EFalse);
			iContainer->Load();
			load = EFalse;
		}
    }
	/*if(!iContainer)
	{
		iContainer->SetMopParent(this);
		iContainer->ConstructL( ClientRect() );
		AppUi()->AddToStackL( *this, iContainer );
	}*/
}

// ---------------------------------------------------------
// CgoSIPMediaShareShareView::DoDeactivate()
// 
// ---------------------------------------------------------
//
void CgoSIPMediaShareShareView::DoDeactivate()
{
    if ( iContainer )
    {
		if(add)
		{
			iContainer->Save();
			add = EFalse;
		}
		load = ETrue;
        AppUi()->RemoveFromViewStack( *this, iContainer );
    }
    
    delete iContainer;
    iContainer = NULL;
}

void CgoSIPMediaShareShareView::BrowseFilesL(TMediaFileType aMediaType)
{
	// Create array of descriptors for the selected files
	CDesCArrayFlat* fileArray = new (ELeave) CDesCArrayFlat(5);
	CleanupStack::PushL(fileArray);

	// Open the dialog.
	TBool ret = MGFetch::RunL(
		*fileArray, // When dialog is closed, fileArray contains selected files
		aMediaType, // Displays only media files of type aMediaType
		EFalse,		// Not used in S60 2.0 (single or multiple file selection)
		this		// Pointer to class implementing MMGFetchVerifier;
					// when user has selected file(s), 
					// MMGFetchVerifier::VerifySelectionL is called.
		);

	// "ret" is true, if user has selected file(s)
	if( ret )
	{
		// Open the first selected file into default application
		_LIT(KQueryStr, "Share file?");
		if(iEikonEnv->QueryWinL(KQueryStr, fileArray->MdcaPoint(0)))
		{
			//ViewFileL(fileArray->MdcaPoint(0));
			//CSymbian1Document* temp = static_cast<CSymbian1Document*>(AppUi()->Document());
			TBuf<256> buf;
			buf = fileArray->MdcaPoint(0);
			buf.TrimAll();
			//temp->InsertItemL(&static_cast<TFileName>(buf));
			
			CgoSIPMediaShareAppEngine* t = new (ELeave) CgoSIPMediaShareAppEngine;
			/*TRAPD(error, t = new (ELeave) CgoSIPMediaShareAppEngine)
			if(error)
			{
				iEikonEnv->InfoMsg(_L("error" ));
			}*/
			
			
			
			CleanupStack::PushL(t);
			iEikonEnv->InfoMsg(buf);
			t->StartFileAdd(&buf);
									
			iContainer->UpdateList(t);
			
			t->EndFileList();
			CleanupStack::PopAndDestroy(t);
			add = ETrue;
			//CleanupStack::Pop(t);
		}
	}

	CleanupStack::PopAndDestroy(fileArray); // fileArray
}


// ----------------------------------------------------------------------------
// CFileFetcherAppUi::VerifySelectionL
// 
// Inherited from MMGFetchVerifier.
// Called when user selects file(s) from MGFetch dialog.
// ----------------------------------------------------------------------------
TBool CgoSIPMediaShareShareView::VerifySelectionL(const MDesCArray* /*aSelectedFiles*/)
{
	// Verify the validity of aSelectedFiles if needed.
	// Return ETrue if we accept the selected file(s), otherwise return EFalse
	return ETrue;
}

void CgoSIPMediaShareShareView::BrowseAudio(const TFileName& aPath)
{
	TFileName filename;

	// Create default filename. (contains only the folder, 
	// e.g. C:\Nokia\Images\) This is used as a starting folder for browsing.
	filename.Append(PathInfo::PhoneMemoryRootPath());
	filename.Append(aPath);

	_LIT(KDialogTitle, "Select file");
	TBool ret = CAknFileSelectionDialog::RunDlgLD(
		filename,		// on return, contains the selected file's name
		PathInfo::PhoneMemoryRootPath(), // default root path for browsing
		KDialogTitle,	// Dialog's title
		this			// Pointer to class implementing 
						// MAknFileSelectionObserver. OkToExitL is called
						// when user has selected an file.
		);

	// "ret" is true, if user has selected a file
	if( ret )
	{
		// Open the selected file into default application
		_LIT(KQueryStr, "Share file?");
		if( iEikonEnv->QueryWinL(KQueryStr,filename ) )
		{
			//ViewFileL(filename);
			//CSymbian1Document* temp = static_cast<CSymbian1Document*>(AppUi()->Document());
			TBuf<256> buf;
			buf = filename;
			buf.TrimAll();
			//temp->InsertItemL(&static_cast<TFileName>(buf));
			CgoSIPMediaShareAppEngine* t = new (ELeave) CgoSIPMediaShareAppEngine;
			CleanupStack::PushL(t);
			iEikonEnv->InfoMsg(buf);
			t->StartFileAdd(&buf);
			iContainer->UpdateList(t);
			t->EndFileList();
			add = ETrue;
			CleanupStack::PopAndDestroy(t);
		}
	}
}


// ----------------------------------------------------------------------------
// CFileFetcherAppUi::OkToExitL
//
// Inherited from MAknFileSelectionObserver.
// Called when user selects a file from CAknFileSelectionDialog.
// ----------------------------------------------------------------------------
TBool CgoSIPMediaShareShareView::OkToExitL (const TDesC& /*aDriveAndPath*/,
									const TEntry& /*aEntry*/)
{
	// Return ETrue if it is OK to close the CAknFileSelectionDialog.
	return ETrue;
}

