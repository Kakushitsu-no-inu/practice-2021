#include "hour_employee.h"

h_employee::h_employee() : employee(){}
h_employee::h_employee(std::string name, std::string surname, int id, int hourly_rate) : employee(name,surname,id), hourly_rate(hourly_rate)
{
    set_msalary(20.8 * 8 * hourly_rate);
}

int h_employee::get_hrate() { return hourly_rate; }

std::ostream& operator<<(std::ostream &out, const h_employee &obj) 
{
    out << obj.get_id() << std::endl;
    out << obj.get_name() << std::endl;
    out << obj.get_surname() << std::endl;
    out << (obj.get_msalary() / (20.8 * 8));
    return out;
}

