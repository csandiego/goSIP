/*
============================================================================
 Name        : goSIPMediaShareAppEngine.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : goSIPMediaShareAppEngine.h - header file
============================================================================
*/

#ifndef GOSIPMEDIASHAREAPPENGINE_H
#define GOSIPMEDIASHAREAPPENGINE_H

// INCLUDES
// System Includes
//#include <e32base.h>  // CBase, link against euser.lib
// FORWARD DECLARATIONS
//class MyClass;

#include <e32std.h>
#include <e32base.h>
#include <coecntrl.h>
#include <f32file.h>        // for CDir
#include <documenthandler.h>// for launching
#include <badesca.h>        // for CDesCArray
#include <apmstd.h>         // for TDataType
#include <coecntrl.h>
//#include <CAknFileSelectionDialog.h>

#include <s32file.h>

// CLASS DECLARATION
class CEikLabel;
/**
*  CgoSIPMediaShareAppEngine
* 
*/
class CgoSIPMediaShareAppEngine : public CCoeControl
{
public: // Constructors and destructor

	/**
        * Destructor.
        */
	~CgoSIPMediaShareAppEngine();

	void ConstructL();

        /**
        * Two-phased constructor.
        */
	//static CgoSIPMediaShareAppEngine* NewL();

        /**
        * Two-phased constructor.
        */
	//static CgoSIPMediaShareAppEngine* NewLC();

private:

	/**
        * Constructor for performing 1st stage construction
        */
	//CgoSIPMediaShareAppEngine();

	/**
        * EPOC default constructor for performing 2nd stage construction
        */

public:

	TInt StartFileList();
	void GetFileListItems(CDesCArray* iItems);
	void SetDirectory(TInt aDirectory);
	void SetSizeDate(TInt aSizeDate);
	void EndFileList();
	void AddItem(CDesCArray* aItems);
	TInt StartFileAdd(TDesC* aName);
	TBool RemoveItems(CDesCArray* aItems);
	void SaveItemsL(CDesCArray* aItems);
	void LoadItemsL(CDesCArray* aItems);
	void SearchAndLoadItemsL(CDesCArray* aSearchResult, TBuf<256> aFilename);
	//void LaunchCurrent(TInt aPosition);
	

//DATA

private:
	CDir* iDirList;
	RFs iFsSession;
	TInt iDirectory;
	TInt iSizeDate; 
	RFileWriteStream writestream;
	RFileReadStream readstream;

};

// CLASS DECLARATION

#endif // GOSIPMEDIASHAREAPPENGINE_H

// End of File
