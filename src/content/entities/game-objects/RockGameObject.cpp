#include "RockGameObject.hpp"

kf::RockGameObject::RockGameObject()
{
}

std::string kf::RockGameObject::getName() const
{
    return "Rock";
}

void kf::RockGameObject::update(double deltaTime)
{
}

void kf::RockGameObject::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}

void kf::RockGameObject::setPosition(const sf::Vector2f &position)
{
    sprite.setPosition(position);
}

sf::Vector2f kf::RockGameObject::getPosition() const
{
    return sprite.getPosition();
}

sf::FloatRect kf::RockGameObject::getHitbox() const
{
    return sprite.getGlobalBounds();
}

double kf::RockGameObject::getSpeed()
{
    return 0.0;
}

void kf::RockGameObject::setTextureFromManager(kf::TexturesManager &manager)
{
    sprite.setTexture(manager.getTexture("ROCK_ITEM"));
}
