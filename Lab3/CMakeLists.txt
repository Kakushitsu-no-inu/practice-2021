set(INC include/simple_s.h)
set(SRC src/simple_s.cpp)

simple_lib(NAME simple_str SOURCES ${INC} ${SRC})

add_executable(main3 main.cpp)
target_link_libraries(main3 PRIVATE simple_str)
# include(FetchContent)
# FetchContent_Declare(
#     fmt
#     GIT_REPOSITORY "https://github.com/fmtlib/fmt.git"
#     GIT_TAG 0889856d6160775462e9e0722d121aab0e75e873
# )
# FetchContent_MakeAvailable(fmt)