/*
============================================================================
 Name        : CgoSIPApp from goSIPApp.cpp
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Main application class
============================================================================
*/

// INCLUDE FILES
#include    "goSIPApp.h"
#include    "goSIPDocument.h"

// ================= MEMBER FUNCTIONS =======================

// ---------------------------------------------------------
// CgoSIPApp::AppDllUid()
// Returns application UID
// ---------------------------------------------------------
//
TUid CgoSIPApp::AppDllUid() const
    {
    return KUidgoSIP;
    }

   
// ---------------------------------------------------------
// CgoSIPApp::CreateDocumentL()
// Creates CgoSIPDocument object
// ---------------------------------------------------------
//
CApaDocument* CgoSIPApp::CreateDocumentL()
    {
    return CgoSIPDocument::NewL( *this );
    }

// ================= OTHER EXPORTED FUNCTIONS ==============
//
// ---------------------------------------------------------
// NewApplication() 
// Constructs CgoSIPApp
// Returns: created application object
// ---------------------------------------------------------
//
EXPORT_C CApaApplication* NewApplication()
    {
    return new CgoSIPApp;
    }

// ---------------------------------------------------------
// E32Dll(TDllReason) 
// Entry point function for EPOC Apps
// Returns: KErrNone: No error
// ---------------------------------------------------------
//
GLDEF_C TInt E32Dll( TDllReason )
    {
    return KErrNone;
    }

  

