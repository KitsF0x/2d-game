#pragma once

#include <vector>
#include <memory>

#include "IGameObject.hpp"
#include "GameObjectsManagerException.hpp"

namespace kf
{
    class GameObjectsManager
    {
    private:
        std::vector<std::shared_ptr<IGameObject>> gameObjects;

    public:
        void add(std::shared_ptr<IGameObject> gameObject, kf::TexturesManager &manager);
        void remove(std::shared_ptr<IGameObject> gameObject);
        void updateAll(double deltaTime);
        void drawAll(sf::RenderWindow &window);
        std::size_t size() const;
        std::vector<std::shared_ptr<kf::IGameObject>> getGameObjectsByName(const std::string &name);
    };
}