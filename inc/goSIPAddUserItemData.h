
#ifndef __GOSIPADDUSERITEMDATA_H__
#define __GOSIPADDUSERITEMDATA_H__


// INCLUDES
#include <e32base.h>


// CONSTANTS
const TInt KSettingAppMaxSettingTextSize = 50;
const TInt KMinFldVal = 20;


// FORWARD DECLARATIONS
class CSharedDataI;


// CLASS DECLARATION

/**
* CgoSIPAddUserItemData 
*/
class CgoSIPAddUserItemData : public CBase
    {

    public: // Constructors and destructor

        /**
        * NewL.
        * Two-phased constructor.
        * Using two phase construction,and return a pointer to the created object
        * @return a pointer to the created instance of CgoSIPAddUserItemData
        */
        static CgoSIPAddUserItemData* NewL();

        /**
        * ~CgoSIPAddUserItemData.
        * Virtual Destructor.
        */
        virtual ~CgoSIPAddUserItemData();


    private:    // Constructors and destructor

        /**
        * CgoSIPAddUserItemData.
        * C++ default constructor.
        */
        CgoSIPAddUserItemData();

        /**
        * ConstructL.
        * 2nd phase constructor.
        */
        void ConstructL();

    public: // Data
        // AddUser variables
        TBuf<KSettingAppMaxSettingTextSize> iSIPAddress;
		TBuf<KSettingAppMaxSettingTextSize> iGroupName;
        /*// Integer type members 
		TInt iVolume;
        TInt iSliderValue;
        TInt iLanguageCode;
        TInt iFepLanguageCode;

        TInetAddr iIpAddress;

        // Boolean type members 
        TBool iFepEnabled;
        TBool iBinary;


        TBuf<KSettingAppMaxPasswordTextSize> iPw;
        TBuf<KSettingAppMaxPasswordTextSize> iPin;*/
    };

#endif
