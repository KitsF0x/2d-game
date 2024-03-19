#pragma once

#include <cstdint>

#include "IState.hpp"

class MockIState : public kf::IState
{
public:
    std::uintmax_t drawCalls{0};
    std::uintmax_t updateCalls{0};
    std::uintmax_t handleEventsCalls{0};

    void draw(sf::RenderWindow &window) override;
    void update(float deltaTime) override;
    void handleEvents(sf::Event &event) override;
};