// lihan resource


//defined stuff added from appoint group
#define GOSIP_NUMBER_EDITOR_MIN_VALUE01   10
#define GOSIP_NUMBER_EDITOR_MAX_VALUE01   30
#define GOSIP_NUMBER_EDITOR_MIN_VALUE02    0
#define GOSIP_NUMBER_EDITOR_MAX_VALUE02   10
// for Date Setting page
#define DATE_EDITOR_MAX_DAY          30
#define DATE_EDITOR_MIN_DAY           0
#define DATE_EDITOR_MAX_MONTH        11
#define DATE_EDITOR_MIN_MONTH         0
#define DATE_EDITOR_MAX_YEAR       2060
#define DATE_EDITOR_MIN_YEAR       1980

// for Time Setting Page
#define TIME_SETTING_PAGE_NUMBER                    1
#define TIME_EDITOR_MIN_SECOND                      0
#define TIME_EDITOR_MIN_MINUTE                      0
#define TIME_EDITOR_MIN_HOUR                        0
#define TIME_EDITOR_MAX_SECOND                      59
#define TIME_EDITOR_MAX_MINUTE                      59
#define TIME_EDITOR_MAX_HOUR                        23
//end of defined stuff


//Start Appointment menu
//1 Set Appointment
RESOURCE AVKON_VIEW r_gosip_appoint_view1
    {
    hotkeys = r_gosip_hotkeys;
    menubar = r_gosip_appoint_menubar_view1;  
    cba     = R_AVKON_SOFTKEYS_SELECTION_LIST;    
    }

RESOURCE MENU_BAR r_gosip_appoint_menubar_view1
    {
    titles =
        {
        MENU_TITLE { menu_pane = r_gosip_appoint_view1_menu; txt = "Appoint View"; }
        };
    }
    
RESOURCE MENU_PANE r_gosip_appoint_view1_menu
    {
    items =
        {
        MENU_ITEM { command = EAppointAddDTime; txt = qtn_appoint1_add_dtime; },
        MENU_ITEM { command = EAppointDelDTime; txt = qtn_appoint1_del_dtime; flags = EEikMenuItemSeparatorAfter; },
        MENU_ITEM { command = EAppointDisplayUL; txt = qtn_appoint1_display_ul; flags = EEikMenuItemSeparatorAfter; },
        MENU_ITEM { command = EAppointStartReq; txt = qtn_appoint1_start_req; flags = EEikMenuItemSeparatorAfter; },
        MENU_ITEM { command = EAppointCmdExit; txt = qtn_appoint1_exit; }
        };
    }
RESOURCE NAVI_LABEL r_gosip_appoint_navi_label
	{
	txt = qtn_appoint1_navi_waiting;
	}
//2 Confirm Appointment

//3 View User List

//End Appointment menu
//View Appoint Stuff
RESOURCE DIALOG r_gosip_appoint_exit_query
    {
    flags = EGeneralQueryFlags;
    buttons = R_AVKON_SOFTKEYS_YES_NO;
    items = {
        DLG_LINE {
           type = EAknCtQuery;
           id = EGeneralQuery;
           control = AVKON_CONFIRMATION_QUERY{
           layout = EConfirmationQueryLayout; 
              };
           }
       };
    }
//setting list
RESOURCE AVKON_SETTING_ITEM_LIST r_gosip_appoint_setting_list_view1
    {
    title = qtn_gosip_appoint_view1_label;
    //initial_number = 1;
    items =     
        {
        AVKON_SETTING_ITEM
            {
            identifier = EAppointSettingSubj;
            setting_page_resource = r_gosip_appoint_subj_setting_page;
            name = qtn_appoint1_subject_title; //qtn_exsl_text_title;
            },
        AVKON_SETTING_ITEM
            {
            identifier = EAppointSettingLoc;
            setting_page_resource = r_gosip_appoint_loc_setting_page;
            name = qtn_appoint1_loc_title;
            },
        AVKON_SETTING_ITEM
            {
            identifier = EAppointSettingDate;
            setting_page_resource = r_gosip_appoint_date_setting_page;
            name = qtn_appoint1_date_title;
            },
        AVKON_SETTING_ITEM
            {
            identifier = EAppointSettingTime;
            setting_page_resource = r_gosip_appoint_time_setting_page;
            name = qtn_appoint1_time_title;
            }    
        };
    }
RESOURCE AVKON_SETTING_PAGE r_gosip_appoint_subj_setting_page
    {
    //number = TEXT_SETTING_PAGE_NUMBER;
    label = qtn_appoint1_subject_title;
    type = EEikCtEdwin;
    editor_resource_id = r_gosip_appoint_edwin;
    }
RESOURCE AVKON_SETTING_PAGE r_gosip_appoint_loc_setting_page
    {
    //number = TEXT_SETTING_PAGE_NUMBER;
    label = qtn_appoint1_loc_title;
    type = EEikCtEdwin;
    editor_resource_id = r_gosip_appoint_edwin;
    }
RESOURCE AVKON_SETTING_PAGE r_gosip_appoint_date_setting_page
    {
    label= qtn_appoint1_date_title;
    type = EEikCtTimeAndDateEditor;
    editor_resource_id = r_gosip_appoint_date;
    }
RESOURCE AVKON_SETTING_PAGE r_gosip_appoint_time_setting_page
    {
    label= qtn_appoint1_time_title;
    type = EEikCtTimeAndDateEditor;
    editor_resource_id = r_gosip_appoint_time;
    }

RESOURCE DATE_EDITOR r_gosip_appoint_date
    {
    //minDate= DATE {year=1980;};
    //maxDate= DATE {year=2060;};
    //flags=0;
    minDate = DATE
        {
        year = DATE_EDITOR_MIN_YEAR;
        day = DATE_EDITOR_MIN_DAY;
        month = DATE_EDITOR_MIN_MONTH;
        };
    maxDate = DATE
        {
        year = DATE_EDITOR_MAX_YEAR;
        day = DATE_EDITOR_MAX_DAY;
        month = DATE_EDITOR_MAX_MONTH;
        };
    //flags = EEikTimeWithoutSecondsField;
    }
RESOURCE TIME_EDITOR r_gosip_appoint_time
    {
    minTime = TIME
        {
        second = TIME_EDITOR_MIN_SECOND;
        minute = TIME_EDITOR_MIN_MINUTE;
        hour = TIME_EDITOR_MIN_HOUR;        
        };
    maxTime = TIME
        {
        second = TIME_EDITOR_MAX_SECOND;
        minute = TIME_EDITOR_MAX_MINUTE;
        hour = TIME_EDITOR_MAX_HOUR;
        };
    flags = EEikTimeWithoutSecondsField;
    }

RESOURCE EDWIN r_gosip_appoint_edwin
    {
    width = 9;
    lines = 5;
    maxlength = 20;
    }
RESOURCE TBUF256 r_gosip_appoint_edwin_text
    {
    buf = qtn_gosip_appoint_edwin_text;
    }
RESOURCE TBUF256 r_gosip_appoint_view1_label
    {
    buf = qtn_gosip_appoint_view1_label;
    }
RESOURCE TBUF256 r_gosip_appoint_view2_label
    {
    buf = qtn_gosip_appoint_view2_label;
    }
RESOURCE TBUF256 r_gosip_appoint_view3_label
    {
    buf = qtn_gosip_appoint_view3_label;
    }
// end of lihan resource
