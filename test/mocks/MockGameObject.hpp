#pragma once

#include <cstdint>

#include "IGameObject.hpp"

class MockGameObject : public kf::IGameObject
{

public:
    mutable std::uintmax_t getNameCalls{0};
    mutable std::uintmax_t updateCalls{0};
    mutable std::uintmax_t drawCalls{0};
    mutable std::uintmax_t setPositionCalls{0};
    mutable std::uintmax_t getPositionCalls{0};
    mutable std::uintmax_t GetHitboxCalls{0};

    std::string getName() const override;
    void update(double deltaTime) override;
    void draw(sf::RenderWindow &window) override;

    void setPosition(const sf::Vector2f &position) override;
    sf::Vector2f getPosition() const override;
    sf::FloatRect getHitbox() const override;
};