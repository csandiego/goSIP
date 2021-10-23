
#ifndef __GOSIPAPPOINTITEMDATA_H__
#define __GOSIPAPPOINTITEMDATA_H__


// INCLUDES
#include <e32base.h>


// CONSTANTS
const TInt KSettingAppMaxSettingTextSize = 50;
const TInt KMinFldVal = 20;


// FORWARD DECLARATIONS
class CSharedDataI;


// CLASS DECLARATION

/**
* CgoSIPAppointItemData 
*/
class CgoSIPAppointItemData : public CBase
    {

    public: // Constructors and destructor

        /**
        * NewL.
        * Two-phased constructor.
        * Using two phase construction,and return a pointer to the created object
        * @return a pointer to the created instance of CgoSIPAppointItemData
        */
        static CgoSIPAppointItemData* NewL();

        /**
        * ~CgoSIPAppointItemData.
        * Virtual Destructor.
        */
        virtual ~CgoSIPAppointItemData();


    private:    // Constructors and destructor

        /**
        * CgoSIPAppointItemData.
        * C++ default constructor.
        */
        CgoSIPAppointItemData();

        /**
        * ConstructL.
        * 2nd phase constructor.
        */
        void ConstructL();

    public: // Data
        // appoint variables
        TBuf<KSettingAppMaxSettingTextSize> iSubject;
		TBuf<KSettingAppMaxSettingTextSize> iLocation;
        TTime iDate;
        TTime iTime;
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
