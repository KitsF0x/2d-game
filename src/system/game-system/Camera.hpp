#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

namespace kf
{
    class Camera
    {
    private:
        sf::View view;
        sf::RenderWindow &window;

    public:
        static const float ZOOM_FACTOR;

        Camera(sf::RenderWindow &window);
        void update(const sf::Vector2f &center);
        void zoomIn();
        void zoomOut();
    };
}