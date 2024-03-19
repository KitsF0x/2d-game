#include "StatesManager.hpp"

void kf::StatesManager::updateAll(float deltaTime)
{
    entities.at(entities.size() - 1)->update(deltaTime);
}

void kf::StatesManager::drawAll(sf::RenderWindow &window)
{
    entities.at(entities.size() - 1)->draw(window);
}

void kf::StatesManager::handleEvents(sf::Event &event)
{
    std::shared_ptr<kf::IState> state = std::dynamic_pointer_cast<IState>(entities.at(entities.size() - 1));
    state->handleEvents(event);
}

void kf::StatesManager::popTopState()
{
    entities.pop_back();
}
