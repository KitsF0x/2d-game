#pragma once

#include "IGuiComponent.hpp"

namespace kf
{
    class Cursor : public IGuiComponent
    {
    private:
        sf::CircleShape shape;
        sf::RenderWindow &window;

    public:
        Cursor(sf::RenderWindow &window);
        void draw(sf::RenderWindow &window) override;
        void update(float deltaTime) override;
    };
}