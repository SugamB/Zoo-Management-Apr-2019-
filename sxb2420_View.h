#pragma once

#include "sxb2420_Animal.h"
#include "sxb2420_Zoo.h"
#include <iostream>
#include <string>

class View 
{
private:
	Zoo& zoo;

public:
	View(Zoo& z);
	int main_menu();
	std::string view_zoo(Zoo&);
	std::vector<std::string> prompt_all();
	std::string prompt(std::string);
	void message(std::string ,std::string title = "Error");
	std::string show_animal(std::vector<Animal*>);
};