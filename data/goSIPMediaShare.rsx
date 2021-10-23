//----------------------------------------------------------------------
//  r_gosip_gosipmediasharesearch_view -- View resources for 'goSIPMediaShareSearch'
//----------------------------------------------------------------------
RESOURCE AVKON_VIEW r_gosip_gosipmediasharesearch_view
    {
    menubar = r_gosip_gosipmediasharesearch_menubar;  
    cba     = R_AVKON_SOFTKEYS_SELECTION_LIST;    
    }

RESOURCE MENU_BAR r_gosip_gosipmediasharesearch_menubar
    {
    titles =
        {
        MENU_TITLE { menu_pane = r_gosip_app_menu; txt = "App"; },
        MENU_TITLE { menu_pane = r_gosip_gosipmediasharesearch_menu; txt = "View"; }
        };
    }

RESOURCE MENU_PANE r_gosip_gosipmediasharesearch_menu
    {
    items =
        {
	MENU_ITEM { command = EgoSIPMediaShareSearch; txt = qtn_search_view_option_search;},
	MENU_ITEM { command = EgoSIPMediaShareConfirm; txt = qtn_search_view_option_confirm; }
        };
    }



//----------------------------------------------------------------------
//  r_gosip_gosipmediashareshare_view -- View resources for 'goSIPMediaShareShare'
//----------------------------------------------------------------------
RESOURCE AVKON_VIEW r_gosip_gosipmediashareshare_view
    {
    menubar = r_gosip_gosipmediashareshare_menubar;  
    cba     = R_AVKON_SOFTKEYS_SELECTION_LIST;    
    }

RESOURCE MENU_BAR r_gosip_gosipmediashareshare_menubar
    {
    titles =
        {
        MENU_TITLE { menu_pane = r_gosip_app_menu; txt = "App"; },
        MENU_TITLE { menu_pane = r_gosip_gosipmediashareshare_menu; txt = "View"; }
        };
    }

RESOURCE MENU_PANE r_gosip_gosipmediashareshare_menu
    {
    items =
        {
        MENU_ITEM { command = EgoSIPMediaShareShare; txt = qtn_share_view_option_share; },
	MENU_ITEM { command = EgoSIPMediaShareUnshare; txt = qtn_share_view_option_unshare; }
        };
    }


//----------------------------------------------------------------------
//  r_gosip_gosipmediasharedownload_view -- View resources for 'goSIPMediaShareDownload'
//----------------------------------------------------------------------
RESOURCE AVKON_VIEW r_gosip_gosipmediasharedownload_view
    {
    menubar = r_gosip_gosipmediasharedownload_menubar;  
    cba     = R_AVKON_SOFTKEYS_SELECTION_LIST;    
    }

RESOURCE MENU_BAR r_gosip_gosipmediasharedownload_menubar
    {
    titles =
        {
        MENU_TITLE { menu_pane = r_gosip_app_menu; txt = "App"; },
        MENU_TITLE { menu_pane = r_gosip_gosipmediasharedownload_menu; txt = "View"; }
        };
    }

RESOURCE MENU_PANE r_gosip_gosipmediasharedownload_menu
    {
    items =
        {
        MENU_ITEM { command = EgoSIPCmdAppTest; txt = qtn_download_view_option_cancel; }
        };
    }


//----------------------------------------------------------------------
//  r_gosip_gosipmediashareupload_view -- View resources for 'goSIPMediaShareUpload'
//----------------------------------------------------------------------
RESOURCE AVKON_VIEW r_gosip_gosipmediashareupload_view
    {
    menubar = r_gosip_gosipmediashareupload_menubar;  
    cba     = R_AVKON_SOFTKEYS_SELECTION_LIST;    
    }

RESOURCE MENU_BAR r_gosip_gosipmediashareupload_menubar
    {
    titles =
        {
        MENU_TITLE { menu_pane = r_gosip_app_menu; txt = "App"; },
        MENU_TITLE { menu_pane = r_gosip_gosipmediashareupload_menu; txt = "View"; }
        };
    }

RESOURCE MENU_PANE r_gosip_gosipmediashareupload_menu
    {
    items =
        {
        MENU_ITEM { command = EgoSIPCmdAppTest; txt = qtn_upload_view_option_cancel; }
        };
    }


RESOURCE AVKON_LIST_QUERY r_gosip_mediashare_select_memory
{
    flags = EGeneralQueryFlags;
    softkeys = R_AVKON_SOFTKEYS_SELECT_CANCEL;
    items =
    {
        AVKON_LIST_QUERY_DLG_LINE
        {
            control = AVKON_LIST_QUERY_CONTROL
            {
                heading = qtn_appl_select_memory;
                listtype = EAknCtSinglePopupMenuListBox;
                listbox = AVKON_LIST_QUERY_LIST
                {
                    array_id = r_gosip_mediashare_select_memory_list;
                };
            };
        }
    };
}

RESOURCE ARRAY r_gosip_mediashare_select_memory_list
{
    items =
    {
        LBUF { txt = qtn_appl_phone_memory; },
        LBUF { txt = qtn_appl_memory_card; }
    };
}

	//DIRECTORY CHOOSER
	
RESOURCE AVKON_LIST_QUERY r_gosip_mediashare_select_directory
{
    flags = EGeneralQueryFlags;
    softkeys = R_AVKON_SOFTKEYS_SELECT_BACK;
    items =
    {
        AVKON_LIST_QUERY_DLG_LINE
        {
            control = AVKON_LIST_QUERY_CONTROL
            {
                //heading = qtn_appl_select_memory;
                listtype = EAknCtSinglePopupMenuListBox;
                listbox = AVKON_LIST_QUERY_LIST
                {
                    array_id = r_gosip_mediashare_select_directory_list;
                };
            };
        }
    };
}

RESOURCE ARRAY r_gosip_mediashare_select_directory_list
{
    items =
    {
        LBUF { txt = qtn_appl_images; },
        LBUF { txt = qtn_appl_sounds; },
        LBUF { txt = qtn_appl_videos; }
    };
}


RESOURCE DIALOG r_aknexquery_confirmation_no_icon_query
    {
    flags = EGeneralQueryFlags;
    buttons = R_AVKON_SOFTKEYS_YES_NO;
    items =
        {
        DLG_LINE
            {
            type = EAknCtQuery;
            id = EGeneralQuery;
            control = AVKON_CONFIRMATION_QUERY
                {
                layout = EConfirmationQueryLayout;
                label = qtn_aknexquery_con_label_text;
                };
            }
        };
    }

RESOURCE DIALOG r_aknexquery_data_query
    {
    flags = EGeneralQueryFlags;
    buttons = R_AVKON_SOFTKEYS_OK_CANCEL;
    items =
        {
        DLG_LINE
            {
            type = EAknCtQuery;
            id = EGeneralQuery;//EDataQueryDlgCIdDataQuery;
            control = AVKON_DATA_QUERY
            {    layout = EDataLayout;
                //label = qtn_aknexquery_data_label_text;
                control = EDWIN
					{
						flags = EEikEdwinResizable;
						width = 200;
						//lines = 5;
						maxlength = 256; //KMaxGameNameLength;
						max_view_height_in_lines = 6;
						base_line_delta = 21;
					};
				
                };
            }
        };
    }
