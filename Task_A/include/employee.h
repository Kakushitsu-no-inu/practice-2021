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

    std::string get_name()const ;
    std::string get_surname()const ;
    int get_id()const ;
    double get_msalary()const ;
    void set_msalary(double salary);
};
