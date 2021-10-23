/*
* ============================================================================
*  Name        : EComImplementationProxy.h
*  Part of     : Common
*  Description : ECom 8.x compatibility definition
*  Version     : SIP/4.0
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
* ==============================================================================
*/
#ifndef __ECOMIMPLEMENTATIONPROXY_H__
#define __ECOMIMPLEMENTATIONPROXY_H__

// INCLUDES
#include <EComImplementationProxy.h>

// Disabled PC-Lint warning for "suspicious typecast" caused by Symbian's
// ECom declarations
/*lint -e611 */

// 8.x ECOM compatibility - EABI requires the use of IMPLEMENTATION_PROXY_ENTRY
// (i.e. define IMPLEMENTATION_PROXY_ENTRY locally on pre 8.x systems)
#ifndef IMPLEMENTATION_PROXY_ENTRY
#define IMPLEMENTATION_PROXY_ENTRY( aUid, aFuncPtr ) { { aUid }, aFuncPtr }
#endif

#endif // __ECOMIMPLEMENTATIONPROXY_H__
