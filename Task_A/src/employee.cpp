#include "employee.h"

employee::employee(std::string name, std::string surname, int id) : name(name),surname(surname),id(id)
{}
employee::employee(std::string name, std::string surname, int id, double m_salary) : name(name),surname(surname),
                 id(id), m_salary(m_salary)
{}
std::string employee::get_name() const{ return name; }
std::string employee::get_surname()const { return surname; }
int employee::get_id() const  { return id; }
double employee::get_msalary() const{ return m_salary; }
void employee::set_msalary(double salary) { m_salary = salary; }
