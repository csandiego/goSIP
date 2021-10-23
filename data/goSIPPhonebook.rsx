
//--------------------------------------------------    
// icon names ?
//  SOURCEPATH               ..\datasrc 
//  SOURCE                   C12 marked_add.bmp 
//  SOURCE                   C12 marked_add_m.bmp 
//  SOURCE                   C12 check.bmp 
//  SOURCE                   1 checkm.bmp 
//  SOURCE                   C12 non_check.bmp 
//  SOURCE                   1 non_checkm.bmp 
//--------------------------------------------------
RESOURCE ARRAY r_icons
    {
    items =
        {
        LBUF
            {
            txt = "../datasrc/check.bmp";
            },
        LBUF
            {
            txt = "../datasrc/checkm.bmp";
            },
        LBUF
            {
            txt = "../datasrc/marked_add.bmp";
            },
        LBUF
            {
            txt = "../datasrc/marked_add_m.bmp";
            },
        LBUF
            {
            txt = "../datasrc/non_check.bmp";
            },
        LBUF
            {
            txt = "../datasrc/non_checkm.bmp";
            }
        };
    }


//----------------------------------------------------
//   
//    r_gosip_phonebook_hotkeys
//
//----------------------------------------------------
//
RESOURCE HOTKEYS r_gosip_phonebook_hotkeys
    {
    control =
        {
        HOTKEY { command = EAknCmdExit; key = 'e'; }
        };
    }

//----------------------------------------------------
//   
//    r_gosip_phonebook_view1
//
//----------------------------------------------------
//
RESOURCE AVKON_VIEW r_gosip_phonebook_view1
    {
    hotkeys = r_gosip_phonebook_hotkeys;
    menubar = r_gosip_phonebook_menubar_view1;  
    cba     = R_AVKON_SOFTKEYS_SELECTION_LIST;    
    }

//----------------------------------------------------
//   
//    r_gosip_phonebook_menubar_view1
//
//----------------------------------------------------
//
RESOURCE MENU_BAR r_gosip_phonebook_menubar_view1
    {
    titles =
        {
        MENU_TITLE { menu_pane = r_gosip_phonebook_exit_menu; txt = "Exit"; },
        MENU_TITLE { menu_pane = r_gosip_phonebook_shared_menu; txt = "Shared Phonebooks Menu"; }
        };
    }

//----------------------------------------------------
//   
//    r_gosip_phonebook_view1_menu
//
//----------------------------------------------------
//
RESOURCE MENU_PANE r_gosip_phonebook_shared_menu
    {
    items =
        {
        MENU_ITEM { command = ECallContact; txt = call_number; },
        MENU_ITEM { command = ESMSContact; txt = message_number; },
        MENU_ITEM { command = ECopyContact; txt = save_number; }
        };
    }

//----------------------------------------------------
//   
//    r_gosip_phonebook_view2
//
//----------------------------------------------------
//
RESOURCE AVKON_VIEW r_gosip_phonebook_view2
    {
    hotkeys = r_gosip_phonebook_hotkeys;
    menubar = r_gosip_phonebook_menubar_view2;  
    cba     = R_AVKON_SOFTKEYS_SELECTION_LIST; 
    }

//----------------------------------------------------
//   
//    r_gosip_phonebook_menubar_view2
//
//----------------------------------------------------
//
RESOURCE MENU_BAR r_gosip_phonebook_menubar_view2
    {
    titles =
        {
        MENU_TITLE { menu_pane = r_gosip_phonebook_exit_menu; txt = "Exit"; },
        MENU_TITLE { menu_pane = r_gosip_phonebook_self_menu; txt = "Share Own Phonebook"; }
        };
    }

//----------------------------------------------------
//   
//    r_gosip_phonebook_self_menu
//
//----------------------------------------------------
//
RESOURCE MENU_PANE r_gosip_phonebook_self_menu
    {
    items =
        {
        //MENU_ITEM { command = EgoSIP_PhonebookCmdAppTest; txt = marking; },
        MENU_ITEM { command = EAknCmdMark; txt = "Mark"; },
        MENU_ITEM { command = EAknCmdUnmark; txt = "Unmark"; },
        MENU_ITEM { command = EgoSIPCmdAppTest; txt = share_marked; },
        MENU_ITEM { command = EgoSIPCmdAppTest; txt = unshare_marked; }
        };
    }
    
//R_ICON_FILE_NAME    
//RESOURCE LISTBOX r_icon_filename
//	{
	//array_id = 
//	} 

//-----------------------------------------------------------------------------
//
// String resources
//
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//
//    r_contacts_create_db_message
//    Label of Create Database message.
//
//-----------------------------------------------------------------------------
//
RESOURCE TBUF r_gosip_phonebook_create_db_message
    {
    buf = qtn_contacts_create_db_message;
    }

//-----------------------------------------------------------------------------
//
//    r_contacts_delete_db_query_message
//    Label of Delete db message.
//
//-----------------------------------------------------------------------------
//
RESOURCE TBUF r_gosip_phonebook_delete_db_query_message
    {
    buf = qtn_contacts_delete_db_query_message;
    }

//-----------------------------------------------------------------------------
//
//    r_contacts_delete_contact_message
//    Label of Delete contact message.
//
//-----------------------------------------------------------------------------
//
RESOURCE TBUF r_gosip_phonebook_delete_contact_message
    {
    buf = qtn_contacts_delete_contact_message;
    }

//-----------------------------------------------------------------------------
//
//    r_contacts_delete_group_message
//    Label of Delete contact group message.
//
//-----------------------------------------------------------------------------
//
RESOURCE TBUF r_gosip_phonebook_delete_group_message
    {
    buf = qtn_contacts_delete_group_message;
    }

//-----------------------------------------------------------------------------
//
//    r_contacts_create_group_message
//    Label of create contact group message.
//
//-----------------------------------------------------------------------------
//
RESOURCE TBUF r_gosip_phonebook_create_group_message
    {
    buf = qtn_contacts_create_group_message;
    }

//-----------------------------------------------------------------------------
//
//    r_contacts_create_group_message
//    Label of create contact template message.
//
//-----------------------------------------------------------------------------
//
RESOURCE TBUF r_gosip_phonebook_create_template_message
    {
    buf = qtn_contacts_create_template_message;
    }


//-----------------------------------------------------------------------------
//
//    r_contacts_db_already_exists
//    Label of contact already exists message.
//
//-----------------------------------------------------------------------------
//
RESOURCE TBUF r_gosip_phonebook_db_already_exists
    {
    buf = qtn_contacts_db_already_exists;
    }

//-----------------------------------------------------------------------------
//
//    r_contacts_db_no_db
//    Label of no contacts database message.
//
//-----------------------------------------------------------------------------
//
RESOURCE TBUF r_gosip_phonebook_db_no_db
    {
    buf = qtn_contacts_db_no_db;
    }
     
//-----------------------------------------------------------------------------
//
//    r_contacts_cannot_delete_def_db
//    Label of cannot delete default database message.
//
//-----------------------------------------------------------------------------
//
RESOURCE TBUF r_gosip_phonebook_cannot_delete_def_db
    {
    buf = qtn_contacts_cannot_delete_def_db;
    }

//-----------------------------------------------------------------------------
//
//    r_contacts_cannot_delete_db
//    Label of cannot delete database message.
//
//-----------------------------------------------------------------------------
//
RESOURCE TBUF r_gosip_phonebook_cannot_delete_db
    {
    buf = qtn_contacts_cannot_delete_db;
    }

//-----------------------------------------------------------------------------
//
//    r_contacts_db_not_found
//    Label of database not found
//
//-----------------------------------------------------------------------------
//
RESOURCE TBUF r_gosip_phonebook_db_not_found
    {
    buf = qtn_contacts_db_not_found;
    }

//-----------------------------------------------------------------------------
//
//    r_contacts_no_db_selected
//    Label of database not selected
//
//-----------------------------------------------------------------------------
//
RESOURCE TBUF r_gosip_phonebook_no_db_selected
    {
    buf = qtn_contacts_no_db_selected;
    }
	
//-----------------------------------------------------------------------------
//
//    r_contacts_no_contact_selected
//    Label of contact not selected
//
//-----------------------------------------------------------------------------
//
RESOURCE TBUF r_gosip_phonebook_no_contact_selected
    {
    buf = qtn_contacts_no_contact_selected;
    }

//-----------------------------------------------------------------------------
//
//    r_contacts_open_created_db
//    Label of open created database
//
//-----------------------------------------------------------------------------
//
RESOURCE TBUF r_gosip_phonebook_open_created_db
    {
    buf = qtn_contacts_open_created_db;
    }

//-----------------------------------------------------------------------------
//
//    r_contacts_created_db
//    Label of created database title
//
//-----------------------------------------------------------------------------
//
RESOURCE TBUF r_gosip_phonebook_created_db
    {
    buf = qtn_contacts_created_db;
    }

//-----------------------------------------------------------------------------
//
//    r_contacts_default_db
//    Label of default database title
//
//-----------------------------------------------------------------------------
//
RESOURCE TBUF r_gosip_phonebook_default_db
    {
    buf = qtn_contacts_default_db;
    }

//-----------------------------------------------------------------------------
//
//    r_contacts_no_db
//    Label of no database title
//
//-----------------------------------------------------------------------------
//
RESOURCE TBUF r_gosip_phonebook_no_db
    {
    buf = qtn_contacts_no_db;
    }



//----------------------------------------------------
//   
//    r_gosip_phonebook_exit_menu
//
//----------------------------------------------------
//
RESOURCE MENU_PANE r_gosip_phonebook_exit_menu
    {
    items =
        {
        MENU_ITEM { command = EAknCmdExit; txt = qtn_appl_exit; }
        };
    }

RESOURCE STATUS_PANE_APP_MODEL r_gosip_phonebook_status_pane
    {
	panes =
		{
		SPANE_PANE
			{
			id = EEikStatusPaneUidNavi;
			type = EAknCtNaviPane;
			resource = r_gosip_navi_decorator;
			}
		};
    }

