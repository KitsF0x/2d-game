#include "InventoryState.hpp"

kf::InventoryState::InventoryState(kf::StatesManager &statesManager)
    : statesManager(statesManager)
{
}

void kf::InventoryState::handleEvents(sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Escape)
        {
            statesManager.popTopState();
        }
    }
}

void kf::InventoryState::draw(sf::RenderWindow &window)
{
    window.clear(sf::Color::Blue);
}

void kf::InventoryState::update(float deltaTime)
{
}
