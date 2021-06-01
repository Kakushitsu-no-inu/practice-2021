#pragma once 
#include <string>

class person
{
    std::string name, surname;
public:
    person() = default;
    person(std::string name, std::string surname);

    void set_name_surname(std::string n, std::string s);
    virtual void print();
    std::string get_name() const;
    std::string get_surname() const;
};