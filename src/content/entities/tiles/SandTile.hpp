#pragma once

#include "ITile.hpp"

#include "TexturesManager.hpp"

class SandTile : public ITile
{
public:
    void setTextureFromManager(kf::TexturesManager &manager) override;
};