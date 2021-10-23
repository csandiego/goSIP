
// MY ADD, for View Group
RESOURCE AVKON_VIEW r_gosip_viewgroup
    {
    hotkeys = r_gosip_hotkeys;
    menubar = r_gosip_menubar_viewgroup;  
    cba     = R_AVKON_SOFTKEYS_SELECTION_LIST;    
    }

RESOURCE MENU_BAR r_gosip_menubar_viewgroup
    {
    titles =
        {
        MENU_TITLE { menu_pane = r_gosip_app_menu; txt = "App"; },
        MENU_TITLE { menu_pane = r_gosip_viewgroup_menu; txt = "View"; }
        };
    }

RESOURCE MENU_PANE r_gosip_viewgroup_menu
    {
    items =
        {
        MENU_ITEM { command = EgoSIPCmdAppChat; txt = qtn_viewgroup_option_chat; },
        MENU_ITEM { command = EgoSIPCmdAppSetAppointment; txt = qtn_viewgroup_option_setappointment; },
        MENU_ITEM { command = EgoSIPCmdAppSearchPhonebooks; txt = qtn_viewgroup_option_searchphonebooks; },
        MENU_ITEM { command = EgoSIPCmdAppSearchFiles; txt = qtn_viewgroup_option_searchfiles;
                    flags = EEikMenuItemSeparatorAfter; },
        MENU_ITEM { command = EgoSIPCmdAppAddUser; txt = qtn_viewgroup_option_adduser; },
        MENU_ITEM { command = EgoSIPCmdAppMoveUser; txt = qtn_viewgroup_option_moveuser; },
        MENU_ITEM { command = EgoSIPCmdAppDeleteUser; txt = qtn_viewgroup_option_deleteuser;
                    flags = EEikMenuItemSeparatorAfter; },
        MENU_ITEM { command = EgoSIPCmdAppSharePhonebook; txt = qtn_viewgroup_option_sharephonebook; },
        MENU_ITEM { command = EgoSIPCmdAppShareFiles; txt = qtn_viewgroup_option_sharefiles;
                    flags = EEikMenuItemSeparatorAfter; },
        MENU_ITEM { command = EgoSIPCmdAppGoOnline; txt = qtn_viewgroup_option_goonline; 
                    flags = EEikMenuItemSeparatorAfter; },
        MENU_ITEM { command = EgoSIPCmdAppGoOffline; txt = qtn_viewgroup_option_gooffline;
                    flags = EEikMenuItemSeparatorAfter; },
        MENU_ITEM { command = EgoSIPCmdAppOptions; txt = qtn_viewgroup_option_options; },
        MENU_ITEM { command = EgoSIPCmdAppAboutGoSIP; txt = qtn_viewgroup_option_aboutgosip; }
        };
    }

//my add
RESOURCE LISTBOX r_dynamiclist_list_box
    {
    flags = EAknListBoxMarkableList;
    }

// MY ADD, for View Group
RESOURCE AVKON_VIEW r_gosip_viewadduser
    {
    cba     = r_gosip_softkeys_viewadduser;
    menubar = r_gosip_menubar_viewadduser;  
    }

RESOURCE MENU_BAR r_gosip_menubar_viewadduser
    {
    titles =
        {
        MENU_TITLE { menu_pane = r_gosip_viewadduser_menu; }
        };
    }

RESOURCE MENU_PANE r_gosip_viewadduser_menu
    {
    items =
        {
        MENU_ITEM { command = EgoSIPCmdAddUserRequest; txt = qtn_viewadduser_option_request; 
                    flags = EEikMenuItemSeparatorAfter; },
		MENU_ITEM { command = EgoSIPCmdAddUserClose; txt = qtn_viewadduser_option_close; }
        };
    }

RESOURCE CBA r_gosip_softkeys_viewadduser
    {
    buttons =
        {
        CBA_BUTTON 
            {
            id = EAknSoftkeyOptions; 
            txt = "Options";
            },
        CBA_BUTTON 
            {
            id = EgoSIPCmdAddUserClose;
            txt = "Close";
            }
        };
    }


RESOURCE AVKON_SETTING_ITEM_LIST r_gosip_adduser_settings_list
    {
    items = {
        AVKON_SETTING_ITEM {
            identifier = EgoSIPSettingItemAddUserSIPAddress;
            setting_page_resource = r_gosip_addusersipaddress_setting_page;
            name = qtn_settinglistadduser_item_sipaddress;
            },
        AVKON_SETTING_ITEM {
            identifier = EgoSIPSettingItemAddUserAddToGroup;
            setting_page_resource = r_gosip_adduseraddtogroup_setting_page;
            name = qtn_settinglistadduser_item_addtogroup;
            }
        };
    }
    
RESOURCE AVKON_SETTING_PAGE r_gosip_addusersipaddress_setting_page
    {
    number = 1;
    label = qtn_settingpageadduser_label_sipaddress;
    type = EEikCtEdwin;
    editor_resource_id = r_gosip_addusersipaddress_edwin;
    }
    
RESOURCE AVKON_SETTING_PAGE r_gosip_adduseraddtogroup_setting_page
    {
    number = 1;
    label = qtn_settingpageadduser_label_addtogroup;
    type = EEikCtEdwin;
    editor_resource_id = r_gosip_adduseraddtogroup_edwin;
    }
    
RESOURCE EDWIN r_gosip_addusersipaddress_edwin
    {
    width = 10;
    maxlength = 40;
    }
    
RESOURCE EDWIN r_gosip_adduseraddtogroup_edwin
    {
    width = 1;
    maxlength = 20;
    }
    
RESOURCE TBUF256 r_gosip_adduser_edwin_text
    {
    buf = qtn_gosip_adduser_edwin_text;
    }
