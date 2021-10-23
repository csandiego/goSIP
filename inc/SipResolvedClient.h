/*
* ==============================================================================
*  Name        : SipResolvedClient.h
*  Part of     : ClientResolver
*  Description : See class definition below.
*  Version     : SIP/4.0
*
*  Copyright © 2004 Nokia Corporation.
*  This material, including documentation and any related
*  computer programs, is protected by copyright controlled by
*  Nokia Corporation. All rights are reserved. Copying,
*  including reproducing, storing, adapting or translating, any
*  or all of this material requires the prior written consent of
*  Nokia Corporation. This material also contains confidential
*  information which may not be disclosed to others without the
*  prior written consent of Nokia Corporation.
* ==============================================================================
*/
#ifndef __SIPRESOLVEDCLIENT_H__
#define __SIPRESOLVEDCLIENT_H__

// INCLUDES
#include <ecom/ecom.h>

// CONSTANTS
const TUid KSIPResolvedClientIFUid = { 0x102010dd };

// CLASS DEFINITION
/**
 * CSIPResolvedClient defines the interface for ECom SIP client launchers.
 * If the SIP client allows starting, it must implement 
 * the abstract functions StartL() and Name().
 * An example implementation for launching a .app by UID is provided below.
 *
 * @code
 * void CMyLauncher::StartL()
 *     {
 *     RApaLsSession session;
 *     User::LeaveIfError( session.Connect() );
 *     CleanupClosePushL( session );
 *
 *     TApaAppInfo appInfo;
 *     const TUid KMyApplicationUid = { 0x12345678 };
 *     User::LeaveIfError( session.GetAppInfo( appInfo, KMyApplicationUid ) );
 *
 *     CApaCommandLine* cmdLine = CApaCommandLine::NewLC();
 *     cmdLine->SetLibraryNameL( appInfo.iFullName );
 *     User::LeaveIfError( session.StartApp( *cmdLine ) );
 *     CleanupStack::PopAndDestroy( 2 ); // cmdLine, session
 *     }
 * @endcode
 */
class CSIPResolvedClient : public CBase
	{
	public:	// Destructor

		/**
		 * Destructor.
		 * Informs ECom framework that this specific instance
		 * of the interface has been destroyed.
		 */
		virtual inline ~CSIPResolvedClient();

	public: // Abstract methods

		/**
		 * Start a SIP client
		 */
		virtual inline void StartL();
		
		/**
		 * Get the localized name of the SIP client 
		 * to be shown to the end user.
		 * @returns SIP client's name
		 */
		virtual inline const TDesC& Name();

	public: // Data

		/// Unique key for implementations of this interface.
		TUid iInstanceKey;

	protected: // Default constructor:

		CSIPResolvedClient() {}
	};

#include "SipResolvedClient.inl"

#endif // __CSIPCLIENTLAUNCHERBASE_H__
