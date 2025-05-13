
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
// Archivo: Fuentes.h
// Autor:   Miguel Angel Zurita Cortés
// Versión: 1.2 (10-Oct-2022)
// Estado:  Terminado. Revisado. No documentado.

			 
#pragma once
#include <string>
#include <map>

#include <SFML/Graphics/Font.hpp>

namespace unir2d {


	using string = std::string;
	using wstring = std::wstring;


	/// @cond


	class Fuentes {
	private:
		inline static int fuentes_cargadas {};
		std::map<string, sf::Font *> tabla_fuentes {};

		int cuenta_usos {0};

		Fuentes () = default;

        // las fuentes no se pueden copiar ni mover       
        Fuentes (const Fuentes & )              = delete;
        Fuentes (Fuentes && )                   = delete;
        Fuentes & operator = (const Fuentes & ) = delete;
        Fuentes & operator = (Fuentes && )      = delete;

		void carga (const string & nombre);
		void descarga ();


		friend class Texto;
        friend class JuegoBase;

	};


	/// @endcond


}