set(INCROOT ${PROJECT_SOURCE_DIR}/include/UNIR2D/Input)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/UNIR2D/Input)

set(SRC
    ${INCROOT}/Raton.hpp
    ${SRCROOT}/Raton.cpp
)
source_group("" FILES ${SRC}) 

unir2d_add_library(Input SOURCES ${SRC})
target_link_libraries(unir2d-input PUBLIC SFML::Window)