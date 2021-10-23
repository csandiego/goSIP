/*
============================================================================
 Name        : CgoSIPDocument from goSIPDocument.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Declares document for application.
============================================================================
*/

#ifndef GOSIPDOCUMENT_H
#define GOSIPDOCUMENT_H

// INCLUDES
//#include <akndoc.h>
#include <eikdoc.h>
#include <e32des8.h>
#include <badesca.h>
   
// CONSTANTS

// FORWARD DECLARATIONS
class  CEikAppUi;

// CLASS DECLARATION

/**
*  CgoSIPDocument application class.
*/
class CgoSIPDocument : public CEikDocument
    {
    public: // Constructors and destructor
        /**
        * Two-phased constructor.
        */
        static CgoSIPDocument* NewL(CEikApplication& aApp);

        /**
        * Destructor.
        */
        virtual ~CgoSIPDocument();

    public: // New functions

    public: // Functions from base classes
    protected:  // New functions

    protected:  // Functions from base classes

    private:

        /**
        * EPOC default constructor.
        */
        CgoSIPDocument(CEikApplication& aApp);
        void ConstructL();

    private:

        /**
        * From CEikDocument, create CgoSIPAppUi "App UI" object.
        */
        CEikAppUi* CreateAppUiL();

        //my add
    public:
        /**
        * OpenFileL
        * Called by the Uikon framework to open a file.
        * @param aDoOpen open an existing file if ETrue; otherwise create a new file. 
        * @param aFilename the file to open or create. 
        * @param aFs file server session to use. 
        * @return a file store object referring to the newly-opened file.
        */
        //CFileStore* OpenFileL( TBool aDoOpen,const TDesC& aFilename,RFs& aFs );

        /**
        * StoreL
        * Store the document's content and state, recording the identity of any headstreams created.
        * @param aStore stream store to which data is saved
        * @param aStreamDic stream dictionary in which to record headstreams
        */
        //void StoreL( CStreamStore& aStore, CStreamDictionary& aStreamDic ) const;

        /**
        * RestoreL
        * Restore this document from a stream store.
        * @param aStore stream store from which to read the new state and content 
        * @param aStreamDic stream dictionary in which to look up head streams
        */
        //void RestoreL( const CStreamStore& aStore, const CStreamDictionary& aStreamDic );

        //CDesCArray* iListBoxArray;

        /**
        * iFlags a bitfield of flags for the shopping item 
        */
        //TUint iFlags;
    };

#endif



