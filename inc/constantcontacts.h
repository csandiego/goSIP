#ifndef __CONTACTSCONSTANTS_H__
#define __CONTACTSCONSTANTS_H__

// CONSTANTS

const TInt KMaxDatabaseNameLength = 12;
// Max database path length (c:\\system\\data\\contacts.cdb)
const TInt KMaxDatabasePathAndNameLength = 60;
const TInt KMaxTemplateNameLength = 20;
const TInt KMaxTextLength = 19;
const TInt KMaxGroupNameLength = 20;
const TInt KArraySize = 4;
const TInt KFormattersSpace = 10;
const TInt KMaxTextBoxQueryLength = 40;
_LIT( KContactFile,"c:\\system\\data\\" );
_LIT( KPrefix,".cdb" );
_LIT( KCDbName,"ContactsA" );
_LIT( KFirstName,"FirstName") ;
_LIT( KLastName,"LastName" );
_LIT( KPhoneNumber,"123123123" );

// CAknSingleStyleListBox needs next formatters
_LIT(KListItemFormatter,"\t%S %S\t\t"); //
_LIT(KListOItemFormatter,"\t%S\t\t");   //

//with icons
_LIT(KListItemFormatter2,"%d\t%S %S\t\t");
_LIT(KListOItemFormatter2,"%d\t%S\t\t"); 

#endif // __CONTACTSCONSTANTS_H__
