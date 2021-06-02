set(INC include/)

set(SRC src/)

simple_lib(NAME employee_lib SOURCES ${INC} ${SRC})

add_executable(TaskA main.cpp)
target_link_libraries(TaskA PRIVATE employee_lib)
