#include "goSIPSIPFunctionality.h"

CgoSIPSIPFunctionality* CgoSIPSIPFunctionality::NewL(TUid aUid)
    {
    CgoSIPSIPFunctionality* self = new( ELeave ) CgoSIPSIPFunctionality( aUid );
    //iUid = aUid;
    //CleanupStack::PushL(*this);
    CleanupStack::PushL( self );
    self->ConstructL();
    CleanupStack::Pop();
    return self;
    //return *this;
    }

void CgoSIPSIPFunctionality::ExecuteL()
    {
    // Initialize SIP Stack
    iSIP = CSIP::NewL(iUid, *this);
    // Initialize ProfileRegistry
    iProfileRegistry = CSIPProfileRegistry::NewL(*iSIP, *this);
    // Get the default profile.
    iProfile = iProfileRegistry->DefaultProfileL();
    // The client asks the API to enable the retrieved profile for its use.
    // For that, the client must inherit and implement MSIPConnectionObserver.
    TInt status = iProfileRegistry->EnableL(*iProfile, *this);
    // The returned status indicates if the profile can be immediately used
    // for creating a session, or if the client must wait for the profile to
    // be registered.
    if (status == KErrNone)
        {
        // get the SIP connection used by the profile
        iConnection = iProfileRegistry->ConnectionL(*iProfile);
        // create a SIP dialog for sending an INVITE;
        iSIPInviteDialogAssoc =
        CreateSIPInviteDialogAssoc();
        // Continue session establishement using the SIP Client API
        iSIPClientTransaction = iSIPInviteDialogAssoc->SendInviteL();
        }
    else //KErrPending
        {
        // wait for the profile to be registered before using it further
        }
    // Next look at
    // ProfileRegistrationStatusChanged(TUint32 aSIPProfileId)
    // method. Response for REGISTER request is handled there.
    }

/**
* Constructs CSIPInviteDialogAssoc object for test purposes.
* @return CSIPInviteDialogAssoc object
*/
CSIPInviteDialogAssoc* CgoSIPSIPFunctionality::CreateSIPInviteDialogAssoc()
    {
    // Construct toHeader. Note that we use possibly non-existing
    // opponent SIP Address.
    CSIPAddress* toAddress =
    CSIPAddress::DecodeL(_L8("sip:opponent@opponentdomain.com"));
    CleanupStack::PushL(toAddress);
    CSIPToHeader* toHeader = CSIPToHeader::NewL(toAddress);
    CleanupStack::Pop(toAddress);
    CleanupStack::PushL(toHeader);
    // and construct CSIPInviteDialogAssoc by using
    // from- and toHeaders:
    CSIPInviteDialogAssoc* inviteDialogAssoc =
    CSIPInviteDialogAssoc::NewL(
    *iConnection,
    toHeader,
    *iProfile );
    CleanupStack::Pop(toHeader);
    return inviteDialogAssoc;
    }

//MSIPProfileRegistryObserver implementation:
void CgoSIPSIPFunctionality::ProfileRegistrationStatusChanged(TUint32 aSIPProfileId)
    {
    // First inform User Interface that this method is being called
    User::InfoPrint(_L("ProfileRegistrationStatusChanged"));
    // Check that the changed profile is the same we use
    if (aSIPProfileId == iProfile->Id())
        {
        // Check that registration to the server was successful
        if ( iProfile->Status() == CSIPProfile::ERegistered)
            {
            // Get a connection object from ProfileRegistry.
            // Note: this can only be done after successful
            // registration.
            iConnection = iProfileRegistry->ConnectionL(*iProfile);
            // Continue this example application directly by
            // sending INVITE request.
            iSIPInviteDialogAssoc =
            CreateSIPInviteDialogAssoc();
            iSIPClientTransaction = iSIPInviteDialogAssoc->SendInviteL();
            }
        }
    }

CgoSIPSIPFunctionality::~CgoSIPSIPFunctionality()
    {
    delete iSIP;
    }

// MSIPConnectionObserver implementation
void CgoSIPSIPFunctionality::IncomingResponse (CSIPClientTransaction& aTransaction,CSIPDialogAssocBase& aDialogAssoc)
    {
    User::InfoPrint(_L("IncomingResponse"));
    // ACK is sent to any 2xx response
    if (aTransaction.ResponseElements()->StatusCode() >= 200 && aTransaction.ResponseElements()->StatusCode() < 300)
        {
        // Send ACK message:
        iSIPInviteDialogAssoc->SendAckL(aTransaction);
        }
    }
    // MSIPConnectionObserver implementation.
void CgoSIPSIPFunctionality::IncomingRequest (CSIPServerTransaction* aTransaction)
    {
    // handle incoming request by using SIP API.
    // CSIPRequestElements reqElem = aTransaction->RequestElements()
    // …
    }