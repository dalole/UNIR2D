include(CMakeParseArguments)

function(set_public_symbols_hidden target)
    # ensure public symbols are hidden by default (exported ones are explicitly marked)
    set_target_properties(${target} PROPERTIES
        CXX_VISIBILITY_PRESET hidden
        VISIBILITY_INLINES_HIDDEN YES
    )
endfunction()

macro(unir2d_add_library module)
    cmake_parse_arguments(THIS "STATIC" "DEPENDENCIES" "SOURCES" ${ARGN})
    if(NOT "${THIS_UNPARSED_ARGUMENTS}" STREQUAL "")
        message(FATAL_ERROR "Extra unparsed arguments when calling unir2d_add_library: ${THIS_UNPARSED_ARGUMENTS}")
    endif()

    string(TOLOWER unir2d-${module} target)
    if(THIS_STATIC)
        add_library(${target} STATIC ${THIS_SOURCES})
    else()
        add_library(${target} ${THIS_SOURCES})
    endif()
    add_library(UNIR2D::${module} ALIAS ${target})

    # enable C++17 support
    target_compile_features(${target} PUBLIC cxx_std_17)
    set_public_symbols_hidden(${target})

    # define the export symbol of the module
    string(REPLACE "-" "_" NAME_UPPER "${target}")
    string(TOUPPER "${NAME_UPPER}" NAME_UPPER)
    set_target_properties(${target} PROPERTIES DEFINE_SYMBOL ${NAME_UPPER}_EXPORTS)

    set_target_properties(${target} PROPERTIES EXPORT_NAME UNIR2D::${module})
    set_target_properties(${target} PROPERTIES FOLDER "UNIR2D")

    if(BUILD_SHARED_LIBS)
        set(config_name "Shared")
    else()
        set(config_name "Static")
    endif()

    install(TARGETS ${target} EXPORT UNIR2D${module}${config_name}Targets
            RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT bin
            LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT bin
            ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT devel
            FRAMEWORK DESTINATION "." COMPONENT bin)

    target_include_directories(${target}
        PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        PRIVATE ${PROJECT_SOURCE_DIR}/src
    )
endmacro()