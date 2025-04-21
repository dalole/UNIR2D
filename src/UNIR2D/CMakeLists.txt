include(${PROJECT_SOURCE_DIR}/cmake/Macros.cmake)
set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG master
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_subdirectory(Audio)
add_subdirectory(Graficos)
add_subdirectory(Sistema)