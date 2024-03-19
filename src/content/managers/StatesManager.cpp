#include "StatesManager.hpp"

void kf::StatesManager::updateAll(float deltaTime)
{
    // TODO: Change it to "stack"
    for (auto &entity : entities)
    {
        entity->update(deltaTime);
    }
}

void kf::StatesManager::drawAll(sf::RenderWindow &window)
{
    // TODO: Change it to "stack"
    for (auto &entity : entities)
    {
        entity->draw(window);
    }
}

void kf::StatesManager::handleEvents(sf::Event &event)
{
    // TODO: Change it to "stack"
    for (auto &entity : entities)
    {
        std::shared_ptr<kf::IState> state = std::dynamic_pointer_cast<IState>(entity);
        state->handleEvents(event);
    }
}
