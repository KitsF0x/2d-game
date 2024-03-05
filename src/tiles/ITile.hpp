#pragma once
#include <string>

#include <SFML/Graphics.hpp>

#include "TexturesManager.hpp"

class ITile : public sf::Sprite
{
public:
    virtual void setTextureFromManager(kf::TexturesManager &manager) = 0;
    virtual ~ITile() = default;
};