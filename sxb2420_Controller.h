#pragma once

#include "sxb2420_View.h"
#include "sxb2420_Animal.h"
#include "sxb2420_Zoo.h"
#include "sxb2420_Avian.h"
#include "sxb2420_Aquatic.h"
#include "sxb2420_Terrestrial.h"
#include "sxb2420_Amphibious.h"
#include <string>


class Controller 
{
private: 
	Zoo& zoo;
	View view{zoo};

public:

	Controller( Zoo& z, View& v);
	void cli();
	std::string execute_cmd(int cmd);
	void add_animal();
	void remove_animal();
	void change_capacity();
	std::string animal_of_id();
	std::string animal_of_type();
	std::string animal_of_species();
	void change_age();
	void change_health();
	std::string animal_of_act();

	
}; 