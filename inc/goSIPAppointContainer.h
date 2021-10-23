/*
============================================================================
 Name        : CgoSIPAppointContainer from goSIPAppointContainer.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Declares container control for application.
============================================================================
*/

#ifndef GOSIPAPPOINTCONTAINER_H
#define GOSIPAPPOINTCONTAINER_H

// INCLUDES
#include <coecntrl.h>

#include <aknsettingitemlist.h>
   
// FORWARD DECLARATIONS
class CEikLabel;        // for example labels

// CLASS DECLARATION
//additional for appoint form 
class CgoSIPAppointView;

/**
*  CgoSIPAppointContainer  container control class.
*  
*/
class CgoSIPAppointContainer : public CCoeControl//, public MEikListBoxObserver
    {
    private: // Enumerations

        enum TgoSIPAppointComponentControls
            {
            EgoSIPAppointComponentLabel
            };
	public: // Constructors and destructor
        
		/**
        * EPOC default constructor.
        * @param aRect Frame rectangle for container.
        */
        void ConstructL(const TRect& aRect);
		//additional appoint form
		//CgoSIPAppointContainer();
		CgoSIPAppointContainer( CgoSIPAppointView* aView );
        void SetTextToLabelL( TInt aResourceId );
        void DisplayFormL( TInt aResourceId );
		//end additional appoint form
		/**
        * Destructor.
        */
        ~CgoSIPAppointContainer();

    private: // Functions from base classes
		//additional appoint form
		void CreateLabelL();
		TKeyResponse OfferKeyEventL( const TKeyEvent& aKeyEvent, TEventCode aType );
		//end additional appoint form
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
    private: //data
        
        CEikLabel* iLabel;          // example label
        CAknTextSettingItem* iSubject;
		//appoint form additional
		CgoSIPAppointView* iView;

    };

#endif


