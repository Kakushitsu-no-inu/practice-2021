#include "fixed_emp.h"

f_emp::f_emp() : employee(){}
f_emp::f_emp(std::string name, std::string surname, int id, double fixed_salary): employee(name,surname,id,fixed_salary){}


std::ostream& operator<<(std::ostream &out, const f_emp &obj) 
{
    out << obj.get_id() << std::endl;
    out << obj.get_name() << std::endl;
    out << obj.get_surname() << std::endl;
    out << obj.get_msalary();
    return out;
}
