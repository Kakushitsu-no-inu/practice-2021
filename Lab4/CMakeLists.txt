set(INC include/book.h include/person.h include/register.h)

set(SRC src/book.cpp src/person.cpp src/register.cpp)

simple_lib(NAME book_lib SOURCES ${INC} ${SRC})

include(FetchContent)
FetchContent_Declare(
    menu
    GIT_REPOSITORY https://github.com/nesterpnyi/text-menu
    GIT_TAG 0.0.1
)
FetchContent_MakeAvailable(menu)

add_executable(main4 main.cpp)
target_link_libraries(main4 PRIVATE book_lib)
target_link_libraries(main4 PRIVATE menu)