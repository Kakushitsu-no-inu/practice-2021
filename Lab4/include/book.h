#pragma once
#include "person.h"


class book : public person
{
    std::string address{}, tel{};
public:
    book();
    book(std::string name, std::string surname,std::string address, std::string tel);

};