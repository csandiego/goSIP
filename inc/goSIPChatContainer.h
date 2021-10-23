/*
============================================================================
 Name        : CgoSIPChatContainer from goSIPChatContainer.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Declares container control for application.
============================================================================
*/

#ifndef GOSIPCHATCONTAINER_H
#define GOSIPCHATCONTAINER_H

// INCLUDES
#include <coecntrl.h>
   
// FORWARD DECLARATIONS
//class CEikLabel;        // for example labels

// My Forward Declarations
//class CEikEdwin;
#include <eikedwin.h>

_LIT(KSaveDir, "C:\\goSIP\\Chat");

// CLASS DECLARATION

/**
*  CgoSIPChatContainer  container control class.
*  
*/
class CgoSIPChatContainer : public CCoeControl, MCoeControlObserver
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
        ~CgoSIPChatContainer();

    public: // New functions
		void WriteMessageL();
		void LoadFromBufferL(const TDesC& aBuffer);
		HBufC* SaveToHBufL() const;
		void SaveToFileL(const TDesC& aFilename) const;

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
		TKeyResponse OfferKeyEventL(const TKeyEvent& aKeyEvent, TEventCode aType);
        
    private: //data
        
        //CEikLabel* iLabel;          // example label
        //CEikLabel* iToDoLabel;      // example label

		CEikEdwin* iEdwin;
		//TDes* iBuffer;
    };

#endif

// End of File
