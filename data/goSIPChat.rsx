//----------------------------------------------------------------------
//  r_gosip_gosipchat_view -- View resources for 'goSIPChat'
//----------------------------------------------------------------------
RESOURCE AVKON_VIEW r_gosip_gosipchat_view
    {
    menubar = r_gosip_gosipchat_menubar;  
    cba     = R_AVKON_SOFTKEYS_SELECTION_LIST;    
    }
/*
RESOURCE MENU_BAR r_gosip_gosipchat_menubar
    {
    titles =
        {
        MENU_TITLE { menu_pane = r_gosip_app_menu; txt = "App"; },
        MENU_TITLE { menu_pane = r_gosip_gosipchat_menu; txt = "View"; }
        };
    }
*/
RESOURCE MENU_BAR r_gosip_gosipchat_menubar
	{
		titles =
			{
			MENU_TITLE
				{
				menu_pane = r_gosip_gosipchat_menu;
				}
			};
	}
/*
RESOURCE MENU_PANE r_gosip_gosipchat_menu
    {
    items =
        {
        MENU_ITEM
			{
			// TODO: Change the following line to point to a command defined in the .hrh file
			command = EgoSIPCmdAppTest;
			// TODO: Change the following line to point to a localized string in the .loc file
			// #define R_GOSIP_GOSIPCHAT_OPTION_TEST "Test"
			txt = R_GOSIP_GOSIPCHAT_OPTION_TEST;
			}
        };
    }
*/
	
RESOURCE MENU_PANE r_gosip_gosipchat_menu
	{
		items =
			{
			MENU_ITEM
				{
				command = EgoSIPChatCmdWriteMessage;
				txt = "Write Message";
				},
			MENU_ITEM
				{
				command = EgoSIPChatCmdDisplayUserList;
				txt = "Display user list";
				},
			MENU_ITEM
				{
				command = EgoSIPChatCmdClose;
				txt = "Close";
				}
			};
	}
RESOURCE DIALOG r_gosip_gosipchat_close_dialog
	{
	flags = EAknGeneralQueryFlags;
	buttons = R_AVKON_SOFTKEYS_YES_NO;
	items =
		{
		DLG_LINE
			{
			type = EAknCtQuery;
			id = EGeneralQuery;
			control =
				AVKON_CONFIRMATION_QUERY
					{
					layout = EConfirmationQueryLayout;
					};
			}
		};
	}
	
RESOURCE DIALOG r_gosip_gosipchat_save_dialog
	{
	flags = EAknGeneralQueryFlags;
	buttons = R_AVKON_SOFTKEYS_YES_NO;
	items =
		{
		DLG_LINE
			{
			type = EAknCtQuery;
			id = EGeneralQuery;
			control =
				AVKON_CONFIRMATION_QUERY
					{
					layout = EConfirmationQueryLayout;
					};
			}
		};
	}
	
RESOURCE DIALOG r_gosip_gosipchat_writemessage_dialog
	{
	flags = EAknGeneralQueryFlags;
	buttons = R_AVKON_SOFTKEYS_OK_CANCEL;
	
	items =
		{
		DLG_LINE
			{
			type = EAknCtQuery;
			//id = EDataQueryDlgCIdDataQuery;
			id = 5000;
			control = 
				AVKON_DATA_QUERY
					{
					layout = EDataLayout;
					control = 
						EDWIN
							{
							width = 13;
							lines = 3;
							maxlength = 256;
							};
					};
			}
		};
	}

RESOURCE RTXTED r_gosip_gosipchat_editor
	{
	width = 13;
	height = 7;
	textlimit = 256;
	flags = EEikEdwinReadOnly | EEikEdwinAvkonDisableCursor;
	avkon_flags = EAknEditorFlagEnableScrollBars;
	}
	
RESOURCE DIALOG r_gosip_gosipchat_savefilename_dialog
	{
	flags = EAknGeneralQueryFlags;
	buttons = R_AVKON_SOFTKEYS_OK_CANCEL;
	
	items =
		{
		DLG_LINE
			{
			type = EAknCtQuery;
			//id = EDataQueryDlgCIdDataQuery;
			id = 5000;
			control = 
				AVKON_DATA_QUERY
					{
					layout = EDataLayout;
					control = 
						EDWIN
							{
							width = 13;
							lines = 1;
							maxlength = 256;
							};
					};
			}
		};
	}

RESOURCE LISTBOX r_gosip_gosipchatuserlist_sample_user_list
	{
	array_id = r_gosip_gosipchatuserlist_sample_user_list_items;
	flags = EAknListBoxSelectionList;
	}

RESOURCE ARRAY r_gosip_gosipchatuserlist_sample_user_list_items
	{
	items =
		{
		LBUF { txt = "\tHardy"; },
		LBUF { txt = "\tAdrian"; },
		LBUF { txt = "\tKit"; },
		LBUF { txt = "\tPamela"; },
		LBUF { txt = "\tRyan"; },
		LBUF { txt = "\tChristopher"; },
		LBUF { txt = "\tAllan"; },
		LBUF { txt = "\tSy"; }
		};
	}

RESOURCE AVKON_LIST_QUERY r_gosip_gosipchatuserlist_list_query
	{
	items =
		{
		AVKON_LIST_QUERY_DLG_LINE
			{
			control = AVKON_LIST_QUERY_CONTROL
				{
				listtype =EAknCtSinglePopupMenuListBox;
				heading = "Invite User";
				listbox = AVKON_LIST_QUERY_LIST
					{
					//array_id = r_gosipchat_sample_user_list_items;
					//	LBUF { txt = "\tHardy"; },
					//	LBUF { txt = "\tAdrian"; },
					
					};
				};
			}
		};
	}

RESOURCE AVKON_VIEW r_gosip_gosipchatuserlist_view
    {
    hotkeys = r_gosip_hotkeys;
    menubar = r_gosip_gosipchatuserlist_menubar;  
    cba     = R_AVKON_SOFTKEYS_SELECTION_LIST; 
    }

RESOURCE MENU_BAR r_gosip_gosipchatuserlist_menubar
    {
    titles =
        {
        //MENU_TITLE { menu_pane = r_gosip_app_menu; txt = "App"; },
        MENU_TITLE { menu_pane = r_gosip_gosipchatuserlist_menu; txt = "View"; }
        };
    }

RESOURCE MENU_PANE r_gosip_gosipchatuserlist_menu
    {
    items =
        {
        MENU_ITEM { command = EgoSIPChatCmdInviteUsers; txt = "Add user to group"; },
        MENU_ITEM { command = EgoSIPChatCmdInviteUsers; txt = "Kick User"; },
        MENU_ITEM { command = EgoSIPChatCmdInviteUsers; txt = "Invite other users"; }
        };
    }
