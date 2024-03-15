#include "TilesManager.hpp"

kf::TilesManager::TilesManager(kf::TexturesManager &manager)
    : manager(manager)
{
}

void kf::TilesManager::add(std::shared_ptr<ITile> tile, const sf::Vector2f &position)
{
    tile->setTextureFromManager(manager);
    tile->setPosition(position);
    tiles.push_back(tile);
}

void kf::TilesManager::drawAll(sf::RenderWindow &window)
{
    for (auto &tile : tiles)
    {
        window.draw(*tile.get());
    }
}

std::shared_ptr<ITile> kf::TilesManager::getTileById(std::size_t index)
{
    return tiles.at(index);
}

std::size_t kf::TilesManager::size() const
{
    return tiles.size();
}
