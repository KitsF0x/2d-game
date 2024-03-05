#pragma once

#include "ITile.hpp"

#include "TexturesManager.hpp"

class GrassTile : public ITile
{
public:
    void setTextureFromManager(kf::TexturesManager &manager) override;
};