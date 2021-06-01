#pragma once 
#include <string>

class person
{
    std::string name, surname;
public:
    person() = default;
    person(std::string name, std::string surname);

    virtual void print();
};