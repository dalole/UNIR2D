set(INCROOT ${PROJECT_SOURCE_DIR}/include/UNIR2D/Sistema)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/UNIR2D/Sistema)

set(SRC
    ${INCROOT}/ActorBase.hpp
    ${SRCROOT}/ActorBase.cpp
    ${INCROOT}/JuegoBase.hpp
    ${SRCROOT}/JuegoBase.cpp
    ${INCROOT}/Motor.hpp
    ${SRCROOT}/Motor.cpp
    ${INCROOT}/Rendidor.hpp
    ${SRCROOT}/Rendidor.cpp
)
source_group("" FILES ${SRC})

unir2d_add_library(Sistema SOURCES ${SRC})
target_link_libraries(unir2d-sistema PUBLIC SFML::Graphics)