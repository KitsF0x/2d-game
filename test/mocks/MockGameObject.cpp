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
}
sf::Vector2f MockGameObject::getPosition() const
{
    getPositionCalls++;
    return sf::Vector2f(0, 0);
}
sf::FloatRect MockGameObject::getHitbox() const
{
    GetHitboxCalls++;
    return sf::FloatRect(0, 0, 0, 0);
}