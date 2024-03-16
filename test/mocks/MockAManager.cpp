#include "MockAManager.hpp"

void MockAManager::updateAll(float deltaTime)
{
    updateAllCalls++;
}

void MockAManager::drawAll(sf::RenderWindow &window)
{
    drawAllCalls++;
}
