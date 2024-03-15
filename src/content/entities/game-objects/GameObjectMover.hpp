#pragma once
#include <memory>

#include "Direction.hpp"
#include "IGameObject.hpp"

namespace kf
{
    class GameObjectMover
    {
    public:
        void move(IGameObject *gameObject, kf::Direction direction, double delta) const;
        void move(std::shared_ptr<IGameObject> gameObject, kf::Direction direction, double delta) const;
    };
}