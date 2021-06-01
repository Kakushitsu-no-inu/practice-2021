set(INC include/simple_s.h)
set(SRC src/simple_s.cpp)

simple_lib(NAME simple_str SOURCES ${INC} ${SRC})

add_executable(main3 main.cpp)
target_link_libraries(main3 PRIVATE simple_str)
