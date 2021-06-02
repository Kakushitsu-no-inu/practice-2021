#include "fixed_emp.h"

f_emp::f_emp() : employee(){}
f_emp::f_emp(std::string name, std::string surname, int id, double fixed_salary): employee(name,surname,id,fixed_salary){}