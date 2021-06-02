#pragma once
#include "employee.h"

class f_emp: public employee
{
    double fixed_salary;
public:
    f_emp();
    f_emp(std::string name, std::string surname, int id, double fixed_salary);
     
};