/*
============================================================================
 Name        : CgoSIPContainer from goSIPContainer.h
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Declares container control for application.
============================================================================
*/

#ifndef GOSIPCONTAINERGROUP_H
#define GOSIPCONTAINERGROUP_H

// INCLUDES
#include <aknlists.h>
#include <coecntrl.h>
#include <e32std.h>
#include <e32base.h>
#include <e32des16.h>
#include <s32file.h>
#include <akndoc.h>
#include <f32file.h>        // for CDir
#include <documenthandler.h>// for launching
#include <badesca.h>        // for CDesCArray
#include <apmstd.h>         // for TDataType
#include <coemain.h>
#include <eiktxlbm.h>
#include <eikclb.h>
#include "eiklbx.h"

//my add CONSTANTS
const TInt KGranularityOfArray = 10;
/*_LIT( KTab,"\t" );
_LIT( KMark,"|\t" );*/
   
// FORWARD DECLARATIONS
//class CEikLabel;        // for example labels

// CLASS DECLARATION
//class CgoSIPDocument;

/**
*  CgoSIPContainer  container control class.
*  
*/
class CgoSIPContainerGroup : public CCoeControl, MCoeControlObserver
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
        ~CgoSIPContainerGroup();

    public: // New functions

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

    //my add
    public: // Functions from base classes

		TKeyResponse    OfferKeyEventL(const TKeyEvent& aKeyEvent,TEventCode aType);
        
        //data
        
        //CEikLabel* iLabel;          // example label
        //CEikLabel* iToDoLabel;      // example label

        //my add

        /**
        * iListBox for Groups List
        */ 
        //CAknSingleStyleListBox* iListBox;
        CAknSingleStyleListBox* iListBox;

        /**
        * iListBoxArray as Array for iListBox
        */
        CDesCArray* iListBoxArray;
        TInt iFamilyIndex;
        TInt iFriendIndex;
        TInt iWorkmateIndex;

        void GetGroupIndex();

        void SaveList();
        void OpenList();
        void CloseList();
        void CreateList();

    private:
        RFs iFsSession;
	    RFileWriteStream writestream;
	    RFileReadStream readstream;

        /*CgoSIPDocument* document;
        void SetDocument(CgoSIPDocument* doc);*/

        //CgoSIPDocument* GetDocument();
    };

#endif
