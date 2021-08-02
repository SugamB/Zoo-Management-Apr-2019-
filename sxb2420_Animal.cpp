#include "sxb2420_Animal.h"

Animal::Animal() {}

std::string Animal::get_name() const
{
	return name;
}

void Animal::set_name(std::string n)
{
	name = n;
}

int Animal::get_id_number() const
{
	return id_number;
}

void Animal::set_id_number(int id)
{
	id_number = id;
}

bool Animal::get_gender() const
{
	return gender;
}

void Animal::set_gender(bool g)
{
	gender = g;
}

int Animal::get_age() const
{
	return age;
}

void Animal::set_age(int a)
{
	age = a;
}

std::string Animal::get_health_status() const
{
	return health_status;
}

void Animal::set_health_status(std::string hs)
{
	health_status = hs;
}

std::string Animal::get_type() const
{
	return type;
}

void Animal::set_type(std::string t)
{
	type = t;
}

std::string Animal::get_species() const
{
	return species;
}

void Animal::set_species(std::string s)
{
	species = s;
}


 std::string Animal::act() const
{
	return  "is an animal";

}

void Animal::save_database(std::ofstream& myfile)
{
	myfile<<name<<"\n"<<id_number<<"\n"<<gender<<"\n"<<age<<"\n"<<health_status<<"\n"<<type<<"\n"<<species<<"\n";
}

bool Animal::operator==(Animal animal) const
{
	return id_number == animal.id_number;
}

std::string Animal::to_string() const
{
	std::ostringstream oss;
	oss <<"Name: "<<name << " ID: " << id_number << " Gender: " << gender << " Age: " << age << " Health: " << health_status << " Type: " << type<<" "<<" Species: "<<species;
	oss<< "--------> It "<< act();
	return oss.str();
}


std::ostream& operator<<(std::ostream& ost, const Animal& animal)
{
	ost<<animal.to_string();
	return ost;
}
