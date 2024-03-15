#include "GameObjectMover.hpp"

void kf::GameObjectMover::move(IGameObject *gameObject, kf::Direction direction, double delta) const
{
    double speed = gameObject->getSpeed() * delta;
    sf::Vector2f toMove{0.0f, 0.0f};
    switch (direction)
    {
    case kf::Direction::NORTH:
        toMove.y -= static_cast<float>(speed);
        break;
    case kf::Direction::SOUTH:
        toMove.y += static_cast<float>(speed);
        break;
    case kf::Direction::EAST:
        toMove.x += static_cast<float>(speed);
        break;
    case kf::Direction::WEST:
        toMove.x -= static_cast<float>(speed);
        break;
    }
    gameObject->setPosition(gameObject->getPosition() + toMove);
}

void kf::GameObjectMover::move(std::shared_ptr<IGameObject> gameObject, kf::Direction direction, double delta) const
{
    // FIXME: Fix this if I find a better way to do it
    move(gameObject.get(), direction, delta);
}