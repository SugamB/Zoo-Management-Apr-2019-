#pragma once
#include "sxb2420_Animal.h"
#include "sxb2420_Aquatic.h"
#include "sxb2420_Terrestrial.h"

class Amphibious: public Aquatic, public Terrestrial
{
public:
	Amphibious();
	Amphibious(std::string n , int id , bool g , int a , std::string hs , std::string t , std::string s );
	std::string act() const override;
	std::string to_string() const override;
	friend std::ostream& operator<<(std::ostream&, const Amphibious& amphibious);
};