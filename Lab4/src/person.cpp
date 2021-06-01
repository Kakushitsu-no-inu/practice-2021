#include "person.h"
#include <iostream>

person::person(std::string name, std::string surname): name(name), surname(surname){}

void person::print(){
    std::cout << name << " " << surname << " ";
}
