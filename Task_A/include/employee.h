#pragma once 
#include <string>
#include <iostream>

class employee{
    std::string name, surname;
    int id;
    double m_salary;

public:
    employee() = default;
    employee(std::string name, std::string surname, int id);
    employee(std::string name, std::string surname, int id, double m_salary);

    std::string get_name();
    std::string get_surname();
    int get_id();
    double get_msalary();
    void set_msalary(double salary);


};
