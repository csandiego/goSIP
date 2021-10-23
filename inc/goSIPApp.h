/*
============================================================================
 Name        : CgoSIPApp from goSIPApp.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Declares main application class.
============================================================================
*/

#ifndef GOSIPAPP_H
#define GOSIPAPP_H

// INCLUDES
#include <aknapp.h>

// CONSTANTS
// UID of the application
const TUid KUidgoSIP = { 0x06e4f6d4 };

// CLASS DECLARATION

/**
* CgoSIPApp application class.
* Provides factory to create concrete document object.
* 
*/
class CgoSIPApp : public CAknApplication
    {
    
    public: // Functions from base classes
    private:

        /**
        * From CApaApplication, creates CgoSIPDocument document object.
        * @return A pointer to the created document object.
        */
        CApaDocument* CreateDocumentL();
        
        /**
        * From CApaApplication, returns application's UID (KUidgoSIP).
        * @return The value of KUidgoSIP.
        */
        TUid AppDllUid() const;
    };

#endif



