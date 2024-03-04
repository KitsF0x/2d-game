#include "PlayerGameObject.hpp"

kf::PlayerGameObject::PlayerGameObject()
{
    this->playerShape.setSize(sf::Vector2f{64, 128});
    this->playerShape.setFillColor(sf::Color::Green);
    this->playerShape.setPosition(0, 0);
}

std::string kf::PlayerGameObject::getName() const
{
    return "Player";
}

void kf::PlayerGameObject::update(double deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        this->playerShape.move(0, -100 * deltaTime);
    }
}

void kf::PlayerGameObject::draw(sf::RenderWindow &window)
{
    window.draw(this->playerShape);
}

void kf::PlayerGameObject::setPosition(const sf::Vector2f &position)
{
    this->playerShape.setPosition(position);
}

sf::Vector2f kf::PlayerGameObject::getPosition() const
{
    return this->playerShape.getPosition();
}

sf::FloatRect kf::PlayerGameObject::getHitbox() const
{
    return this->playerShape.getGlobalBounds();
}
