#pragma once

#include <cstdint>

#include "AManager.hpp"

class MockAManager : public kf::AManager
{
public:
    std::uintmax_t updateAllCalls{0};
    std::uintmax_t drawAllCalls{0};

    void updateAll(float deltaTime) override;
    void drawAll(sf::RenderWindow &window) override;
};