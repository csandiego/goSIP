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
#include "goSIPUser.h"

CgoSIPUser::~CgoSIPUser()
{
}

CgoSIPUser::CgoSIPUser(const TDes& aName, const TDes& aSIPAddress)
    {
        iName.Copy(aName);
        iSIPAddress.Copy(aSIPAddress);

    }

const TDes& CgoSIPUser::GetName() const
{
	return iName;
}

const TDes& CgoSIPUser::GetSIPAddress() const
    {
    return iSIPAddress;
    }
    
void CgoSIPUser::SetName(const TDes& aName)
{
    iName.Copy(aName);
}

void CgoSIPUser::SetSIPAddress(const TDes& aSIPAddress)
    {
    iSIPAddress.Copy(aSIPAddress);
    }


// ================= MEMBER FUNCTIONS =======================

// End of File
