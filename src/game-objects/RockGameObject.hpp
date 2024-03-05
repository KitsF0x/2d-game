#pragma once

#include "IGameObject.hpp"
#include "GameObjectMover.hpp"

namespace kf
{
    class RockGameObject : public IGameObject
    {
    private:
        sf::Sprite sprite;

    public:
        RockGameObject();
        std::string getName() const override;
        void update(double deltaTime) override;
        void draw(sf::RenderWindow &window) override;

        void setPosition(const sf::Vector2f &position) override;
        sf::Vector2f getPosition() const override;
        sf::FloatRect getHitbox() const override;
        double getSpeed() override;

        void setTextureFromManager(kf::TexturesManager &manager) override;
    };
}