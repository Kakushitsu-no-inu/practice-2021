function(simple_lib)
    include(CMakeParseArguments)
    cmake_parse_arguments(
        PARSED_ARGS
        ""
        "NAME"
        "SOURCES"
        ${ARGN}
    )

    set(src ${PARSED_ARGS_SOURCES})
    set(lib ${PARSED_ARGS_NAME})
    add_library(${lib} STATIC)
    add_library(${lib}::${lib} ALIAS ${lib})
    target_include_directories(${lib} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
   target_sources(${lib} PUBLIC ${src})
endfunction(simple_lib)