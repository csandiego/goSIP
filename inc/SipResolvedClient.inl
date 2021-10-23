/*
* =============================================================================
*  Name          : SipResolvedClient.inl
*  Part of       : SipClientResolver
*  Description   : 
*  Version       : SIP/4.0 
*
*  Copyright (c) 2004 Nokia Corporation. 
*  This material, including documentation and any related 
*  computer programs, is protected by copyright controlled by 
*  Nokia Corporation. All rights are reserved. Copying, 
*  including reproducing, storing, adapting or translating, any 
*  or all of this material requires the prior written consent of 
*  Nokia Corporation. This material also contains confidential 
*  information which may not be disclosed to others without the 
*  prior written consent of Nokia Corporation. 
* =============================================================================
*/
#ifndef __SIPRESOLVEDCLIENT_INL__
#define __SIPRESOLVEDCLIENT_INL__

// ---------------------------------------------------------------------------
// CSIPResolvedClient::~CSIPResolvedClient 
// ---------------------------------------------------------------------------
//
inline CSIPResolvedClient::~CSIPResolvedClient()
	{
	REComSession::DestroyedImplementation( iInstanceKey );
	}

// ---------------------------------------------------------------------------
// CSIPResolvedClient::StartL
// ---------------------------------------------------------------------------
//
inline void CSIPResolvedClient::StartL() 
	{
	User::Leave( KErrNotSupported );
	}

// ---------------------------------------------------------------------------
// CSIPResolvedClient::Name
// ---------------------------------------------------------------------------
//
inline const TDesC& CSIPResolvedClient::Name() 
	{
	return KNullDesC;
	}

#endif // end of __SIPRESOLVEDCLIENT_INL__

// End of File
