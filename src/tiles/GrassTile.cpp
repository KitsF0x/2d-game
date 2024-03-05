#include "GrassTile.hpp"

void GrassTile::setTextureFromManager(kf::TexturesManager &manager)
{
    setTexture(manager.getTexture("GRASS"));
    
}
