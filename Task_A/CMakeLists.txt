set(INC include/employee.h include/fixed_emp.h include/hour_employee include/staff.h)

set(SRC src/employee.cpp src/fixed_emp.cpp src/hour_employee.cpp src/staff.cpp)

simple_lib(NAME employee_lib SOURCES ${INC} ${SRC})

add_executable(TaskA main.cpp)
target_link_libraries(TaskA PRIVATE employee_lib)
