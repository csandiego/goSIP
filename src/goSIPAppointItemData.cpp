
// INCLUDE FILES
#include <eikenv.h>
#include <in_sock.h>
#include <goSIP.rsg>
#include "goSIPAppointItemData.h"



// ========================= MEMBER FUNCTIONS ==================================

// -----------------------------------------------------------------------------
// CgoSIPAppointItemData::NewL()
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
CgoSIPAppointItemData* CgoSIPAppointItemData::NewL()
    {
    CgoSIPAppointItemData* data = new( ELeave ) CgoSIPAppointItemData;
    CleanupStack::PushL(data);
    data->ConstructL();
    CleanupStack::Pop();
    return data;
    }


// -----------------------------------------------------------------------------
// CgoSIPAppointItemData::~CgoSIPAppointItemData()
// Destructor.
// -----------------------------------------------------------------------------
//
CgoSIPAppointItemData::~CgoSIPAppointItemData()
    {
    // No implementation required
    }


// -----------------------------------------------------------------------------
// CgoSIPAppointItemData::CgoSIPAppointItemData()
// C++ default constructor can NOT contain any code, that might leave.
// -----------------------------------------------------------------------------
//
CgoSIPAppointItemData::CgoSIPAppointItemData() /*: iVolume( 5 )*/
    {
    // No implementation required
    }


// ------------------------------------------------------------------------------
// CgoSIPAppointItemData::ConstructL()
// Symbian 2nd phase constructor can leave.
// ------------------------------------------------------------------------------
//
void CgoSIPAppointItemData::ConstructL()
    {

    //Sets the initial value of the iTextBuf
	CEikonEnv* env = CEikonEnv::Static();
    env->ReadResource( iSubject,R_GOSIP_APPOINT_EDWIN_TEXT);

    iTime.HomeTime();
    iDate.HomeTime();

    /*env->ReadResource( iPw, R_goSIPAppointITEMDATA_MYPASSWORD );
    
    iIpAddress.SetAddress( INET_ADDR( KMinFldVal,
                                      KMinFldVal,
                                      KMinFldVal,
                                      KMinFldVal) );*/
    }

// End of File
