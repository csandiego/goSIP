/*
============================================================================
 Name        : CgoSIPAddUserContainer from goSIPAddUserContainer.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Declares container control for application.
============================================================================
*/

#ifndef GOSIPADDUSERCONTAINER_H
#define GOSIPADDUSERCONTAINER_H

// INCLUDES
#include <coecntrl.h>

#include <aknsettingitemlist.h>
   
// FORWARD DECLARATIONS
class CEikLabel;        // for example labels

// CLASS DECLARATION
//additional for addUser form 
class CgoSIPAddUserView;

/**
*  CgoSIPAddUserContainer  container control class.
*  
*/
class CgoSIPAddUserContainer : public CCoeControl//, public MEikListBoxObserver
    {
    private: // Enumerations

        enum TgoSIPAddUserComponentControls
            {
            EgoSIPAddUserComponentLabel
            };
	public: // Constructors and destructor
        
		/**
        * EPOC default constructor.
        * @param aRect Frame rectangle for container.
        */
        void ConstructL(const TRect& aRect);
		//additional adduser form
		//CgoSIPAddUserContainer();
		CgoSIPAddUserContainer( CgoSIPAddUserView* aView );
        void SetTextToLabelL( TInt aResourceId );
        void DisplayFormL( TInt aResourceId );
		//end additional addUser form
		/**
        * Destructor.
        */
        ~CgoSIPAddUserContainer();

    private: // Functions from base classes
		//additional adduser form
		void CreateLabelL();
		TKeyResponse OfferKeyEventL( const TKeyEvent& aKeyEvent, TEventCode aType );
		//end additional adduser form
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
		//addUser form additional
		CgoSIPAddUserView* iView;

    };

#endif


