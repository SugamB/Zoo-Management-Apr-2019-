#include "sxb2420_Avian.h"
#include <iostream>

Avian::Avian() {}
Avian::Avian(std::string n , int id , bool g , int a , std::string hs , std::string t , std::string s ) : Animal{ n, id, g, a, hs, t, s } {}
std::string Avian::act() const
{

	return "flies";
}

std::string Avian::to_string() const 
{
	std::ostringstream oss;
	oss <<"Name: "<<name << " ID: " << id_number << " Gender: " << gender << " Age: " << age << " Health: " << health_status << " Type: " << type<<" "<<" Species: "<<species;
	oss<< "--------> It "<< act();
	return oss.str();
}

std::ostream& operator<<(std::ostream& ost, const Avian& avian) 
{
	ost<<"Name: " << avian.name <<" ID#: " << avian.id_number << " Gender: " << avian.gender << " Age: " << avian.age << " Health: " << avian.health_status << " Type: " << avian.type<< " Species: " <<avian.species << "\n";
	ost << avian.to_string();
	return ost;
}
