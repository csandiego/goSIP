/*
============================================================================
 Name        : CgoSIPMediaShareSearchContainer from goSIPMediaShareSearchContainer.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Declares container control for application.
============================================================================
*/

#ifndef GOSIPMEDIASHARESEARCHCONTAINER_H
#define GOSIPMEDIASHARESEARCHCONTAINER_H

// INCLUDES
#include <coecntrl.h>
#include <aknquerydialog.h>
#include <aknlistquerydialog.h>
#include <aknlists.h>
#include "goSIPMediaShareAppEngine.h"
   
// FORWARD DECLARATIONS
class CEikLabel;        // for example labels

// CLASS DECLARATION

/**
*  CgoSIPMediaShareSearchContainer  container control class.
*  
*/
class CgoSIPMediaShareSearchContainer : public CCoeControl, MCoeControlObserver
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
        ~CgoSIPMediaShareSearchContainer();

    public: // New functions
		
		void SearchFileL();
		
		void LoadL();

    public: // Functions from base classes
			
		TKeyResponse    OfferKeyEventL(const TKeyEvent& aKeyEvent,TEventCode aType);

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

	public:
		CAknDoubleStyleListBox* iListBox;
		CgoSIPMediaShareAppEngine* iAppEngine;
    };

#endif
