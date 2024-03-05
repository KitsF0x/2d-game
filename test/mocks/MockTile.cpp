#include "MockTile.hpp"

void MockTile::setTextureFromManager(kf::TexturesManager &manager)
{
    setTextureFromManagerCalls++;
}

void MockTile::setTexture(const sf::Texture &texture, bool resetRect)
{
    setTextureCalls++;
}

void MockTile::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    drawCalls++;
}
