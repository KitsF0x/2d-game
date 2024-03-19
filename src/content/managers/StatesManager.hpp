#pragma once

#include "AManager.hpp"
#include "IState.hpp"

namespace kf
{
    class StatesManager : public AManager
    {
    public:
        void updateAll(float deltaTime) override;
        void drawAll(sf::RenderWindow &window) override;
        void handleEvents(sf::Event &event);
        void popTopState();
    };
}