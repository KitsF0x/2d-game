#include "GameObjectsManager.hpp"

void kf::GameObjectsManager::add(std::shared_ptr<IGameObject> gameObject)
{
    if (std::find(gameObjects.begin(), gameObjects.end(), gameObject) != gameObjects.end())
    {
        kf::Log::warn("Trying to add already existing game object: " + gameObject->getName());
        throw kf::GameObjectsManagerException(gameObject->getName(), "Game object already exists");
    }
    kf::Log::info("Adding new game object: " + gameObject->getName());
    gameObjects.push_back(gameObject);
    kf::Log::info("Current game objects: " + std::to_string(gameObjects.size()));
}

void kf::GameObjectsManager::remove(std::shared_ptr<IGameObject> gameObject)
{
    kf::Log::info("Removing game object: " + gameObject->getName());
    kf::Log::info("Current game objects: " + std::to_string(gameObjects.size()));
    if (std::find(gameObjects.begin(), gameObjects.end(), gameObject) != gameObjects.end())
    {
        gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), gameObject), gameObjects.end());
    }
    else
    {
        kf::Log::error("Trying to remove non existing game object: " + gameObject->getName());
        throw kf::GameObjectsManagerException(gameObject->getName(), "Game object not found");
    }
}

void kf::GameObjectsManager::updateAll(double deltaTime)
{
    for (auto &gameObject : gameObjects)
    {
        gameObject->update(deltaTime);
    }
}

void kf::GameObjectsManager::drawAll(sf::RenderWindow &window)
{
    for (auto &gameObject : gameObjects)
    {
        gameObject->draw(window);
    }
}

std::size_t kf::GameObjectsManager::size() const
{
    return gameObjects.size();
}

std::vector<std::shared_ptr<kf::IGameObject>> kf::GameObjectsManager::getGameObjectsByName(const std::string &name)
{
    std::vector<std::shared_ptr<kf::IGameObject>> result;
    for (auto &gameObject : gameObjects)
    {
        if (gameObject->getName() == name)
        {
            result.push_back(gameObject);
        }
    }
    return result;
}
