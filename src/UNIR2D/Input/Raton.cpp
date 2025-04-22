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

void Raton::configura (Rendidor * rendidor) {
    winHandle = rendidor->window->getSystemHandle ();
    momento_clic = std::chrono::steady_clock::time_point::min ();
}

bool Raton::pulsando(sf::Mouse::Button boton)
{
    return sf::Mouse::isButtonPressed(boton);
}

bool Raton::dobleClic () {
    if(!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) return false;

    Momento ahora = std::chrono::steady_clock::now ();
    std::chrono::nanoseconds lapso = ahora - momento_clic;        
    momento_clic = ahora;

    constexpr std::chrono::nanoseconds ms__50 { 50 * 1000 * 1000};  // 50 millisegundos
    constexpr std::chrono::nanoseconds ms_200 {200 * 1000 * 1000}; // 200 millisegundos

    if (lapso > ms_200 || lapso < ms__50) return false;
    return true;
}

Vector Raton::posicion () {
    return Vector {sf::Mouse::getPosition().x, sf::Mouse::getPosition().y};
}