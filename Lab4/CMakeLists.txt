set(INC include/book.h include/person.h)

set(SRC src/book.cpp src/person.cpp)

simple_lib(NAME book_lib SOURCES ${INC} ${SRC})


add_executable(main4 main.cpp)
target_link_libraries(main4 PRIVATE book_lib)