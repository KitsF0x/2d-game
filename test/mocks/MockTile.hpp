#pragma once

#include "ITile.hpp"

#include "TexturesManager.hpp"

class MockTile : public ITile
{

public:
    std::uintmax_t setTextureFromManagerCalls{0};
    std::uintmax_t setTextureCalls{0};
    mutable std::uintmax_t drawCalls{0};

    void setTextureFromManager(kf::TexturesManager &manager) override;
    void setTexture(const sf::Texture &texture, bool resetRect = false);

protected:
    friend class RenderTarget;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};