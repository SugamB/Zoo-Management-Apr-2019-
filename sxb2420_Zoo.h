#pragma once
#include <map>
#include <vector>
#include "sxb2420_Animal.h"
#include "sxb2420_Avian.h"
#include "sxb2420_Aquatic.h"
#include "sxb2420_Terrestrial.h"
#include "sxb2420_Amphibious.h"
class Zoo
{
	public:
		Zoo(int c = 10) ;
		~ Zoo();		
		int get_capacity() const;
		void set_capacity(int);
		bool add_animal(Animal* animal);
		std::vector<Animal*> get_animals_of_type(std::string) const;
		std::vector<Animal*> get_animals_of_species(std::string) const;
		std::vector<Animal*> get_animals_of_act(std::string) const;
		bool save_data(std::string s);
		bool load_data(std::string s);
		Animal* get_animal_of_id(int id); 
		bool is_animal_in_zoo(int) const;
		void remove_animal(int);
		void change_animal_age(int, int);
		void change_animal_health_status(int, std::string);
		friend std::ostream& operator<<(std::ostream&, const Zoo&);

	private:
		std::map<std::string,std::vector<Animal*>> zoo;
		int capacity;
};
