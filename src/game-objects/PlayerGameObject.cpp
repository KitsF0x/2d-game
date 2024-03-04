#include "PlayerGameObject.hpp"

void kf::PlayerGameObject::handleMovement(double delta)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        mover.move(this, kf::Direction::NORTH, delta);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        mover.move(this, kf::Direction::SOUTH, delta);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        mover.move(this, kf::Direction::WEST, delta);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        mover.move(this, kf::Direction::EAST, delta);
    }
}

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
    handleMovement(deltaTime);
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

double kf::PlayerGameObject::getSpeed()
{
    return speed;
}
