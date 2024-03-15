#include "RandomTIleGenerator.hpp"

kf::RandomTileGenerator::RandomTileGenerator(std::uint32_t xCount, std::uint32_t yCount)
    : xCount(xCount), yCount(yCount)
{
}

void kf::RandomTileGenerator::generate(kf::TilesManager &manager, const sf::Vector2f &position)
{
    for (std::uint32_t x = 0; x < xCount; x++)
    {
        for (std::uint32_t y = 0; y < yCount; y++)
        {
            int random = rand() % 2;

            float tilePosX = (position.x + x) * TileConsts::TILE_SIZE;
            float tilePosY = (position.y + y) * TileConsts::TILE_SIZE;
            sf::Vector2f tilePos(tilePosX, tilePosY);
            if (random == 0)
            {
                manager.add(std::make_shared<GrassTile>(), tilePos);
            }
            else if (random == 1)
            {
                manager.add(std::make_shared<SandTile>(), tilePos);
            }
        }
    }
}

std::uint32_t kf::RandomTileGenerator::getXCount() const
{
    return xCount;
}

std::uint32_t kf::RandomTileGenerator::getYCount() const
{
    return yCount;
}
