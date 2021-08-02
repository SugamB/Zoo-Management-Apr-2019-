#pragma once
#include "sxb2420_Animal.h"

class Avian : public Animal {
public:
	Avian();
	Avian(std::string n , int id , bool g , int a , std::string hs , std::string t , std::string s );	
	std::string act() const override;
	std::string to_string() const override;
	friend std::ostream& operator<<(std::ostream&, const Avian& avian);

} ;