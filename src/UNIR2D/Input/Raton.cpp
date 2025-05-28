// UNIR-2D :: Motor de juego mínimo para la programación de microjuegos en 2 dimensiones.
// 
// Copyright (C) 2022 UNIR-Universidad Internacional de La Rioja. 
// Todos los derechos reservados. 
// El sofware se entrega solo para uso educativo, sin ninguna garantía de adecuación para ningún 
// proposito particular.
// 
// Bibliotecas de código usadas: 
//   1) SFML - Simple and Fast Multimedia Library. Licencia: https://www.sfml-dev.org/license.php  
// 
// Archivo: Raton.cpp
// Autor:   Miguel Angel Zurita Cortés
// Versión: 1.2 (10-Oct-2022)
// Estado:  Terminado. Revisado. No documentado.

#include <UNIR2D/Input.hpp>
using namespace unir2d;


constexpr std::chrono::nanoseconds ms__50 { 50 * 1000 * 1000};  // 50 millisegundos
constexpr std::chrono::nanoseconds ms_200 {200 * 1000 * 1000}; // 200 millisegundos

int pulsacionBoton = 0;
bool botonPulsado {false};

bool Raton::pulsando(sf::Mouse::Button boton)
{
    if(pulsacionBoton == 1 && botonPulsado) return true;
    return false;
}

bool Raton::dobleClic () {
    bool botonPulsando = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
    if(pulsacionBoton > 2) pulsacionBoton = 0;

    if(botonPulsando) {
        if(!botonPulsado) {
            pulsacionBoton++;
            botonPulsado = true;
        }
    }
    else botonPulsado = false;

    if(pulsacionBoton == 2 && botonPulsado) return true;
    return false;
}

Vector Raton::posicion () {
    return Vector {(float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y};
}