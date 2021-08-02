#include "sxb2420_Aquatic.h"
#include <iostream>

Aquatic::Aquatic() {}

Aquatic::Aquatic(std::string n , int id , bool g , int a , std::string hs , std::string t , std::string s ) : Animal{ n, id, g, a, hs, t, s } {}
std::string Aquatic::act() const
{

	return "swims";
}

std::string Aquatic::to_string() const 
{
	std::ostringstream oss;
	oss <<"Name: "<<name << " ID: " << id_number << " Gender: " << gender << " Age: " << age << " Health: " << health_status << " Type: " << type<<" "<<" Species: "<<species;
	oss<< "--------> It "<< act();
	return oss.str();
}

std::ostream& operator<<(std::ostream& ost, const Aquatic& aquatic) 
{
	ost << aquatic.to_string();
	return ost;
}

