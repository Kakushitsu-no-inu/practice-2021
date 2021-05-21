set(INC include/array.h)
set(SRC src/array.cpp)

simple_lib(NAME array SOURCES ${INC} ${SRC})

add_executable(main1 main.cpp)
target_link_libraries(main1 PRIVATE array)

add_executable(test1 test.cpp)
target_link_libraries(test1
    array
    gtest_main
)
gtest_discover_tests(test1)