#include "GuiManager.hpp"

void kf::GuiManager::updateAll(float deltaTime)
{
    for (auto &entity : entities)
    {
        entity->update(deltaTime);
    }
}

void kf::GuiManager::drawAll(sf::RenderWindow &window)
{
    for (auto &entity : entities)
    {
        entity->draw(window);
    }
}
