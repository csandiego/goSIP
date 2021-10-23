#ifndef GOSIPGROUP_H
#define GOSIPGROUP_H

#include "goSIPUser.h"
/*
Include approriate headers here
*/

#define KgoSIPGroupMaxNameLength (256)

typedef TUint TgoSIPGroupId;

class TgoSIPGroup
{
public:
	TgoSIPGroup(TgoSIPGroupId aId, const TDesC& aName);
	~TgoSIPGroup();

public:
	TgoSIPGroupId& Id();
	const TgoSIPGroupId& Id() const;
	TDesC& Name();
	const TDesC& Name() const;
	RPointerArray<CgoSIPUser>& Members();
	const RPointerArray<CgoSIPUser>& Members() const;

	void GetId(TgoSIPGroupId& aId) const;
	void GetNameL(TDesC& aName) const;
	void GetMembersL(RPointerArray<CgoSIPUser>& aMembers) const;
	void SetId(const TgoSIPGroupId& aId);
	void SetNameL(const TDesC& aName);
	void SetMembersL(const RPointerArray<CgoSIPUser>& aMembers);

public:
	static void LoadL(RPointerArray<TgoSIPGroup> aGroups, RPointerArray<CgoSIPUser> aUsers);
	static void SaveL(RPointerArray<TgoSIPGroup> aGroups);

public:
	void InternalizeL(RReadStream& aStream);
	void ExternalizeL(RWriteStream& aStream) const;

private:
	TgoSIPGroupId iId;
	TBufC<KgoSIPGroupMaxNameLength> iName;
	RPointerArray<CgoSIPUser> iMembers;
};

#endif // GOSIPGROUP_H