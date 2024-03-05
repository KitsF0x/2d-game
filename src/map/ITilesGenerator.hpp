#pragma once

#include "TilesManager.hpp"

namespace kf
{
    class ITilesGenerator
    {
    public:
        virtual void generate(kf::TilesManager &manager, const sf::Vector2f &position) = 0;
        virtual ~ITilesGenerator() = default;
    };
}