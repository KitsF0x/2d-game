#pragma once

#include "ITilesGenerator.hpp"

#include "GrassTile.hpp"
#include "SandTile.hpp"

namespace kf
{
    class RandomTileGenerator : public ITilesGenerator
    {
    private:
        std::uint32_t xCount;
        std::uint32_t yCount;

    public:
        RandomTileGenerator(std::uint32_t xCount, std::uint32_t yCount);
        void generate(kf::TilesManager &manager, const sf::Vector2f &position) override;
        std::uint32_t getXCount() const;
        std::uint32_t getYCount() const;
    };
}