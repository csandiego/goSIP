/* Copyright (c) 2004, Nokia. All rights reserved */


#ifndef __GOSIPAPPOINTLISTBOX_H__
#define __GOSIPAPPOINTLISTBOX_H__



// INCLUDES
#include <AknSettingItemList.h>



// FORWARD DECLARATIONS
class CgoSIPAppointItemData;
class CgoSIPAppointView;



// CLASS DECLARATION

/**
* CgoSIPAppointContainer  container control class.
*/
class CgoSIPAppointListbox : public CAknSettingItemList 
    {
    public:  // From CAknSettingItemList


        /**
        * CreateSettingItemL
        * Creates SettingItem
        * @param identifier
        * @return pointer to CAknSettingItem object
        */
        CAknSettingItem* CreateSettingItemL( TInt identifier );
                
        /**
        * SetData
        * Sets List's item data.
        * @param aData data to set
        */
        void SetData( CgoSIPAppointItemData* aData );
        
         /**
        * SetView
        * Sets List's item view
        * @param aView view to set
        */
        void SetView( CgoSIPAppointView* aView );
        

    private:    // From CCoeControl

        /**
        * OfferKeyEventL.
        * Handles the key events.
        * @param aKeyEvent Key event
        * @param aType Type of key event (EEventKey, EEventKeyUp or EEventKeyDown)
        * @return if key-event is consumed, EKeyWasConsumed. Else EKeyWasNotConsumed
        */
        TKeyResponse OfferKeyEventL( const TKeyEvent& aKeyEvent, 
                                     TEventCode aType );

        /**
        * SizeChanged
        * Called by framework when the size is changed..
        */
        void SizeChanged();
    private:    //Data

        /**
        * iData
        * Not owned by CgoSIPAppointListbox object.
        */  
        CgoSIPAppointItemData*      iData;

        /**
        * iView
        * Not owned by CgoSIPAppointListbox object.
        */  
        CgoSIPAppointView*          iView;
		
    };


#endif //__goSIPAppointLISTBOX_H__

// End of File
