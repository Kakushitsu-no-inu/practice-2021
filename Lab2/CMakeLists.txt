set(INC include/simple_f.h)
set(SRC src/simple_f.cpp)

simple_lib(NAME simple_f SOURCES ${INC} ${SRC})

add_executable(main2 files.cpp)
target_link_libraries(main2 PRIVATE simple_f)

add_executable(test2 test.cpp)
target_link_libraries(test2
    simple_f
    gtest_main
)
gtest_discover_tests(test2)