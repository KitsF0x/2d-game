#include "Cursor.hpp"

kf::Cursor::Cursor(sf::RenderWindow &window)
    : window(window)
{
    shape.setRadius(10.0f);
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(shape.getRadius(), shape.getRadius());
    shape.setPosition(-10, -10);
}

void kf::Cursor::draw(sf::RenderWindow &window)
{
    window.draw(shape);
}

void kf::Cursor::update(float deltaTime)
{
    sf::Vector2f position = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    shape.setPosition(position);
}
