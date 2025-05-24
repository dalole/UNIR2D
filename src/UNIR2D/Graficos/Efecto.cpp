#include <UNIR2D/Graficos.hpp>
using namespace unir2d;

explicit Efecto::Efecto(sf::Texture&& texture, sf::Shader&& shader) : m_texture(std::move(texture)), m_shader(std::move(shader))
{
    m_shader.setUniform("texture", sf::Shader::CurrentTexture);
}

bool Efecto::carga(std::filesystem::path ruta, sf::Shader::Type tipo) {
    if(m_shader.loadFromFile(ruta, tipo)) return true;
    return false;
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