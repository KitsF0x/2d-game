#pragma once

#include <SFML/Graphics.hpp>

namespace kf
{   
    class IGameObject
    {
    public:
        virtual std::string getName() const = 0;
        virtual void update(double deltaTime) = 0;
        virtual void draw(sf::RenderWindow &window) = 0;

        virtual void setPosition(const sf::Vector2f &position) = 0;
        virtual sf::Vector2f getPosition() const = 0;
        virtual sf::FloatRect getHitbox() const = 0;

        virtual ~IGameObject() = default;
    };
}