#include "sxb2420_Mainwin.h"
#include <ostream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <regex>

Mainwin::Mainwin(Controller c): _controller{c}
{
	// /////////////////
    // G U I   S E T U P
    // /////////////////
	set_title("Zoo Management System");
    set_icon_from_file("zoo_logo.jpg");
    set_default_size(800, 300);

	// Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);

    main_display = Gtk::manage(new Gtk::Label);
    grid = Gtk::manage(new Gtk::Grid);
    // //////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
    vbox->pack_start(*grid, Gtk::PACK_SHRINK,0);
    
   


    // Gtk::ScrolledWindow scroll_window;
    // text_view = new Gtk::TextView();
    // text_view->set_editable(true);
    // scroll_window.add(*main_display);
    // scroll_window.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
    // scroll_window.set_hexpand(true);
    // scroll_window.set_vexpand(true);
    // text_buffer = text_view->get_buffer();
    // text_buffer->set_text("Hello!\n");
    // text_view->set_buffer(text_buffer);
    // grid->attach(scroll_window, 0, 0, 200, 100);


    // Gtk::Button add_button("add text");
    // add_button.signal_activate().connect(sigc::mem_fun(*this,&Mainwin::on_add_button_clicked));
    // grid->attach_next_to(add_button, scroll_window, Gtk::POS_BOTTOM, 1, 1);

    // Gtk::Button scroll_button("scroll to somewhere");
    // scroll_button.signal_activate().connect(sigc::mem_fun(*this,&Mainwin::on_scroll_button_clicked));
    // grid->attach_next_to(scroll_button, add_button, Gtk::POS_RIGHT, 1, 1);






















  //   Gtk::ScrolledWindow scroll_window;
  //   scroll_window.add(*main_display);
  //   scroll_window.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_ALWAYS);
  //   //scroll_window.set_hexpand(true);
  //   //scroll_window.set_vexpand(true);
   













       
    
    grid->set_row_spacing(10);
    grid->set_column_spacing(10);
    grid->attach(*main_display, 0, 1, 100, 50);




    //vbox->pack_start(*main_display, Gtk::PACK_SHRINK,0);
     //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);
	
	// Append Save to the File menu
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    menuitem_save->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::save_file_click));
    filemenu->append(*menuitem_save);

    // Append Load to the File menu
    Gtk::MenuItem *menuitem_load = Gtk::manage(new Gtk::MenuItem("_Load", true));
    menuitem_load->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::load_file_click));
    filemenu->append(*menuitem_load);

     // Append Exit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Exit", true));
    menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::quit_click));
    filemenu->append(*menuitem_quit);



    //     E D I T   
    // Create a Edit menu and add to the menu bar
    Gtk::MenuItem *menuitem_edit = Gtk::manage(new Gtk::MenuItem("_Edit", true));
    menubar->append(*menuitem_edit);
    Gtk::Menu *editmenu = Gtk::manage(new Gtk::Menu());
    menuitem_edit->set_submenu(*editmenu);

    //edit add animal
    Gtk::MenuItem *menuitem_addanimal = Gtk::manage(new Gtk::MenuItem("_Add animal", true));
    menuitem_addanimal->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::add_animal_click));
    editmenu->append(*menuitem_addanimal);

    //edit remove animal
    Gtk::MenuItem *menuitem_removeanimal = Gtk::manage(new Gtk::MenuItem("_Remove animal", true));
    menuitem_removeanimal->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::remove_animal_click));
    editmenu->append(*menuitem_removeanimal);

    //edit add animal
    Gtk::MenuItem *menuitem_changecap = Gtk::manage(new Gtk::MenuItem("_Change capacity", true));
    menuitem_changecap->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::change_capacity_click));
    editmenu->append(*menuitem_changecap);

    //edit add animal
    Gtk::MenuItem *menuitem_changeage = Gtk::manage(new Gtk::MenuItem("_Change age", true));
    menuitem_changeage->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::change_age_click));
    editmenu->append(*menuitem_changeage);

    //edit add animal
    Gtk::MenuItem *menuitem_changehealth = Gtk::manage(new Gtk::MenuItem("_Change health status", true));
    menuitem_changehealth->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::change_health_click));
    editmenu->append(*menuitem_changehealth);

    // Append Exit to the edit menu
    Gtk::MenuItem *menuitem_exit = Gtk::manage(new Gtk::MenuItem("_Exit", true));
    menuitem_exit->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::quit_click));
    editmenu->append(*menuitem_exit);


    //     V I E W
    // Create a View menu and add to the menu bar
    Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
    menubar->append(*menuitem_view);
    Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
    menuitem_view->set_submenu(*viewmenu);

    //view zoo
     Gtk::MenuItem *menuitem_viewzoo = Gtk::manage(new Gtk::MenuItem("_View zoo", true));
    menuitem_viewzoo->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::view_zoo_click));
    viewmenu->append(*menuitem_viewzoo);

    //view id animal
    Gtk::MenuItem *menuitem_idanimal = Gtk::manage(new Gtk::MenuItem("_View Animal by Id", true));
    menuitem_idanimal->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::animal_id_click));
    viewmenu->append(*menuitem_idanimal);

    //view type animal
    Gtk::MenuItem *menuitem_typeanimal = Gtk::manage(new Gtk::MenuItem("_View Animal by Type", true));
    menuitem_typeanimal->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::animal_type_click));
    viewmenu->append(*menuitem_typeanimal);

    //view species animal
    Gtk::MenuItem *menuitem_speciesanimal = Gtk::manage(new Gtk::MenuItem("_View Animal by Species", true));
    menuitem_speciesanimal->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::animal_species_click));
    viewmenu->append(*menuitem_speciesanimal);

    //view act animal
    Gtk::MenuItem *menuitem_actanimal = Gtk::manage(new Gtk::MenuItem("_View Animal by Act", true));
    menuitem_actanimal->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::animal_act_click));
    viewmenu->append(*menuitem_actanimal);


    vbox->show_all();
}

    Mainwin::~Mainwin() { }

    void Mainwin::view_zoo_click()
    {
         main_display->set_text(_controller.execute_cmd(1));
         //text_buffer->set_text(_controller.execute_cmd(1));
    }
    void Mainwin::animal_id_click()
    {
        main_display->set_text(_controller.execute_cmd(5));
          
    }
    void Mainwin::animal_type_click()
    {
        main_display->set_text(_controller.execute_cmd(6));
         
    }
    void Mainwin::animal_species_click()
    {
        main_display->set_text(_controller.execute_cmd(7));
         
    }
    void Mainwin::animal_act_click()
    {
        main_display->set_text(_controller.execute_cmd(10));
         
    }
  

    void Mainwin::add_animal_click() 
    {
        _controller.execute_cmd(2);
        main_display->set_text(_controller.execute_cmd(1));
    }
    void Mainwin::remove_animal_click()
    {
        _controller.execute_cmd(3);
        main_display->set_text(_controller.execute_cmd(1));
    }
    void Mainwin::change_capacity_click()
    {
        _controller.execute_cmd(4);
        main_display->set_text(_controller.execute_cmd(1));
    }
    void Mainwin::change_age_click()
    {
        _controller.execute_cmd(8);
        main_display->set_text(_controller.execute_cmd(1));
    }
    void Mainwin::change_health_click()
    {
        _controller.execute_cmd(9);
        main_display->set_text(_controller.execute_cmd(1));
    }
    

    void Mainwin::save_file_click()
    {
        _controller.execute_cmd(11);
    }
    void Mainwin::load_file_click(){
        _controller.execute_cmd(12);
        view_zoo_click();        
    }
    void Mainwin::quit_click()
    {
        close();
    }

    void Mainwin::on_add_button_clicked() {
    Glib::RefPtr<Gtk::TextBuffer> text_buffer = text_view->get_buffer();
    for (int i = 0; i != 100; ++i) {
        text_buffer->insert_at_cursor("foobar\n");
        }
    }

    void Mainwin::on_scroll_button_clicked() {
    Glib::RefPtr<Gtk::TextBuffer> text_buffer = text_view->get_buffer();
    Gtk::TextBuffer::iterator it = text_buffer->end();
    text_view->scroll_to(it, 0.49);
    }

