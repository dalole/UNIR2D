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
// Archivo: Efecto.h
// Autor:   Daniel Lopez Leiva
// Versión: 1.2 (10-Oct-2022)
// Estado:  Terminado. Revisado. No documentado.

#pragma once

#include <SFML/Graphics/Shader.hpp>

#include <UNIR2D/Graficos/Textura.hpp>
#include <UNIR2D/Graficos/Dibujable.hpp>

namespace unir2d {
    class Efecto : public Dibujable {
        public:
            explicit Efecto();
            ~Efecto ();

            void carga(std::filesystem::path ruta, sf::Shader::Type tipo);
            void asigna(Textura * valor);

            void define(string nombre, float valor);
            void define(string nombre, Vector valor);

            void actualiza(double time);
        protected:
            sf::Shader m_shader {};
            sf::Texture m_texture {};
        private:
            inline static int cuenta_instancias {};

            // los efectos no se pueden copiar ni mover       
            Efecto (const Efecto & )              = delete;
            Efecto (Efecto && )                   = delete;
            Efecto & operator = (const Efecto & ) = delete;
            Efecto & operator = (Efecto && )      = delete;

            void dibuja(const Transforma & contenedor, Rendidor * rendidor);
    };

    inline Efecto::Efecto () {
        cuenta_instancias ++;
    }

    inline Efecto::~Efecto () {
        cuenta_instancias --;
    }
}