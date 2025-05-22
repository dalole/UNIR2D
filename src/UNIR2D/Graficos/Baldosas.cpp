
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
// Archivo: Imagen.cpp
// Autor:   Miguel Angel Zurita Cortés
// Versión: 1.2 (10-Oct-2022)
// Estado:  Terminado. Revisado. No documentado.

#include <UNIR2D/Graficos.hpp>
using namespace unir2d;

Baldosas::~Baldosas () {
    if (textura != nullptr) {
        textura->cuenta_usos --;
    }
}


void Baldosas::asigna (Textura * textura) {
    this->textura = textura;
    this->preparado = false;
    textura->cuenta_usos ++;
}


void Baldosas::defineEstampas (int filas, int columnas) {
    assert (filas >= 1);
    assert (columnas >= 1);
    //
    filas_estampas = filas;
    colns_estampas = columnas;
    this->preparado = false;
}


void Baldosas::defineSuperficie (int filas, int columnas) {
    assert (filas >= 1);
    assert (columnas >= 1);
    //
    filas_baldosas = filas;
    colns_baldosas = columnas;
    this->preparado = false;
}


void Baldosas::mapea (const std::vector <uint32_t> & tabla_indices) {
    int total_superf = filas_baldosas * colns_baldosas;
    assert (tabla_indices.size () == total_superf);
    //
    int ancho_estmp = textura->rectg_textura.x / this->colns_estampas;
    int alto__estmp = textura->rectg_textura.y / this->filas_estampas; 
    //
    this->vertices.setPrimitiveType(sf::PrimitiveType::Triangles);
    this->vertices.resize(filas_baldosas * colns_baldosas * 6);

    for (int i = 0; i < this->filas_baldosas; ++i) {
        for (int j = 0; j < this->colns_baldosas; ++j) {
            int index_balds = i * colns_baldosas + j;
            int index_estmp = tabla_indices[index_balds];
            int coln__estmp = index_estmp % colns_estampas;
            int fila__estmp = index_estmp / colns_estampas;

            // Posiciones de los 4 vértices del quad
            float izqrd = (float)(j * ancho_estmp);
            float derch = (float)((j + 1) * ancho_estmp);
            float arrba = (float)(i * alto__estmp);
            float abajo = (float)((i + 1) * alto__estmp);

            sf::Vector2f v0(izqrd, arrba);   // superior izquierda
            sf::Vector2f v1(derch, arrba);   // superior derecha
            sf::Vector2f v2(derch, abajo);   // inferior derecha
            sf::Vector2f v3(izqrd, abajo);   // inferior izquierda

            // Coordenadas de textura
            float t_izqrd = (float)(coln__estmp * ancho_estmp);
            float t_derch = (float)((coln__estmp + 1) * ancho_estmp);
            float t_arrba = (float)(fila__estmp * alto__estmp);
            float t_abajo = (float)((fila__estmp + 1) * alto__estmp);

            sf::Vector2f t0(t_izqrd, t_arrba);
            sf::Vector2f t1(t_derch, t_arrba);
            sf::Vector2f t2(t_derch, t_abajo);
            sf::Vector2f t3(t_izqrd, t_abajo);

            int index_vertc = index_balds * 6;

            // Primer triángulo: v0, v1, v2
            this->vertices[index_vertc + 0].position = v0;
            this->vertices[index_vertc + 1].position = v1;
            this->vertices[index_vertc + 2].position = v2;
            this->vertices[index_vertc + 0].texCoords = t0;
            this->vertices[index_vertc + 1].texCoords = t1;
            this->vertices[index_vertc + 2].texCoords = t2;

            // Segundo triángulo: v0, v2, v3
            this->vertices[index_vertc + 3].position = v0;
            this->vertices[index_vertc + 4].position = v2;
            this->vertices[index_vertc + 5].position = v3;
            this->vertices[index_vertc + 3].texCoords = t0;
            this->vertices[index_vertc + 4].texCoords = t2;
            this->vertices[index_vertc + 5].texCoords = t3;
        }
    }
    //
    this->preparado = true;
}


void Baldosas::dibuja (const Transforma & contenedor, Rendidor * rendidor) {
    assert (this->preparado);
	//
    sf::Transformable objeto {};
	Dibujable::situa (objeto, contenedor, this->m_transforma);
	//
    sf::RenderStates states {};
    states.transform = objeto.getTransform ();
    states.texture = & textura->entidad ();
    //
	rendidor->window->draw (this->vertices, states);
}


