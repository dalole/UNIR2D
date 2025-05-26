set(INCROOT ${PROJECT_SOURCE_DIR}/include/UNIR2D/Graficos)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/UNIR2D/Graficos)

set(SRC
    ${INCROOT}/Baldosas.hpp
    ${SRCROOT}/Baldosas.cpp
    ${INCROOT}/Circulo.hpp
    ${SRCROOT}/Circulo.cpp
    ${INCROOT}/Color.hpp
    ${SRCROOT}/Color.cpp
    ${INCROOT}/Dibujable.hpp
    ${SRCROOT}/Dibujable.cpp
    ${INCROOT}/Fuentes.hpp
    ${SRCROOT}/Fuentes.cpp
    ${INCROOT}/Imagen.hpp
    ${SRCROOT}/Imagen.cpp
    ${INCROOT}/Malla.hpp
    ${SRCROOT}/Malla.cpp
    ${INCROOT}/Rectangulo.hpp
    ${SRCROOT}/Rectangulo.cpp
    ${INCROOT}/Texto.hpp
    ${SRCROOT}/Texto.cpp
    ${INCROOT}/Textura.hpp
    ${SRCROOT}/Textura.cpp
    ${INCROOT}/Trazos.hpp
    ${SRCROOT}/Trazos.cpp
    ${INCROOT}/Efecto.hpp
    ${SRCROOT}/Efecto.cpp
)
source_group("" FILES ${SRC}) 

unir2d_add_library(Graficos SOURCES ${SRC})
target_link_libraries(unir2d-graficos PUBLIC SFML::Graphics)