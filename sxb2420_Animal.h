#pragma once
#include <iostream>
#include <sstream>
#include <fstream>

class Animal 
{
	protected:
		std::string name;
		int id_number;
		bool gender;
		int age;
		std::string health_status;
		std::string type;	
		std::string species;

	public:
		Animal();
		Animal(std::string n, int id , bool g , int a , std::string hs , std::string t , std::string s ) : name(n), id_number(id), gender(g), age(a), health_status(hs), type(t), species(s) {} ;
		std::string get_name() const;
		int get_id_number() const;
		bool get_gender() const;
		int get_age() const;
		std::string get_health_status() const;
		std::string get_type() const;		
		std::string get_species() const;
		void set_name(std::string);
		void set_id_number(int);
		void set_gender(bool);
		void set_age(int);
		void set_health_status(std::string);
		void set_type(std::string);
		void set_species(std::string);
		void save_database(std::ofstream&);

		friend std::ostream& operator<<(std::ostream&, const Animal&);
		virtual std::string act()const;
		bool operator==(Animal animal) const;	
		virtual std::string to_string() const;
};