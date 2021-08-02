#pragma once
#include <gtkmm.h>
#include "sxb2420_Controller.h"

class Mainwin: public Gtk::Window
{
public:
	Mainwin(Controller c);
	virtual ~Mainwin();

protected:
	void view_zoo_click();
	void animal_id_click();
	void animal_type_click();
	void animal_species_click();
	void animal_act_click();
	
	void add_animal_click();
	void remove_animal_click();
	void change_capacity_click();
	void change_age_click();
	void change_health_click();
	
	void save_file_click();
	void load_file_click();
	void quit_click();

	void on_add_button_clicked();

	void on_scroll_button_clicked();



private:
	Controller _controller;
	Gtk::Label* main_display;
	Gtk::Grid* grid;
	Gtk::TextView* text_view;
	Glib::RefPtr<Gtk::TextBuffer> text_buffer;
};