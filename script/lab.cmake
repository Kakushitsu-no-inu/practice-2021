function(MakeLab)
    include(CMakeParseArguments)
    cmake_parse_arguments(LAB "TARGET" "SOURCES" ${ARGN})

    set(SRC ${LAB_SOURCES})
    set(EXEC ${LAB_TARGET})

    add_executable(${EXEC} ${SRC})
    target_include_directories(${EXEC} PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include)
endfunction()