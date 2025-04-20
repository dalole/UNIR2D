cmake_minimum_required(VERSION 3.22)
project(UNIR2D VERSION 0.1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG master
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

file(GLOB UNIR2D_HEADERS RELATIVE ${PROJECT_SOURCE_DIR} "include/UNIR2D/*")
set(UNIR2D_SOURCES ${UNIR2D_HEADERS})

add_library(UNIR2D ${UNIR2D_SOURCES})
target_compile_features(UNIR2D PRIVATE cxx_std_17)
target_link_libraries(UNIR2D PRIVATE SFML::Graphics)

include(CTest)
enable_testing()

