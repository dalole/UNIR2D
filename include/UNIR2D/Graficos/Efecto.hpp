#pragma once

#include <SFML/Graphics/Shader.hpp>
#include <SFML/Graphics/Drawable.hpp>

class Efecto : public sf::Drawable {
    public:
        virtual void load() = 0;
        virtual void update(float time) = 0;
    private:
        sf::Shader m_shader;
};