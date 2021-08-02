#include "sxb2420_Controller.h"
#include <vector>
#include <exception>
#include <bits/stdc++.h>
#include <gtkmm.h>

Controller::Controller(Zoo& z, View& v): zoo{z}, view{v} {}

// void Controller:: cli()
// {
// 	int option;
// 	while (true)
// 	{
// 		//view.main_menu();
// 		//std:: cin>>option;
// 		option = view.main_menu();
// 		//std:: cin.ignore();

// 		if(option<0 || option>12) 
// 		{
// 			view.message("Wrong input. Try again");						//std::cerr<<"Wrong input. Try again!"<<std::endl;
// 			continue; 
// 		}
// 		else if (option == 0)
// 		{
// 			break;
// 		}
// 		execute_cmd(option);	
// 	}

// }

std::string Controller::execute_cmd(int cmd)
{
	switch(cmd)
	{
		case 1: 
		{ //View Animals
			return view.view_zoo(zoo);	//std::cout << zoo << std::endl;
			break;
		}

		case 2:
		{ //Add an animal to the system
			add_animal();
			view.view_zoo(zoo);
			break;
		}
		
		case 3:
		{//Remove an animal from the system
			remove_animal();
			//view.view_zoo(zoo);
			break;
		}

		case 4:
		{//Change the capacity of zoo
			change_capacity();
			break;
		}

		case 5:
		{//Individual animal with an id
			return animal_of_id();
			break;
		}

		case 6:
		{//animals of certain type
			return animal_of_type();
			break;
		}

		case 7:
		{//animals of certain species
			return animal_of_species();
			break;
		}

		case 8:
		{//change the age
			change_age();
			break;
		}

		case 9:
		{// change the health status
			change_health();
			break;
		}

		case 10:
		{//animals of an exihibit "act"
			return animal_of_act();
			break;
		}

		case 11:
		{//save to file
			// if((zoo.save_data("sxb2420_save_file.txt")) == true) 
			//  view.message("Save complete");
			//  else view.message("Save incomplete");
			// break;
    
    std::string CANCEL_X = "Exit";
    Gtk::FileChooserDialog dialog("Please choose a file",Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
  
    auto filter_text = Gtk::FileFilter::create();
    filter_text->set_name("Text files");
    filter_text->add_mime_type("text/plain");
    dialog.add_filter(filter_text);
    
    dialog.set_filename("untitled.txt");

    dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    dialog.add_button("_Save", Gtk::RESPONSE_OK);

    auto result = dialog.run();

    if (result == Gtk::RESPONSE_OK) {
         zoo.save_data(dialog.get_filename());
       
        } else {
        	view.message("Unable to save", "Error");
//           GtkMessageDialog("####Unable to save to " + dialog.get_filename(), "ERROR");
        }
        view.message("File has been saved successfully...", "info");
        break;

    }
    

		case 12: 
		{ //load from file
			//  if((zoo.load_data("sxb2420_save_file.txt")) == true)
			//  {
			//  view.message("Load complete", "info");  view.message("Please press 1 to view the animals", "info");
			//  } 
			//  else 
			//  	{
			//  		view.message("Load incomplete");
			//  	}
			// break;

		Gtk::FileChooserDialog dialog("Please choose a file",Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);

        auto filter_text = Gtk::FileFilter::create();
        filter_text->set_name("Text files");
        filter_text->add_mime_type("text/plain");
        dialog.add_filter(filter_text);

        dialog.set_filename("untitled.txt");

        dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
        dialog.add_button("_Open", Gtk::RESPONSE_OK);

        int result = dialog.run();


        if (result == Gtk::RESPONSE_OK) 
        {
            zoo.load_data(dialog.get_filename());
            }
        else{
        		view.message("Unable to load", "Error");;
            }

       //view.message("Choose View to view the animals", "Load Complete");
    break;
		}
	}

	return "";
}



void Controller::add_animal()
{				

				//view.message(std::to_string(zoo.get_capacity()));
				bool check = true;
				std::vector<std::string> animal_info = view.prompt_all();
				if (animal_info.size()==0 ) return;
				std::string s1 = animal_info[6];
				std::transform(s1.begin(), s1.end(), s1.begin(), ::toupper);

				if(s1== "AQUATIC"){
					check= zoo.add_animal(new Aquatic(animal_info[0], std::stoi(animal_info[1]), std::stoi(animal_info[2]), std::stoi(animal_info[3]), animal_info[4],animal_info[5],animal_info[6]));
				}

				else if(s1== "AVIAN"){
					check= zoo.add_animal(new Avian(animal_info[0], std::stoi(animal_info[1]), std::stoi(animal_info[2]), std::stoi(animal_info[3]), animal_info[4],animal_info[5],animal_info[6]));
				}
				else if(s1== "TERRESTRIAL"){
					check= zoo.add_animal(new Terrestrial(animal_info[0], std::stoi(animal_info[1]), std::stoi(animal_info[2]), std::stoi(animal_info[3]), animal_info[4],animal_info[5],animal_info[6]));
				}
				else if(s1== "AMPHIBIOUS"){
					check= zoo.add_animal(new Amphibious(animal_info[0], std::stoi(animal_info[1]), std::stoi(animal_info[2]), std::stoi(animal_info[3]), animal_info[4],animal_info[5],animal_info[6]));
				}

				if(check==false) 
				{
					view.message("Sorry, No more animals can be added. Update the capacity of zoo");					//std::cout<<"Sorry, No more animals can be added. Update the capacity of zoo"<<std::endl;
				}
}


void Controller::remove_animal()
{
			int id_number;
			id_number=stoi(view.prompt("id of animal you want to remove"));							//std::cout << "Insert id of animal you want to remove" << std::endl;
			//std::cin >> id_number;
			zoo.remove_animal(id_number);
			view.view_zoo(zoo);						//std::cout << zoo << std::endl;
}

void Controller::change_capacity()
{
		int cap;
		cap=stoi(view.prompt("new capacity of zoo"));							//std::cout<<"What is the new capacity of zoo?" <<std::endl;
		//std::cin>>cap;
		zoo.set_capacity(cap);
}


std::string Controller::animal_of_id()
{
		int id;
		id = stoi(view.prompt("id of animal you want to see"));									//std::cout << "Enter the id of animal you want to see" << std::endl;
		//std::cin >> id;
		if(zoo.is_animal_in_zoo(id) == true)
		{
			auto a = zoo.get_animal_of_id(id);
			std::vector<Animal*> v;
			v.push_back(a);
			return view.show_animal(v);									//std::cout<<zoo.get_animals_of_id(id)<<std::endl;
		}
		else 
		{
			return "Sorry, no animal found";						//std::cout<<"Sorry, no animal found"<<std::endl;
		}
}


std::string Controller::animal_of_type()
{
		std::string type;
		type=view.prompt("type of animal you want to see");								//std::cout << "Which type of animal do want to see" << std::endl;
		//std::cin >> type;
		auto vec = zoo.get_animals_of_type(type);
		//for(Animal* a : vec)
		return view.show_animal(vec);  				//std::cout << a << std::endl;		
}

std::string Controller::animal_of_species()
{
		std::string species;
		species=view.prompt("species of animal you want to see");								//std::cout << "Which type of animal do want to see" << std::endl;
		//std::cin >> species;
		auto vec = zoo.get_animals_of_species(species);
		//for(Animal* a : vec)
		return view.show_animal(vec);  				//std::cout << a << std::endl;		
}


void Controller::change_age()
{
		int id_number;
		int age;
		id_number= stoi(view.prompt("id of animal you want change the age of"));									//std::cout << "Insert id of animal you want change the age of?" << std::endl;
		//std::cin >> id_number;
		age=stoi(view.prompt("new age"));									//std::cout << "What is the new age?" << std::endl;
		//std::cin >> age;
		zoo.change_animal_age(id_number, age);
		view.view_zoo(zoo);		//std::cout << zoo << std::endl;
}

void Controller::change_health()
{		
		int id_number;
		std::string health_status;
		id_number= stoi(view.prompt("id of animal you want change the health status of"));								//std::cout << "Insert id of animal you want change the health status of?" << std::endl;
		//std::cin >> id_number;
		health_status=view.prompt("new health status");							//std::cout << "What is the new health status?" << std::endl;
		//std::cin >> health_status;
		zoo.change_animal_health_status(id_number, health_status);
		view.view_zoo(zoo);											//std::cout << zoo << std::endl;
}

std::string Controller::animal_of_act()
{
		std::string act;
		act=view.prompt("act of animal you want to see");								//std::cout << "Which type of animal do want to see" << std::endl;
		//std::cin >> act;
		if(act =="both"||act =="swims and walks"||act =="swim and walk"||act =="walk and swim"||act =="walks and swims"||act =="walks swims"||act =="swims walks")
		act = "walks and swims";
		auto vec = zoo.get_animals_of_act(act);
		//for(Animal* a : vec)
		return view.show_animal(vec);  				//std::cout << a << std::endl;		
}
