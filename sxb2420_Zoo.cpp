#include "sxb2420_Zoo.h"
#include <fstream>

Zoo::Zoo(int c) : capacity{c}{}
	Zoo::~Zoo(){}
int Zoo::get_capacity() const
{
	return capacity;
}

void Zoo::set_capacity(int c)
{
	capacity = c;
}

bool Zoo::add_animal(Animal* animal)
{

	int animals_in_zoo = 0;
	for(auto x : zoo)
	{
		animals_in_zoo += x.second.size();
	}
	if(animals_in_zoo >= capacity)
		return false;
	
	for(auto x : zoo)
	{
		for(Animal* a : x.second)
		{
			if(*animal == *a)
				return false;
		}
	}
	
	if(zoo.count(animal->get_species()) == 1)
	{
		zoo.at(animal->get_species()).push_back(animal);
	}
	else
	{
		
		zoo.insert(std::pair<std::string, std::vector<Animal*>>(animal->get_species(), {animal}));
	}
	
	return true;
}

std::vector<Animal*> Zoo::get_animals_of_type(std::string type) const
{

	std::vector<Animal*> data;
	for(auto x : zoo)
	{
		for(Animal* a : x.second)
		{
			if(a->get_type() == type)
				data.push_back(a);
				
		}
	}

	return data;
}

std::vector<Animal*> Zoo::get_animals_of_species(std::string species) const
{
	return zoo.at(species);
}

std::vector<Animal*> Zoo::get_animals_of_act(std::string act) const
{
	std::vector<Animal*> data;
	for(auto x : zoo)
	{
		for(Animal* a : x.second)
		{
			if(a->act() == act)
				data.push_back(a);
				
		}
	}

	return data;
}


bool Zoo::is_animal_in_zoo(int id) const
{
	for(auto x : zoo)
	{
		for(Animal* a : x.second)
		{
			if(a->get_id_number() == id)
				return true; 
		}
	}
	
	return false;
}

Animal* Zoo::get_animal_of_id(int id)
{
	for(auto x : zoo)
	{
		for(Animal* a : x.second)
		{
			if(a->get_id_number() == id)
				return a; 
		}
	}

}
void Zoo::remove_animal(int id)
{
	auto map_it = zoo.begin();
	for(;map_it != zoo.end(); map_it++)
	{
		auto vec_it = map_it->second.begin();
		for(; vec_it != map_it->second.end(); vec_it++)
		{
			if((*vec_it)->get_id_number() == id)
				{
					map_it->second.erase(vec_it);
					break;
				}
		}
		if(map_it->second.size()==0){
			zoo.erase(map_it->first);

		}
	}
}

void Zoo::change_animal_age(int id, int age)
{
	auto map_it = zoo.begin();
	for(;map_it != zoo.end(); map_it++)
	{
		auto vec_it = map_it->second.begin();
		for(; vec_it != map_it->second.end(); vec_it++)
		{
			if((*vec_it)->get_id_number() == id)
				{
					(*vec_it)->set_age(age);
				}
		}
	}
}

void Zoo::change_animal_health_status(int id, std::string status)
{
	auto map_it = zoo.begin();
	for(;map_it != zoo.end(); map_it++)
	{
		auto vec_it = map_it->second.begin();
		for(; vec_it != map_it->second.end(); vec_it++)
		{
			if((*vec_it)->get_id_number() == id)
				{
					(*vec_it)->set_health_status(status);
				}
		}
	}
}

std::ostream& operator<<(std::ostream& ost, const Zoo& zoo)
{
	for(auto x : zoo.zoo)
	{
		ost << x.first << std::endl;
		std::vector<std::string> type_check;
		for(Animal* a : x.second)
		{
			int y =0;
			for(int i =0; i<type_check.size();i++)
			{
				if(a->get_type() == type_check[i])
				{
					y = 1;
				break;
				}
			}
			if (y !=1)
			{
				ost<<"  "<<a->get_type()<<std::endl;
				for(Animal* b : x.second)
				{
					if(b->get_type()==a->get_type())
					{
						ost<<"      "<< b->to_string() << std::endl;	
					}
				}
			type_check.push_back(a->get_type());
			}
		}		
	}
	return ost;
}


bool Zoo::save_data(std::string s)
{
	std::ofstream myfile(s);
	if (myfile.is_open())
	{
		myfile<<capacity<<"\n";
		myfile<<zoo.size()<<"\n";
		for(auto x : zoo)
		{
		myfile<<x.first<<"\n";
		myfile<<(x.second).size()<<"\n";
		for (int i = 0; i <(x.second).size(); ++i)
			{
				(x.second)[i]->save_database(myfile);	
			}	
		}

	}
	else {
		return false; 
	}

	myfile.close();
	return true;

}

bool Zoo::load_data(std::string s)
{
	std::ifstream myfile(s);
	if (myfile.is_open())
	{
		myfile>>capacity;
		set_capacity(capacity);
		int size;
		myfile>>size;

		for (int i =0;i<size;i++)
		{
			std::string typevar;
			myfile>>typevar;
			std::vector<Animal*> vec;
			int vectorsize;
			myfile>>vectorsize;
			 for(int j = 0; j<vectorsize;j++)
			 {
				std::string name;
				int id_number;
				bool gender;
				int age;
				std::string health_status;
				std::string type;
				std::string s;
				myfile>>name;
				myfile>>id_number;
				myfile>>gender;
				myfile>>age;
				myfile>>health_status;
				myfile>>type;
				myfile>>s;

				if(s =="aquatic"||s=="Aquatic"){

					vec.push_back(new Aquatic(name, id_number, gender, age, health_status, type, s));
			//zoo.add_animal(new Aquatic{name,id,gen,age,hs,t,s});
		}
		else if(s =="avian"||s=="Avian"){

			vec.push_back(new Avian(name, id_number, gender, age, health_status, type, s));
			//zoo.add_animal(new Avian{name,id,gen,age,hs,t,s});

		}
		else if(s =="terrestrial"||s=="Terrestrial"){

			vec.push_back(new Terrestrial(name, id_number, gender, age, health_status, type, s));
			//zoo.add_animal(new Terrestrial{name,id,gen,age,hs,t,s});

			}
		else if(s =="amphibious"||s=="Amphibious"){

			vec.push_back(new Amphibious(name, id_number, gender, age, health_status, type, s));
			//zoo.add_animal(new Amphibious{name,id,gen,age,hs,t,s});
			 }
			}
			 zoo.insert(std::pair<std::string, std::vector<Animal*>>(typevar, vec));
		}
			
	}

	else {
		return false;
	}
		myfile.close();
		return true;

 }
