#include <UNIR2D/Graficos.hpp>
using namespace unir2d;

void Efecto::carga(std::filesystem::path archivo, sf::Shader::Type tipo) {
    bool bien = m_shader.loadFromFile(archivo, tipo);
    if(!bien) throw std::runtime_error {"archivo de carga de Efecto no encontrado: " + archivo.string ()};
}

void Efecto::asigna(Textura * textura) {
    m_shader.setUniform("texture", textura);
}
 
void Efecto::actualiza(double time) {
}

void Efecto::dibuja(const Transforma & contenedor, Rendidor * rendidor) {
    sf::Sprite sprite = sf::Sprite{m_texture};
    sf::RenderStates states {};

    Dibujable::situa(sprite, contenedor, this->m_transforma);
    states.shader = &m_shader;

    rendidor->window->draw(sprite, states);
}