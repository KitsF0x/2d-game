#include "MockIState.hpp"

void MockIState::draw(sf::RenderWindow &window)
{
    drawCalls++;
}

void MockIState::update(float deltaTime)
{
    updateCalls++;
}

void MockIState::handleEvents(sf::Event &event)
{
    handleEventsCalls++;
}
