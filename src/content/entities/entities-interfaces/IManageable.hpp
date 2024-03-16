#pragma once

#include <SFML/Graphics.hpp>

namespace kf
{
    class IManageable
    {
    public:
        virtual void draw(sf::RenderWindow &window) = 0;
        virtual void update(float deltaTime) = 0;
    };
}