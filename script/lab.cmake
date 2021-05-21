function(MakeLab)
    include(CMakeParseArguments)
    cmake_parse_arguments(LAB "" "EXE" "SOURCES" ${ARGN})

    set(SRC ${LAB_SOURCES})
    set(EXEC ${LAB_EXE})

    add_executable(${EXEC})
    target_sources(${EXEC} PUBLIC ${SRC})
    target_include_directories(${EXEC} PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>/include)
endfunction()