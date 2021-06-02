#pragma once
#include "fixed_emp.h"
#include "hour_employee.h"
#include <vector>

class staff{
    std::vector<employee *> collection;
public:
    staff() = default;

    void add_employee();
    
};