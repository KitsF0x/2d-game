#pragma once
#include <string>

#include <SFML/Graphics.hpp>

#include "TexturesManager.hpp"

class ITile : public sf::Sprite
{
public:
    static const float TILE_SIZE;
    virtual void setTextureFromManager(kf::TexturesManager &manager) = 0;
    virtual ~ITile() = default;
};