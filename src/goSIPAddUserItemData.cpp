/*
============================================================================
 Name        : goSIPAddUserItemData.cpp
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : goSIPAddUserItemData.cpp - source file
============================================================================
*/

// INCLUDE FILES
#include <eikenv.h>
#include <in_sock.h>
#include <goSIP.rsg>
#include "goSIPAddUserItemData.h"

// ========================= MEMBER FUNCTIONS ==================================

// -----------------------------------------------------------------------------
// CgoSIPAddUserItemData::NewL()
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
CgoSIPAddUserItemData* CgoSIPAddUserItemData::NewL()
    {
    CgoSIPAddUserItemData* data = new( ELeave ) CgoSIPAddUserItemData;
    CleanupStack::PushL(data);
    data->ConstructL();
    CleanupStack::Pop();
    return data;
    }


// -----------------------------------------------------------------------------
// CgoSIPAddUserItemData::~CgoSIPAddUserItemData()
// Destructor.
// -----------------------------------------------------------------------------
//
CgoSIPAddUserItemData::~CgoSIPAddUserItemData()
    {
    // No implementation required
    }


// -----------------------------------------------------------------------------
// CgoSIPAddUserItemData::CgoSIPAddUserItemData()
// C++ default constructor can NOT contain any code, that might leave.
// -----------------------------------------------------------------------------
//
CgoSIPAddUserItemData::CgoSIPAddUserItemData() /*: iVolume( 5 )*/
    {
    // No implementation required
    }


// ------------------------------------------------------------------------------
// CgoSIPAddUserItemData::ConstructL()
// Symbian 2nd phase constructor can leave.
// ------------------------------------------------------------------------------
//
void CgoSIPAddUserItemData::ConstructL()
    {

    //Sets the initial value of the iTextBuf
	CEikonEnv* env = CEikonEnv::Static();
    env->ReadResource( iSIPAddress,R_GOSIP_ADDUSER_EDWIN_TEXT);
   env->ReadResource( iGroupName,R_GOSIP_ADDUSER_EDWIN_TEXT);
    /*env->ReadResource( iPw, R_goSIPAddUserITEMDATA_MYPASSWORD );
    
    iIpAddress.SetAddress( INET_ADDR( KMinFldVal,
                                      KMinFldVal,
                                      KMinFldVal,
                                      KMinFldVal) );*/
    }

// End of File
