#include "sxb2420_View.h"
#include <exception>

#include <bits/stdc++.h>
#include <gtkmm.h>
#include <sstream>


View::View(Zoo& z): zoo{z} {}


int View::main_menu()
{
	std::string menu = R"(
==============================
CSE 1325 Zoo Management System
==============================

Main menu 
------------------------------
(1) View all animals
(2) Add an animal
(3) Remove an animal
(4) Change the zoo’s capacity
(5) Get an individual animal given an id
(6) Get all animals of a certain type
(7) Get all animals of a certain species
(8) Change an animal’s age
(9) Change an animal’s health status
(10) Get all animals in an exhibit "act"
(11) Save to file
(12) Load from file 
(0) Exit

Input?
	)";
//	std::cout<<menu<<std::endl;
	Gtk::Dialog *dialog = new Gtk::Dialog();
	dialog-> set_title("CSE 1325 Zoo Management System");

	Gtk::Label *label = new Gtk::Label(menu);
	dialog->get_content_area()->pack_start(*label);
	label->show();

	dialog-> add_button("Cancel",0);
	dialog-> add_button("OK", 1);
	dialog-> set_default_response(1);


	Gtk::Entry *entry = new Gtk::Entry{};
	entry->set_text("Enter a valid number here");
	entry->set_max_length(50);
	entry->show();
	dialog->get_vbox()->pack_start(*entry);

	int result= dialog->run();

	if (result == 0) 
		{
			return 0;
		}
//	if (result =1)
	std::string text = entry->get_text();
	if(text == "Enter a valid number here")
		return 13;

	dialog->close();
	while(Gtk::Main::events_pending()) Gtk::Main::iteration();

	return stoi(text);
}


std::vector<std::string> View::prompt_all()
{	
	int id_number;
	int gender;
	int age;
	
	
	std::vector<std::string> animal_info;
	
	Gtk::Dialog *dialog = Gtk::manage(new Gtk::Dialog ("Animal info"));
	Gtk::HBox b_name;

	Gtk::Label label_name{"Name: "};
	label_name.set_width_chars(15);
	b_name.pack_start(label_name, Gtk::PACK_SHRINK);
	
	Gtk::Entry e_name;
	e_name.set_max_length(50);
	b_name.pack_start(e_name, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);


	Gtk::HBox b_id;

	Gtk::Label label_id{"Id: "};
	label_id.set_width_chars(15);
	b_id.pack_start(label_id, Gtk::PACK_SHRINK);
	
	Gtk::Entry e_id;
	e_id.set_max_length(50);
	b_id.pack_start(e_id, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(b_id, Gtk::PACK_SHRINK);
	

	Gtk::HBox b_gender;

	Gtk::Label label_gender{"Gender: "};
	label_gender.set_width_chars(15);
	b_gender.pack_start(label_gender, Gtk::PACK_SHRINK);
	
	Gtk::Entry e_gender;
	e_gender.set_max_length(50);
	b_gender.pack_start(e_gender, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(b_gender, Gtk::PACK_SHRINK);

	Gtk::HBox b_age;

	Gtk::Label label_age{"Age: "};
	label_age.set_width_chars(15);
	b_age.pack_start(label_age, Gtk::PACK_SHRINK);
	
	Gtk::Entry e_age;
	e_age.set_max_length(50);
	b_age.pack_start(e_age, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(b_age, Gtk::PACK_SHRINK);

	Gtk::HBox b_hs;

	Gtk::Label label_hs{"Health Status: "};
	label_hs.set_width_chars(15);
	b_hs.pack_start(label_hs, Gtk::PACK_SHRINK);
	
	Gtk::Entry e_hs;
	e_hs.set_max_length(50);
	b_hs.pack_start(e_hs, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(b_hs, Gtk::PACK_SHRINK);


	Gtk::HBox b_type;

	Gtk::Label label_type{"Type: "};
	label_type.set_width_chars(15);
	b_type.pack_start(label_type, Gtk::PACK_SHRINK);
	
	Gtk::Entry e_type;
	e_type.set_max_length(50);
	b_type.pack_start(e_type, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(b_type, Gtk::PACK_SHRINK);


	Gtk::HBox b_species;

	Gtk::Label label_species{"Species: "};
	label_species.set_width_chars(15);
	b_species.pack_start(label_species, Gtk::PACK_SHRINK);
	
	Gtk::Entry e_species;
	e_species.set_max_length(50);
	b_species.pack_start(e_species, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(b_species, Gtk::PACK_SHRINK);
	

	dialog-> add_button("Cancel",0);
	dialog-> add_button("OK", 1);
	dialog-> set_default_response(1);
	dialog-> show_all();

	int result;
	bool error = true;

	while(error){
		error=false;
		result=dialog->run();
		if (result!=1) {delete dialog; return animal_info;}
		try{
			id_number = std::stoi(e_id.get_text());
		}
			catch(std::exception e)
			{
				e_id.set_text("!!!!Invalid Input");
				error =true;
			}
		try{
			gender = std::stoi(e_gender.get_text());
			}
			catch(std::exception e)
			{
				e_gender.set_text("!!!!Invalid Input!!!!");
				error =true;
			}

			try{
			if (gender != 0 && gender!= 1) {throw 20;}
		}
	
	catch (int x){
					e_gender.set_text("Gender must be 0 or 1");
				error =true;

	}

		try{
			age = std::stoi(e_age.get_text());
		}
			catch(std::exception e)
			{
				e_age.set_text("!!!!Invalid Input!!!");
				error =true;
			}
			std::string s1 =e_species.get_text();
			std::transform(s1.begin(), s1.end(), s1.begin(), ::toupper);

		if ((s1 != "AQUATIC") && (s1 != "TERRESTRIAL") && (s1 !="AVIAN") && (s1 !="AMPHIBIOUS"))
		{
			e_species.set_text("!!!Invalid Input!!!");
			error= true;
		}
		else {
			if(s1 == "AQUATIC") e_species.set_text("Aquatic");
			else if(s1 == "TERRESTRIAL") e_species.set_text("Terrestrial");
			else if(s1 == "AVIAN") e_species.set_text("Avian");
			else if(s1 == "AMPHIBIOUS") e_species.set_text("Amphibious");
		}

	}

	animal_info.push_back(e_name.get_text());
	animal_info.push_back(e_id.get_text());
	animal_info.push_back(e_gender.get_text());
	animal_info.push_back(e_age.get_text());
	animal_info.push_back(e_hs.get_text());
	animal_info.push_back(e_type.get_text());
	animal_info.push_back(e_species.get_text());

	delete dialog;

	return animal_info;


}

std::string View::prompt(std::string prompt)
{
//	std::cout<<"Insert the "<<prompt<<std::endl;
	std::string insert="Insert the " + prompt;
	Gtk::Dialog *dialog = new Gtk::Dialog();
	dialog-> set_title("CSE 1325 Zoo Management System");

	Gtk::Label *label = new Gtk::Label(insert);
	dialog->get_content_area()->pack_start(*label);
	label->show();

	dialog-> add_button("Cancel",0);
	dialog-> add_button("OK", 1);
	dialog-> set_default_response(1);


	Gtk::Entry *entry = new Gtk::Entry{};
	entry->set_text("Type here");
	entry->set_max_length(50);
	entry->show();
	dialog->get_vbox()->pack_start(*entry);

	int result= dialog->run();

	if (result == 0) 
		{
			return 0;
		}

	std::string text = entry->get_text();
	if(text == "Type here")
		return "nothing to display";

	dialog->close();
	while(Gtk::Main::events_pending()) Gtk::Main::iteration();

	return text;

}

void View::message(std::string msg, std::string title)
{
	//std::cout<< msg << "!!"<<std::endl;	
	Gtk::MessageDialog *dialog =new Gtk::MessageDialog(title);
	dialog->set_secondary_text(msg, true);
	dialog->run();

	dialog-> close();

	delete dialog;
}

std::string View::show_animal(std::vector<Animal*> vec)
{
	//std::cout<< *a << std::endl;
		std::stringstream ss;
		if(vec.size() == 0) return " Nothing to show.";
		std::string menu = R"(
=====================================
Animals in the system are as follows:		
=====================================
	)";
	ss<<menu<<std::endl;
		std::vector<std::string> type_check;
		ss<<vec[0]->get_species()<<std::endl;
		for(Animal* a : vec)
		{
			int y =0;
			for(int i =0; i<type_check.size();i++)
			{
				if(a->get_type() == type_check[i])
				{
					y = 1;
				break;
				}
			}
			if (y !=1)
			{
				ss<<"  "<<a->get_type()<<std::endl;
				for(Animal* b : vec)
				{
					if(b->get_type()==a->get_type())
					{
						ss<<"      "<< b->to_string() << std::endl;	
					}
				}
			type_check.push_back(a->get_type());
			}
		}
	//Gtk::MessageDialog *dialog =new Gtk::MessageDialog("Title");
	//dialog->set_secondary_text(ss.str(), true);
	//dialog->run();

	//dialog-> close();

	//delete dialog;


	// std::cout << x.first << std::endl;
	// std::vector<std::string> type_check;
	// for(Animal* a : x.second)
	// 	{
	// 		int y =0;
	// 		for(int i =0; i<type_check.size();i++)
	// 		{
	// 			if(a->get_type() == type_check[i])
	// 			{
	// 				y = 1;
	// 			break;
	// 			}
	// 		}
	// 		if (y !=1)
	// 		{
	// 			std::cout<<"  "<<a->get_type()<<std::endl;
	// 			for(Animal* b : x.second)
	// 			{
	// 				if(b->get_type()==a->get_type())
	// 				{
	// 					std::cout<<"      "<< b->to_string() << std::endl;	
	// 				}
	// 			}
	// 		type_check.push_back(a->get_type());
	// 		}
	// 	}
	return ss.str();
}

std::string View::view_zoo(Zoo& z)
{
	std::stringstream ss;
	std::string menu = R"(
=====================================
Animals in the system are as follows:		
=====================================
	)";
	ss<<menu<<std::endl;
	ss<< z <<std::endl;

	//Gtk::MessageDialog *dialog =new Gtk::MessageDialog(" ");
	//dialog->set_secondary_text(ss.str(), true);
	//dialog->run();

	//dialog-> close();

	//delete dialog;

	return ss.str();
}