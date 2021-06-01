#include "person.h"
#include <iostream>

person::person(std::string name, std::string surname): name(name), surname(surname){}

void person::print(){
    std::cout << name << " " << surname << " ";
}

std::string person::get_name() const { return name; }
std::string person::get_surname() const { return surname; }

void person::set_name_surname(std::string n,std::string s)
{
    name = n;
    surname = s;
}