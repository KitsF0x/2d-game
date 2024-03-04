#pragma once

#include "IGameObject.hpp"

namespace kf
{
    class PlayerGameObject : public IGameObject
    {
    private:
        sf::RectangleShape playerShape;

    public:
        PlayerGameObject();
        std::string getName() const override;
        void update(double deltaTime) override;
        void draw(sf::RenderWindow &window) override;

        void setPosition(const sf::Vector2f &position) override;
        sf::Vector2f getPosition() const override;
        sf::FloatRect getHitbox() const override;
    };
}