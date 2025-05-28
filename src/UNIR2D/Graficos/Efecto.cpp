#include <UNIR2D/Graficos.hpp>
#include <iostream>
using namespace unir2d;

void Efecto::carga(std::filesystem::path archivo, sf::Shader::Type tipo) {
    bool bien = m_shader.loadFromFile(archivo, tipo);
    if(!bien) throw std::runtime_error {"archivo de carga de Efecto no encontrado: " + archivo.string ()};
}

void Efecto::asigna(Textura * textura) {
    m_texture = textura->entidad();
}

void Efecto::define(string nombre, float valor) {
    m_shader.setUniform(nombre, valor);
}

void Efecto::define(string nombre, Vector valor) {
    m_shader.setUniform(nombre, sf::Vector2f{valor.x(), valor.y()});
}
 
void Efecto::actualiza(double time) {
}

void Efecto::dibuja(const Transforma & contenedor, Rendidor * rendidor) {
    sf::Sprite sprite = sf::Sprite{m_texture};
    Dibujable::situa(sprite, contenedor, this->m_transforma);
    rendidor->window->draw(sprite, &m_shader);
}