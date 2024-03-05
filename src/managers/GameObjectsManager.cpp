#include "GameObjectsManager.hpp"

void kf::GameObjectsManager::add(std::shared_ptr<IGameObject> gameObject,  kf::TexturesManager &manager)
{
    if (std::find(gameObjects.begin(), gameObjects.end(), gameObject) != gameObjects.end())
    {
        throw kf::GameObjectsManagerException(gameObject->getName(), "Game object already exists");
    }
    gameObject->setTextureFromManager(manager);
    gameObjects.push_back(gameObject);
}

void kf::GameObjectsManager::remove(std::shared_ptr<IGameObject> gameObject)
{
    if (std::find(gameObjects.begin(), gameObjects.end(), gameObject) != gameObjects.end())
    {
        gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), gameObject), gameObjects.end());
    }
    else
    {
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
