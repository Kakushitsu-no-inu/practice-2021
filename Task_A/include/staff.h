#pragma once
#include "fixed_emp.h"
#include "hour_employee.h"
#include <vector>
#include <fstream>


class staff{
    std::vector<employee *> collection;
public:
    staff() = default;

    void add_employee(employee*);
    void sort_();
    void last_ids();
    void print(int);
    void push_to_file();
    void load_from_file();
    void clear_();

    friend std::ostream &operator<<(std::ostream &out, const staff &obj);
    friend std::istream &operator>>(std::istream &in, const staff &obj);   
    ~staff();
};