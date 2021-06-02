#pragma once
#include "employee.h"

class f_emp: public employee
{
    double fixed_salary;
public:
    std::string def{"fixed"};
    f_emp();
    f_emp(std::string name, std::string surname, int id, double fixed_salary);
    friend std::ostream& operator<<(std::ostream &out, const f_emp &obj);

};