#pragma once

#include "ITile.hpp"
#include <vector>
#include <memory>

#include "TexturesManager.hpp"

namespace kf
{
    class TilesManager
    {
    private:
        std::vector<std::shared_ptr<ITile>> tiles;
        kf::TexturesManager &manager;

    public:
        TilesManager(kf::TexturesManager &manager);
        void add(std::shared_ptr<ITile> tile, const sf::Vector2f &position);
        void drawAll(sf::RenderWindow &window);
        std::shared_ptr<ITile> getTileById(std::size_t index);
        std::size_t size() const;
    };
}