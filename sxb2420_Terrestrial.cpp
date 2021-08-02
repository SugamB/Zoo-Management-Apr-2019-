#include "sxb2420_Terrestrial.h"
#include <iostream>

Terrestrial::Terrestrial() {}
Terrestrial::Terrestrial(std::string n,int id,bool g,int a,std::string hs,std::string t,std::string s) : Animal{n,id,g,a,hs,t,s}{}
std::string Terrestrial::act() const
{

	return "walks";
}

std::string Terrestrial::to_string() const
{
	std::ostringstream oss;
	oss <<"Name: "<<name << " ID: " << id_number << " Gender: " << gender << " Age: " << age << " Health: " << health_status << " Type: " << type<<" "<<" Species: "<<species;
	oss<< "--------> It "<< act();
	return oss.str();
}

std::ostream& operator<<(std::ostream& ost, const Terrestrial& terrestrial) 
{
	ost<<"Name: " << terrestrial.name <<" ID#: " << terrestrial.id_number << " Gender: " << terrestrial.gender << " Age: " << terrestrial.age << " Health: " << terrestrial.health_status << " Type: " << terrestrial.type<< " Species: " << terrestrial.species << "\n";
	ost << terrestrial.to_string();
	return ost;
}
