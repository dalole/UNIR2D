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
// Archivo: Raton.h
// Autor:   Miguel Angel Zurita Cortés
// Versión: 1.2 (10-Oct-2022)
// Estado:  Terminado. Revisado. Documentado.


#pragma once
#include <chrono>

#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/WindowHandle.hpp>

#include <UNIR2D/Matematicas/Vector.hpp>
#include <UNIR2D/Sistema/Rendidor.hpp>

namespace unir2d {

    class Rendidor;

    class Raton {
        public:
            /// @brief Comprueba si el botón del ratón indicado está pulsado en el momento de la llamada.
            /// @details La pulsación doble (doble-clic) y la pulsación simple no son excluyentes.
            /// @param boton Botón del ratón que se comprueba.
            /// @return Si el botón está pulsado.
            static bool pulsando (sf::Mouse::Button boton);

            /// @brief Comprueba si se ha realizado un doble-clic reciente con el ratón.
            /// @details El doble-clic y la pulsación simple no son excluyentes.
            /// @return Si se ha reaizado un doble-clic reciente.
            static bool dobleClic ();

            /// @brief Obtiene la posición del ratón en el momento de la llamada.
            /// @details La posición del ratón es relativa a la posición del la pantalla del juego. El 
            /// origen de la pantalla está en la esquina superior izquierda del area de cliente de la 
            /// ventana.
            /// @return Posición del ratón.
            static Vector posicion ();
        private:
            using Momento = std::chrono::time_point<std::chrono::steady_clock>;
    
            inline static sf::WindowHandle winHandle;
            inline static Momento momento_clic;

            static void configura (Rendidor * rendidor);
            friend class Motor;
    };
}