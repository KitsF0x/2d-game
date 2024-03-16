#pragma once

#include "IManageable.hpp"

class MockIManageable : public kf::IManageable
{
public:
    void update(float deltaTime) override;
    void draw(sf::RenderWindow &window) override;
};