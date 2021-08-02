#include "sxb2420_Amphibious.h"

Amphibious::Amphibious(){}
Amphibious::Amphibious(std::string n , int id , bool g , int a , std::string hs , std::string t , std::string s ) : Aquatic{n, id, g, a, hs, t, s}, Terrestrial{n, id, g, a, hs, t, s}, Animal{n, id, g, a, hs, t, s} {}

std::string Amphibious::act() const
{

	return Terrestrial::act()+ " and " + Aquatic::act();
	//return "walks and swims";
}

std::string Amphibious::to_string() const
{std::ostringstream oss;
	oss <<"Name: "<<name << " ID: " << id_number << " Gender: " << gender << " Age: " << age << " Health: " << health_status << " Type: " << type<<" "<<" Species: "<<species;
	oss<< "--------> It "<< act();
	return oss.str();
}
std::ostream& operator<<(std::ostream& ost, const Amphibious& amphibious) 
{	
	ost<<"Name: " << amphibious.Animal::name <<" ID#: " << amphibious.Animal::id_number << " Gender: " << amphibious.Animal::gender << " Age: " << amphibious.Animal::age << " Health: " << amphibious.Animal::health_status << " Type: " << amphibious.Animal::type<< " Species: " << amphibious.Animal::species << "\n";
	ost << amphibious.to_string();
	return ost;
}
