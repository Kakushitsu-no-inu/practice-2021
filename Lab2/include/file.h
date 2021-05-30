#pragma once
#include <iostream>
#include <fstream>

class file
{
    std::string name;
    std::fstream file_;
public:
    file(std::string name) : name(name)
    {
        file_.open(name);
    }
    
};