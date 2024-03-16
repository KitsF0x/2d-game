#pragma once

#include "AManager.hpp"

namespace kf
{
    class GuiManager : public AManager
    {
    public:
        void updateAll(float deltaTime) override;
        void drawAll(sf::RenderWindow &window) override;
    };
}