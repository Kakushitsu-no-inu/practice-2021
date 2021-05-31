set(INC include/file.h)
set(SRC src/file.cpp)

simple_lib(NAME file SOURCES ${INC} ${SRC})

add_executable(main2 files.cpp)
target_link_libraries(main2 PRIVATE file)

# add_executable(test2 test.cpp)
# target_link_libraries(test2
#     file
#     gtest_main
# )
# gtest_discover_tests(test2)

file(COPY 1.txt 2.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})