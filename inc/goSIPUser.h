/*
============================================================================
 Name        : goSIPMediaShareAppEngine.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : goSIPMediaShareAppEngine.h - header file
============================================================================
*/

#ifndef GOSIPUSER_H
#define GOSIPUSER_H

// INCLUDES
// System Includes
//#include <e32base.h>  // CBase, link against euser.lib
// FORWARD DECLARATIONS
//class MyClass;

#include <e32std.h>
#include <s32strm.h>

/**
*  CgoSIPUser
* 
*/

class CgoSIPUser 
{
public: // Constructors and destructor

	/**
        * Destructor.
        */
	~CgoSIPUser();

    CgoSIPUser(const TDes& aName, const TDes& aSIPAddress);
    const TDes& GetName() const;
    const TDes& GetSIPAddress() const;
    void SetName(const TDes& aName);
    void SetSIPAddress(const TDes& aSIPAddress);

private:
	TBuf<256> iName;
    TBuf<256> iSIPAddress;

};

// CLASS DECLARATION

#if 0

/***************************************
* Include the appropriate headers here *
***************************************/

#define KgoSIPUserMaxNameLength (256)

typedef TUint TgoSIPUserId;

class CgoSIPUser : public CBase
{
private:
	CgoSIPUser(TgoSIPUserId aId, const TDesC& aName);
	void ConstructL(const CSIPAddress* aAddress);

public:
	static CgoSIPUser* NewLC(TgoSIPUserId aId, const TDesC& aName, const CSIPAddress* aAddress);
	static CgoSIPUser* NewL(TgoSIPUserId aId, const TDesC& aName, const CSIPAddress* aAddress);

public:
	virtual ~CgoSIPUser();

public:
	TgoSIPUserId& Id();
	const TgoSIPUserId& Id() const;
	TDesC& Name();
	const TDesC& Name() const;
	CSIPAddress* Address();
	const CSIPAddress* Address() const;

	void GetId(TgoSIPUserId& aId) const;
	void GetNameL(TDesC& aName) const;
	void GetAddress(CSIPAddress* aAddress) const;
	void SetId(const TgoSIPUserId& aId);
	void SetNameL(const TDesC& aName);
	void SetAddressL(const CSIPAddress* aAddress);

public:
	void InternalizeL(RReadStream& aStream);
	void ExternalizeL(RWriteStream& aStream) const;

private:
	TgoSIPUserId iId;
	TBufC<KgoSIPUserMaxNameLength> iName;
	CSIPAddress* iAddress;
};

#endif // #if 0

#endif // GOSIPUSER_H

// End of File
