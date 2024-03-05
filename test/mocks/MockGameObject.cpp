#include "MockGameObject.hpp"

std::string MockGameObject::getName() const
{
    getNameCalls++;
    return "MockGameObject";
}
void MockGameObject::update(double deltaTime)
{
    updateCalls++;
}
void MockGameObject::draw(sf::RenderWindow &window)
{
    drawCalls++;
}

void MockGameObject::setPosition(const sf::Vector2f &position)
{
    setPositionCalls++;
    getPositionReturn = position;
}
sf::Vector2f MockGameObject::getPosition() const
{
    getPositionCalls++;
    return getPositionReturn;
}
sf::FloatRect MockGameObject::getHitbox() const
{
    getHitboxCalls++;
    return sf::FloatRect(0, 0, 0, 0);
}

double MockGameObject::getSpeed()
{
    getSpeedCalls++;
    return getSpeedReturn;
}

void MockGameObject::setTextureFromManager(kf::TexturesManager &manager)
{
    setTextureFromManagerCalls++;
}
