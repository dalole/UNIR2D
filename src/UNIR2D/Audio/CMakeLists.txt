set(INCROOT ${PROJECT_SOURCE_DIR}/include/UNIR2D/Audio)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/UNIR2D/Audio)

set(SRC
    ${INCROOT}/Sonido.hpp
    ${SRCROOT}/Sonido.cpp
)
source_group("" FILES ${SRC}) 

unir2d_add_library(Audio SOURCES ${SRC})
target_link_libraries(unir2d-audio PUBLIC SFML::Audio)