#pragma once
#include "sxb2420_Animal.h"

class Terrestrial: virtual public Animal
{
public:
	Terrestrial();
	Terrestrial(std::string n , int id , bool g , int a , std::string hs , std::string t , std::string s );	
	std::string act() const override;
	std::string to_string() const override;
	friend std::ostream& operator<<(std::ostream&, const Terrestrial& terrestrial);
};