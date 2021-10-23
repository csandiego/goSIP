/*
============================================================================
 Name        : CgoSIPPhonebookContainer from goSIPPhonebookContainer.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Container control implementation
============================================================================
*/

// INCLUDE FILES
#include "goSIPPhonebookContainer.h"
#include "goSIP.hrh"

#include <aknquerydialog.h>		//remove this if not needed
#include <aknnotewrappers.h>    //remove this if not needed
#include <cntdb.h>				//contact database
#include <cntitem.h>			//
#include <cntfldst.h>
#include <goSIP.rsg>
#include <aknlists.h>			//listbox 
#include <avkon.hrh>
#include <CPbkContactEngine.h>	//native nokia header file
#include <CPbkViewState.h>
#include <CPbkContactEditorDlg.h>
#include <CPbkContactItem.h>
#include <f32file.h>
#include <rpbkviewresourcefile.h>
#include <stringloader.h>

#include <eiklabel.h>  // for example label control


// ================= MEMBER FUNCTIONS =======================
// This PhonebookContainer will build a Double Line Listbox
// ---------------------------------------------------------
// CgoSIPPhonebookContainer::CgoSIPPhonebookContainer()
// constructor
// ---------------------------------------------------------
//
CgoSIPPhonebookContainer::CgoSIPPhonebookContainer()
	{
	iContactDb = NULL;
	iSelectedItemId = -1;
	}

// ---------------------------------------------------------
// CgoSIPPhonebookContainer::ConstructL(const TRect& aRect)
// EPOC two phased constructor
// ---------------------------------------------------------
//
void CgoSIPPhonebookContainer::ConstructL(const TRect& aRect)
    {
    CreateWindowL();
	// ------------------------------------------------------------------
	// Original Code for the Tab View1
	// ------------------------------------------------------------------
    //
	// iLabel = new (ELeave) CEikLabel;
    // iLabel->SetContainerWindowL( *this );
    // iLabel->SetTextL( _L("Example View") );

    // iToDoLabel = new (ELeave) CEikLabel;
    // iToDoLabel->SetContainerWindowL( *this );
    // iToDoLabel->SetTextL( _L("Add Your controls\n here") );

	iContactArray = new (ELeave) CDesCArrayFlat( KArraySize );
	iContactGroupArray = new (ELeave) CDesCArrayFlat( KArraySize );

	iListBox = new (ELeave) CAknDoubleStyleListBox;
	if( iListBox)
		{
		iListBox->ConstructL( NULL, EAknListBoxSelectionList);//NULL, EAknListBoxSelectionList );
		iListBox->Model()->SetItemTextArray( iContactArray );
		iListBox->CreateScrollBarFrameL();
		iListBox->Model()->SetOwnershipType( ELbmDoesNotOwnItemArray );
		iListBox->SetListBoxObserver( this );
		iListBox->HandleItemAdditionL();
		}
	SizeChanged();

    SetRect(aRect);

    ActivateL();
    }

// Destructor
CgoSIPPhonebookContainer::~CgoSIPPhonebookContainer()
	{
	if( iListBox )
		{
		delete iListBox;
		}
	if( iContactDb )
		{
		iContactDb->CloseTables();
		delete iContactDb;
		}
	if( iContactArray )
		{
		delete iContactArray;
		}
	if( iContactGroupArray) delete iContactGroupArray;
    //delete iLabel;
    //delete iToDoLabel;
    }

// ---------------------------------------------------------
// CgoSIPPhonebookContainer::SizeChanged()
// Called by framework when the view size is changed
// ---------------------------------------------------------
//
void CgoSIPPhonebookContainer::SizeChanged()
    {
    // TODO: Add here control resize code etc.
    //iLabel->SetExtent( TPoint(10,10), iLabel->MinimumSize() );
    //iToDoLabel->SetExtent( TPoint(10,100), iToDoLabel->MinimumSize() );
	iListBox->SetExtent( TPoint(0,45), iListBox->MinimumSize() );
	}

// ---------------------------------------------------------
// CgoSIPPhonebookContainer::CountComponentControls() const
// ---------------------------------------------------------
//
TInt CgoSIPPhonebookContainer::CountComponentControls() const
    {
    return 1; // return nbr of controls inside this container
	// since the listbox is the only control, then there's only one
	// control instance
    }

// ---------------------------------------------------------
// CgoSIPPhonebookContainer::ComponentControl(TInt aIndex) const
// ---------------------------------------------------------
//
CCoeControl* CgoSIPPhonebookContainer::ComponentControl(TInt aIndex) const
    {
    switch ( aIndex )
        {
		case 0: 
			if ( iListBox )
				{
				return iListBox;
				}
        //case 0:
        //    return iLabel;
        //case 1:
        //    return iToDoLabel;
        default:
            return NULL;
        }
    }

// ---------------------------------------------------------
// CgoSIPPhonebookContainer::Draw(const TRect& aRect) const
// ---------------------------------------------------------
//
void CgoSIPPhonebookContainer::Draw(const TRect& aRect) const
    {
    CWindowGc& gc = SystemGc();
    gc.SetPenStyle( CGraphicsContext::ENullPen );
    gc.SetBrushColor( KRgbWhite );
    gc.SetBrushStyle( CGraphicsContext::ESolidBrush );
    gc.DrawRect( aRect );
    }

// ----------------------------------------------------------------------------
// CgoSIPPhonebookContainer::OfferKeyEventL()
// Handles the key events.
// ----------------------------------------------------------------------------
//
TKeyResponse CgoSIPPhonebookContainer::OfferKeyEventL( const TKeyEvent& aKeyEvent,
                                              TEventCode aType )
	{
    if ( aType != EEventKey )
        { 
        return EKeyWasNotConsumed;
        }

	if ( aKeyEvent.iCode == EKeyDownArrow || aKeyEvent.iCode == EKeyUpArrow )
        {
        return iListBox->OfferKeyEventL( aKeyEvent, aType );
        }
	return EKeyWasNotConsumed;

    }

// ---------------------------------------------------------------------------
// CgoSIPPhonebookContainer::HandleListBoxEventL()
// Handles listboxevents.
// ---------------------------------------------------------------------------
//
void CgoSIPPhonebookContainer::HandleListBoxEventL( CEikListBox* /*aListBox*/,
    TListBoxEvent aEventType )
    {
    switch( aEventType )
        {
        case EEventEnterKeyPressed: // Flow through
        case EEventItemClicked:
            EditContactDlgL();
            break;
        default:
            break;
        }
    }

// ---------------------------------------------------------
// CgoSIPPhonebookContainer::HandleControlEventL(
//     CCoeControl* aControl,TCoeEvent aEventType)
// ---------------------------------------------------------
//
void CgoSIPPhonebookContainer::HandleControlEventL(
    CCoeControl* /*aControl*/,TCoeEvent /*aEventType*/)
    {
    // TODO: Add your control event handler code here
    }
void CgoSIPPhonebookContainer::HandleMarkCommandL( TInt cmd )
    {
    // TODO: Add your control event handler code here
		AknSelectionService::HandleMarkableListProcessCommandL(cmd,iListBox);
    }
// ---------------------------------------------------------
// CgoSIPPhonebookContainer::UpdateContactDbName()
// Store current database path and name.
// ---------------------------------------------------------
//
void CgoSIPPhonebookContainer::UpdateContactDbName( TDesC& aDbName )
    {
    iDbName = aDbName;
    }

// ---------------------------------------------------------
// CgoSIPPhonebookContainer::GetContactDbName()
// ---------------------------------------------------------
//
void CgoSIPPhonebookContainer::GetContactDbName( TDesC& aDbName, TPtr aCompleteDbName )
	{
    TBuf<KMaxDatabasePathAndNameLength> contactFile( KContactFile );
    contactFile.Append( aDbName );
    contactFile.Append( KPrefix );

    aCompleteDbName = contactFile;
	}


// ----------------------------------------------------
// CgoSIPPhonebookContainer::UpdateListBoxL()
// Updates listbox.
// ----------------------------------------------------
//
void CgoSIPPhonebookContainer::UpdateListBoxL()
    {
    iListBox->HandleItemAdditionL();
    iListBox->SetCurrentItemIndexAndDraw( 0 );
    SizeChanged();
    DrawNow();
    }

// ----------------------------------------------------
// CgoSIPPhonebookContainer::IsContactsOnListBox()
// The function returns state of the listbox.
// If contacts on the listbox has been selected
// the function returns ETrue.
// ----------------------------------------------------
//
TBool CgoSIPPhonebookContainer::IsContactsOnListBox()
    {
    CDesCArray* itemArray = (CDesCArray*) iListBox->Model()->ItemTextArray();

    if ( iContactArray == itemArray )
        {
	    return ETrue;
	    }

    return EFalse;
    }
// ----------------------------------------------------
// CgoSIPPhonebookContainer::ShowContactsL()
// Show contacts in the listbox.
// ----------------------------------------------------
//
void CgoSIPPhonebookContainer::ShowContactsL()
    {

    if ( !IfContactDbSelected() )
        {
        ShowInformationNoteNoDbL();
        return;
        }

    if ( IsContactsOnListBox() )
        {
        return;
        }

    iListBox->Model()->SetItemTextArray( iContactArray );
    iListBox->Model()->SetOwnershipType( ELbmDoesNotOwnItemArray );
    UpdateListBoxL();
    }

// ----------------------------------------------------
// CgoSIPPhonebookContainer::ShowContactGroupsL()
// Show contact groups in the listbox.
// ----------------------------------------------------
//
void CgoSIPPhonebookContainer::ShowContactGroupsL()
	{

    if ( !IfContactDbSelected() )
        {
        ShowInformationNoteNoDbL();
        return;
        }

    if ( !IsContactsOnListBox() )
	    {
	    return;
	    }

    iListBox->Model()->SetItemTextArray( iContactGroupArray );
    iListBox->Model()->SetOwnershipType( ELbmDoesNotOwnItemArray );
    UpdateListBoxL();
    }



// ----------------------------------------------------
// CgoSIPPhonebookContainer::ShowInformationNoteNoDbL()
// Show information not if contact database
// did not opened.
// ----------------------------------------------------
//
void CgoSIPPhonebookContainer::ShowInformationNoteNoDbL()
    {
    HBufC* textResource = StringLoader::LoadLC( R_GOSIP_PHONEBOOK_NO_DB_SELECTED );
    CAknInformationNote* informationNote = new( ELeave ) CAknInformationNote;
    informationNote->ExecuteLD( textResource->Des() );
    CleanupStack::PopAndDestroy( textResource );

    }
// ----------------------------------------------------
// CgoSIPPhonebookContainer::IfContactDbSelected()
// The function checks is contact database
// has been opened.
// ----------------------------------------------------
//
TBool CgoSIPPhonebookContainer::IfContactDbSelected()
    {

    if ( iContactDb )
	    {
	    return ETrue;
	    }

    return EFalse;
    }

// ---------------------------------------------------------
// CgoSIPPhonebookContainer::DeleteContactDatabaseL()
// ---------------------------------------------------------
//
void CgoSIPPhonebookContainer::DeleteContactDatabaseL( TDesC& aDbName )
    {

    HBufC* contactFile = HBufC::NewLC( KMaxDatabasePathAndNameLength );
    TPtr ptr( contactFile->Des() );

    // Resolve path for contact database file
    GetContactDbName( aDbName, ptr );

    // Check if database opened
    if ( iContactDb && ( !iDbName.Compare( contactFile->Des() ) ) )
        {
        iContactDb->CloseTables();
        delete iContactDb;
        iContactDb = NULL;

        TBuf<15> noContactFile( KNullDesC );
        UpdateContactDbName( noContactFile );
        }

    // Try remove db
    if ( iCoeEnv->FsSession ().IsValidName( contactFile->Des() ) )
        {
        TInt errCode( iCoeEnv->FsSession().Delete( contactFile->Des() ) );
        if ( errCode != KErrNone )
            {
            HBufC* text = StringLoader::LoadLC( R_GOSIP_PHONEBOOK_CANNOT_DELETE_DB );
            CAknInformationNote* informationNote = new (ELeave) CAknInformationNote;
            informationNote->ExecuteLD( *text );
            CleanupStack::PopAndDestroy( text );
            }
        }

    CleanupStack::PopAndDestroy( contactFile );

    // Update iContactArray and iContactGroupArray
    ReadContactsFromDbL();
    UpdateListBoxL();
    }

// ----------------------------------------------------------------------------
// CgoSIPPhonebookContainer::OpenDefaultDatabaseL()
// Open default contact database.
// Database is same as what Phonebook uses.
// ----------------------------------------------------------------------------
//
void CgoSIPPhonebookContainer::OpenDefaultDatabaseL()
    {
    // Read name of the default database
    _LIT( KOrgContactFile,"" );
    TBuf<KMaxDatabasePathAndNameLength> orgContactFile( KOrgContactFile );
    CContactDatabase::GetDefaultNameL( orgContactFile );
    orgContactFile.LowerCase();

    if ( iContactDb )
        {
        if ( !iDbName.Compare( orgContactFile ) )
            {
            return;
            }
        iContactDb->CloseTables();
        delete iContactDb;
        iContactDb = NULL;
        }

    TRAPD(err, iContactDb = CContactDatabase::OpenL( orgContactFile ););
    // Check if database already exist
    if ( err == KErrNotFound )
        {

        HBufC* text = StringLoader::LoadLC( R_GOSIP_PHONEBOOK_DB_NOT_FOUND );
        CAknInformationNote* informationNote = new (ELeave) CAknInformationNote;
        informationNote->ExecuteLD( *text );
        CleanupStack::PopAndDestroy( text );
        iContactDb = NULL;
        ReadContactsFromDbL();// Update iContactArray and iContactGroupArray

        TBuf<15> noContactFile( KNullDesC );
        UpdateContactDbName( noContactFile );

        UpdateListBoxL();
        }
    else
        {
        // Update iContactArray and iContactGroupArray
        ReadContactsFromDbL();
        UpdateContactDbName( orgContactFile ); //This is the method that opens the default phone directory
        UpdateListBoxL();
        }
    }

// ----------------------------------------------------
// CgoSIPPhonebookContainer::EditContactDlgL()
// Opens CPbkContactEditorDlg for contact.
// ----------------------------------------------------
//
void CgoSIPPhonebookContainer::EditContactDlgL()
    {
    if ( !IfContactDbSelected() )
        {
        ShowInformationNoteNoDbL();
        return;
        }

    // Check if contacts list on the list box
    if ( !IsContactsOnListBox() )
        {
        return;
        }

    // The caller does not take ownership of this object.
    // so do not push it onto the CleanupStack.
    const CContactIdArray* contacts = iContactDb->SortedItemsL();

    TInt currentItemIndex( iListBox->CurrentItemIndex() );
    TInt count( iContactArray->Count() );
    if ( currentItemIndex < 0 || currentItemIndex >= count )
        {
        HBufC* textResource = StringLoader::LoadLC( R_GOSIP_PHONEBOOK_NO_CONTACT_SELECTED );
        CAknInformationNote* informationNote = new( ELeave ) CAknInformationNote;
        informationNote->ExecuteLD( textResource->Des() );
        CleanupStack::PopAndDestroy( textResource );
	    return;
        }

    TContactItemId itemId( ((*contacts)[currentItemIndex]) );

    CPbkContactEngine* pbkContactEng =
                    CPbkContactEngine::NewL(iDbName,
                                            EFalse,
                                            &iCoeEnv->FsSession());
    CleanupStack::PushL( pbkContactEng );
    // load the contacts dialog resources
    CCoeEnv *env = CEikonEnv::Static();
    RPbkViewResourceFile pbkRes( *env );
    pbkRes.OpenL();

    CPbkContactItem* aContactItem = pbkContactEng->OpenContactL( itemId );
    CleanupStack::PushL( aContactItem );
	
    // Open the contacts dialog
    // third parameter: set to true if aContactItem is a
    // new contact (not yet in the database)
    // fourth parameter index of field to focus initially
    // fifth paramter if true sets the contact initially as "edited".
    CPbkContactEditorDlg* pbkContactDlg =
                    CPbkContactEditorDlg::NewL( *pbkContactEng,
                                                *aContactItem,
                                                EFalse, -1,
                                                EFalse );

    CleanupStack::PushL( pbkContactDlg );
    pbkContactDlg->SetMopParent( iAvkonAppUi );

    TInt res( KErrNone );
    TRAPD( err, res = pbkContactDlg->ExecuteLD() );

    pbkRes.Close();
    pbkContactEng->CloseContactL( aContactItem->Id() );

    CleanupStack::Pop( pbkContactDlg );
    CleanupStack::PopAndDestroy( 2 ); //aContactItem, pbkContactEng

    // Update iContactArray and iContactGroupArray
    ReadContactsFromDbL();
    UpdateListBoxL();
    }

// ----------------------------------------------------
// CgoSIPPhonebookContainer::GetSelectedContactL()
// Set selected contact's item id to
// variable and changes listbox data to contact groups.
// ----------------------------------------------------
//
void CgoSIPPhonebookContainer::GetSelectedContactL()
    {
    if ( !IfContactDbSelected() )
        {
        ShowInformationNoteNoDbL();
        return;
        }

    if ( !IsContactsOnListBox() )
        {
	    return;
        }

    iContactDb->SetDbViewContactType( KUidContactCard );
    // The caller does not take ownership of this object.
    // so do not push it onto the CleanupStack
    const CContactIdArray* contacts = iContactDb->SortedItemsL();

    TInt currentItemIndex( iListBox->CurrentItemIndex() );
    TInt count( iContactArray->Count() );
    if ( currentItemIndex < 0 || currentItemIndex >= count )
        {
	    return;
        }

    iSelectedItemId = ((*contacts)[currentItemIndex]);

    ShowContactGroupsL();
    }

// ----------------------------------------------------
// CgoSIPPhonebookContainer::AddContactToGrp()
// Add selected contact to contact group.
// ----------------------------------------------------

void CgoSIPPhonebookContainer::AddContactToGrpL()
    {
    if ( !IfContactDbSelected() )
        {
        ShowInformationNoteNoDbL();
        return;
        }

    if ( iSelectedItemId == -1 )
	    {
	    return;
	    }

    TInt currentItemIndex( iListBox->CurrentItemIndex() );
    TInt count( iContactGroupArray->Count() );
    if ( currentItemIndex < 0 || currentItemIndex >= count )
        {
        return;
        }

    // The caller takes ownership of the returned object.
    // groupIdList is NULL if there are no groups in the database.
    CContactIdArray* groupIdList = iContactDb->GetGroupIdListL();
    if ( !groupIdList )
        {
	    return;
        }

    CleanupStack::PushL( groupIdList );

    TContactItemId groupItemId = ((*groupIdList)[currentItemIndex]);
    iContactDb->AddContactToGroupL( iSelectedItemId , groupItemId );

    iSelectedItemId = -1;

    CleanupStack::PopAndDestroy( groupIdList );
    }
// ----------------------------------------------------
// CgoSIPPhonebookContainer::AddNewContactDlg()
// Open CPbkContactEditorDlg dialog
// for new contact item.
// ----------------------------------------------------
//
void CgoSIPPhonebookContainer::AddNewContactDlgL()
    {

    if ( !IfContactDbSelected() )
        {
        ShowInformationNoteNoDbL();
        return;
        }

    if ( !IsContactsOnListBox() )
        {
        return;
        }

    //Creates a new Phonebook engine object and connect
    //to the contact database. If the database
    //does not exist it is created.
    CPbkContactEngine* pbkContactEng =
                    CPbkContactEngine::NewL( iDbName,
                                             EFalse,
                                             &iCoeEnv->FsSession() );
    // Put object to the stack
    CleanupStack::PushL( pbkContactEng );

    // load the contacts dialog resources
    CCoeEnv *env = CEikonEnv::Static();
    RPbkViewResourceFile pbkRes( *env );
    pbkRes.OpenL();

    //create a new empty contact
    // The caller takes ownership of this object.
    // so push it onto the CleanupStack
    CPbkContactItem* aContactItem = pbkContactEng->CreateEmptyContactL();
    CleanupStack::PushL( aContactItem );

    // launch the contact dialog
    CPbkContactEditorDlg* pbkContactDlg =
                CPbkContactEditorDlg::NewL( *pbkContactEng,
                                            *aContactItem,
                                            ETrue, -1,
                                            ETrue );

    CleanupStack::PushL( pbkContactDlg );

    pbkContactDlg->SetMopParent( iAvkonAppUi );

    TInt res( KErrNone );

    // Show contact dialog
    TRAPD( err, res = pbkContactDlg->ExecuteLD() );

    pbkRes.Close();

    CleanupStack::Pop( pbkContactDlg );
    CleanupStack::PopAndDestroy( 2 ); //aContactItem, pbkContactEng

    // Update internal database connection
    iContactDb->CloseTables();
    delete iContactDb;
    iContactDb = CContactDatabase::OpenL( iDbName );

    // Update iContactArray and iContactGroupArray
    ReadContactsFromDbL();
    // Update display
    UpdateListBoxL();
    }

// ---------------------------------------------------------
// CgoSIPPhonebookContainer::ReadContactsFromDbL()
// Read contacts from contact database
// and sort contacts by Family Name and
// Given Name and Phone Number.
// Add sorted items to iContactArray.
// ---------------------------------------------------------
//
void CgoSIPPhonebookContainer::ReadContactsFromDbL()
    {
    ReadContactGroupsFromDbL();
	
    // Delete old contact from listbox
    TInt count( iContactArray->Count() );
    if ( count )
        {
        // Clear array. Start to index 0
	    iContactArray->Delete( 0, count );
        }

    if ( !IfContactDbSelected() )
        {
	    return;
        }

    iContactDb->SetDbViewContactType( KUidContactCard );

    TFieldType aFieldType1( KUidContactFieldFamilyName );
    TFieldType aFieldType2( KUidContactFieldGivenName );
	//TFieldType aFieldType3( KUidContactFieldPhoneNumber );
    CContactDatabase::TSortPref sortPref1( aFieldType1 );
    CContactDatabase::TSortPref sortPref2( aFieldType2 );
	//CContactDatabase::TSortPref sortPref2( aFieldType3 );
    // Sort contacts by Family and Given Name
    CArrayFixFlat<CContactDatabase::TSortPref>* aSortOrder =
                    new (ELeave) CArrayFixFlat<CContactDatabase::TSortPref>(2);

    CleanupStack::PushL( aSortOrder );
    aSortOrder->AppendL( sortPref1 );
    aSortOrder->AppendL( sortPref2 );

    // The database takes ownership of the sort order array passed in
    iContactDb->SortL( aSortOrder );

    // The caller does not take ownership of this object.
    // so do not push it onto the CleanupStack
    const CContactIdArray* contacts = iContactDb->SortedItemsL();

	
    // Go through each contact item and
    // make items for listbox
    const TInt nc( contacts->Count() );

    for ( TInt i( nc-1 ); i >= 0; i-- ) //For each ContactId
        {
        CContactItem* contact = NULL;
        // The caller takes ownership of the returned object.
        // So push it onto the CleanupStack
        contact = iContactDb->OpenContactL( (*contacts)[i] );
        CleanupStack::PushL( contact );

        CContactItemFieldSet& fieldSet = contact->CardFields();

        HBufC* firstNameBuf = NULL;
        HBufC* lastNameBuf = NULL;
		HBufC* numberBuf = NULL;

        // Get first name
        TInt findpos( fieldSet.Find( KUidContactFieldGivenName ) );

        // Check that the first name field is actually there.
        if ( (findpos > -1) || (findpos >= fieldSet.Count()) )
            {
            CContactItemField& firstNameField = fieldSet[findpos];
            CContactTextField* firstName = firstNameField.TextStorage();
            firstNameBuf = firstName->Text().AllocLC();
            }

	    // Get last name
        findpos = fieldSet.Find( KUidContactFieldFamilyName );

		// Check that the last name field is actually there.
        if ( (findpos > -1) || (findpos >= fieldSet.Count()) )
            {
            CContactItemField& lastNameField = fieldSet[ findpos ];
            CContactTextField* lastName = lastNameField.TextStorage();
            lastNameBuf = lastName->Text().AllocLC();
            }


		//get default number
	   findpos = fieldSet.Find( KUidContactFieldPhoneNumber );

	   if ( (findpos > -1) || (findpos >= fieldSet.Count()) )
            {
            CContactItemField& numberField = fieldSet[ findpos ];
			CContactTextField* number = numberField.TextStorage();
			numberBuf = number->Text().AllocLC();
            }

        TInt len( 0 );
		TInt len2( 0 );
        if ( firstNameBuf )
            {
            len+=firstNameBuf->Length();
            }

        if ( lastNameBuf )
            {
            len+=lastNameBuf->Length();
            }
		if ( numberBuf )
            {
			//len2 = len +numberBuf->Length();
            len += numberBuf->Length();
            }
	    // Create new buffer and add space for formatters
	    HBufC* combinedDes = HBufC::NewLC( len + KFormattersSpace );
		
		if ( ( firstNameBuf ) && ( lastNameBuf ) && numberBuf ) {
			_LIT(newformat,"\t%S %S\t%S");
			combinedDes->Des().Format( newformat,
									   firstNameBuf,
                                       lastNameBuf,
									   numberBuf);
		}
		else if ( numberBuf ) {
			_LIT(newformat,"\t%S\t%S");
			if(firstNameBuf) {
				combinedDes->Des().Format( newformat,
                                       firstNameBuf,
									   numberBuf);
			} else if (lastNameBuf) {
				combinedDes->Des().Format( newformat,
                                       lastNameBuf,
                                       numberBuf);
			} else
				{
				combinedDes->Des().Format(KListOItemFormatter, numberBuf );
				}
		}
        else if ( ( firstNameBuf ) && ( lastNameBuf ) )
            {
            combinedDes->Des().Format( KListItemFormatter,
                                       lastNameBuf,
                                       firstNameBuf );
            }
        else
            {
            if ( firstNameBuf )
                {
                combinedDes->Des().Format( KListOItemFormatter, firstNameBuf );
                }
            else if ( lastNameBuf )
                {
                combinedDes->Des().Format( KListOItemFormatter, lastNameBuf );
                }
			
			}
        // Insert a contacts name into the array at the specified position.
        // If the specified position is the same as the current number of
        // descriptor elements in the array, this has the effect of
        // appending the element.
		iContactArray->InsertL( 0, *combinedDes );
		CleanupStack::PopAndDestroy( combinedDes );
		if ( numberBuf )
            {
            CleanupStack::PopAndDestroy( numberBuf );
            }
        if ( lastNameBuf )
            {
            CleanupStack::PopAndDestroy( lastNameBuf );
            }

        if ( firstNameBuf )
            {
            CleanupStack::PopAndDestroy( firstNameBuf );
            }

        iContactDb->CloseContactL( contact->Id() );
        CleanupStack::PopAndDestroy( contact );

        }

    CleanupStack::Pop( aSortOrder );
    }

// ---------------------------------------------------------
// CgoSIPPhonebookContainer::ReadContactGroupsFromDbL()
// Read contact groups from contact database.
// Do not sort contact groups. Add group items
// to iContactGroupArray.
// ---------------------------------------------------------
//
void CgoSIPPhonebookContainer::ReadContactGroupsFromDbL()
    {
    TInt count( iContactGroupArray->Count() );
    if ( count )
        {
        // Clear array. Start to index 0
        iContactGroupArray->Delete( 0, count );
        }
    if ( !IfContactDbSelected() )
        {
        return;
        }

	//The caller takes ownership of the returned object.
    // groupIdList is NULL if there are no groups in the database.
    CContactIdArray* groupIdList = iContactDb->GetGroupIdListL();
    if( !groupIdList )
        {
        return;
        }

    CleanupStack::PushL( groupIdList );

    CContactGroup* contactGroup = NULL;
    const TInt nc( groupIdList->Count() );
    for ( TInt i( nc-1 ); i >= 0; i-- ) //For each Contact Group Id
        {
        CContactItem* contact=NULL;

        // The caller takes ownership of the returned object.
        // So push it onto the CleanupStack
        contact = iContactDb->OpenContactL( ((*groupIdList)[i]) );
        CleanupStack::PushL( contact );

        contactGroup = (CContactGroup*) contact;
        TInt len( contactGroup->GetGroupLabelL().Length() );
        HBufC* groupLabelBuf = HBufC::NewLC( len + KFormattersSpace );
        HBufC* combinedDes = HBufC::NewLC( len + KFormattersSpace );

        *groupLabelBuf = contactGroup->GetGroupLabelL();
        combinedDes->Des().Format( KListOItemFormatter, groupLabelBuf );

        // Insert a group name into the array at the specified position.
        // If the specified position is the same as the current number of
        // descriptor elements in the array, this has the effect of
        // appending the element.
        iContactGroupArray->InsertL( 0, *combinedDes );

	    CleanupStack::PopAndDestroy( combinedDes );
	    CleanupStack::PopAndDestroy( groupLabelBuf );

	    iContactDb->CloseContactL( contact->Id() );
	    CleanupStack::PopAndDestroy( contact );
	    }

    CleanupStack::PopAndDestroy( groupIdList );
    }


// ---------------------------------------------------------
// CgoSIPPhonebookContainer::DatabaseExists()
// Check if contact database is created.
// ---------------------------------------------------------
//
TBool CgoSIPPhonebookContainer::DatabaseExists( TDesC& aDbName )
    {

	HBufC* contactFile = HBufC::NewLC( KMaxDatabasePathAndNameLength );
    TPtr ptr( contactFile->Des() );

    // Resolve path for contact database file
    GetContactDbName( aDbName, ptr );

	CContactDatabase* contactDb = NULL;
	TBool retValue = ETrue;
	TRAPD(err, contactDb = CContactDatabase::OpenL( contactFile->Des() ););
    // Check if database already exist
    if ( err == KErrNotFound )
        {
		retValue = EFalse;
		}
	else
		{
		contactDb->CloseTables();
		delete contactDb;
		}

	CleanupStack::PopAndDestroy( contactFile );
	return retValue;
	}