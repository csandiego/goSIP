/*
============================================================================
 Name        : CgoSIPMediaShareDownloadContainer from goSIPMediaShareDownloadContainer.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Declares container control for application.
============================================================================
*/

#ifndef GOSIPMEDIASHAREDOWNLOADCONTAINER_H
#define GOSIPMEDIASHAREDOWNLOADCONTAINER_H

// INCLUDES
#include <coecntrl.h>
#include <eikprogi.h>
#include "eikenv.h"
   
// FORWARD DECLARATIONS
class CEikLabel;        // for example labels
class CEikProgressInfo;

const TInt KProgressBarHeight = 10;
const TInt KProgressBarResetValue = 0;
const TInt KAknExPbarBlack = 0xffffff;
const TInt KProgressBarSplitsInBlock = 0;
const TInt KProgressBarWidth = 120;
const TInt KProgressBarFinalValue = 30;

// CLASS DECLARATION

/**
*  CgoSIPMediaShareDownloadContainer  container control class.
*  
*/
class CgoSIPMediaShareDownloadContainer : public CCoeControl, MCoeControlObserver
    {
    public: // Constructors and destructor
        
        /**
        * EPOC default constructor.
        * @param aRect Frame rectangle for container.
        */
        void ConstructL(const TRect& aRect);

        /**
        * Destructor.
        */
        ~CgoSIPMediaShareDownloadContainer();

    public: // New functions

		void IncrementAndDrawBars();

    public: // Functions from base classes

    private: // Functions from base classes

       /**
        * From CoeControl,SizeChanged.
        */
        void SizeChanged();

       /**
        * From CoeControl,CountComponentControls.
        */
        TInt CountComponentControls() const;

       /**
        * From CCoeControl,ComponentControl.
        */
        CCoeControl* ComponentControl(TInt aIndex) const;

       /**
        * From CCoeControl,Draw.
        */
        void Draw(const TRect& aRect) const;

       	
		/**
		* From MCoeControlObserver
		* Acts upon changes in the hosted control's state. 
		*
		* @param	aControl	The control changing its state
		* @param	aEventType	The type of control event 
		*/
        void HandleControlEventL(CCoeControl* aControl,TCoeEvent aEventType);
        
    private: //data
        CEikLabel* iLabel;          // example label
		CEikProgressInfo* iPBar;


    };

#endif

// End of File
