#include <SIPProfileRegistryObserver.h>
#include <SIPObserver.h>
#include <SIPConnectionObserver.h>
#include <SIP.h>
#include <SipProfileRegistry.h>
#include <SipProfileRegistry.h>
#include <SIPProfile.h>
#include <SIPConnection.h>
#include <SIPInviteDialogAssoc.h>
#include <SIPFromHeader.h>
#include <SIPToHeader.h>
#include <SIPContactHeader.h>
#include <SIPAddress.h>
#include <SIPClientTransaction.h>
#include <SIPResponseElements.h>
#include <SIPRequestElements.h>

class CSIPProfileRegistryObserver;
class CSIPObserver;
class CSIPConnectionObserver;
class CSIP;
class CSipProfileRegistry;
class CSipProfileRegistry;
class CSIPProfile;
class CSIPConnection;
class CSIPInviteDialogAssoc;
class CSIPFromHeader;
class CSIPToHeader;
class CSIPContactHeader;
class CSIPAddress;
class CSIPClientTransaction;
class CSIPResponseElements;
class CSIPRequestElements;
class CSIPResolvedClient;

class CgoSIPSIPFunctionality:
    public CBase,
    public MSIPProfileRegistryObserver,
    public MSIPObserver,
    public MSIPConnectionObserver
    {
    public:
        static CgoSIPSIPFunctionality* NewL(TUid aUid);
        // MSIPProfileRegistryObserver implementation.
        // Move to cpp-file if further implementation.
        void ProfileCreated(TUint32 /*aSIPProfileId*/){}
        void ProfileUpdated(TUint32 /*aSIPProfileId*/){}
        void ProfileDestroyed(TUint32 /*aSIPProfileId*/){}
        void ProfileRegistryErrorOccurred(
            TUint32 /*aSIPProfileId*/,TInt /*aError*/){}
        // MSIPObserver implementation.
        // Move to cpp-file if further implementation.
        void IncomingRequest(
            TUint32 /*aIapId*/, CSIPServerTransaction* /*aTransaction*/){}
        virtual void TimedOut(
            CSIPServerTransaction& /*aSIPServerTransaction*/){}
        // MSIPConnectionObserver implementation.
        // Move to cpp-file if further implementation.
        void IncomingRequest (
            CSIPServerTransaction* /*aTransaction*/,
            CSIPDialog& /*aDialog*/){}
        void IncomingResponse (
            CSIPClientTransaction& /*aTransaction*/){}
        void IncomingResponse (
            CSIPClientTransaction& /*aTransaction*/,
            CSIPInviteDialogAssoc* /*aDialogAssoc*/){}
        void IncomingResponse (
            CSIPClientTransaction& /*aTransaction*/,
            CSIPRegistration& /*aRegistration*/){}
        void ErrorOccured (
            TInt /*aError*/,
            CSIPTransactionBase& /*aTransaction*/){}
        void ErrorOccured (
            TInt /*aError*/,
            CSIPClientTransaction& /*aTransaction*/,
            CSIPRegistration& /*aRegistration*/){}
        void ErrorOccured (
            TInt /*aError*/,
            CSIPTransactionBase& /*aTransaction*/,
            CSIPDialogAssocBase& /*aDialogAssoc*/){}
        void ErrorOccured (
            TInt /*aError*/,
            CSIPRefresh& /*aSIPRefresh*/){}
        void ErrorOccured (
            TInt /*aError*/,
            CSIPRegistration& /*aRegistration*/){}
        void ErrorOccured (
            TInt /*aError*/,
            CSIPDialogAssocBase& /*aDialogAssoc*/){}
        void InviteCompleted (
            CSIPClientTransaction& /*aTransaction*/){}
        void ConnectionStateChanged (
            CSIPConnection::TState /*aState*/){}
    public:
        CgoSIPSIPFunctionality(TUid& aUid){iUid = aUid;}
        ~CgoSIPSIPFunctionality();
        void ConstructL();
        void ExecuteL();
        CSIP* iSIP;
        CSIPProfileRegistry* iProfileRegistry;
        CSIPProfile* iProfile;
        CSIPConnection* iConnection;
        TUid iUid;
        CSIPClientTransaction* iSIPClientTransaction;
        CSIPInviteDialogAssoc* iSIPInviteDialogAssoc;
        CSIPInviteDialogAssoc* CreateSIPInviteDialogAssoc();
        void IncomingRequest (CSIPServerTransaction*);
        void ProfileRegistrationStatusChanged(TUint32);
        void IncomingResponse(CSIPClientTransaction&,CSIPDialogAssocBase&);
};