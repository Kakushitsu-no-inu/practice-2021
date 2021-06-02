#pragma once
#include "employee.h"

class h_employee : public employee
{
    int hourly_rate;
public:
    h_employee();
    h_employee(std::string name, std::string surname, int id, int hourly_rate );

    friend std::ostream &operator<<(std::ostream &out, const h_employee &obj);
    int get_hrate();
