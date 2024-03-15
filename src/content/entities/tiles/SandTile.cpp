#include "SandTile.hpp"

void SandTile::setTextureFromManager(kf::TexturesManager &manager)
{
    setTexture(manager.getTexture("SAND"));
}