#include <catch2/catch_test_macros.hpp>

#include "MockGameObject.hpp"
#include "Direction.hpp"
#include "GameObjectMover.hpp"

TEST_CASE("WhenCalled_Move_ShouldCallGetSpeedOnTheGameObjectWhenDirectionIsAnyDirection")
{
    // Arrange
    kf::GameObjectMover mover;
    std::shared_ptr<MockGameObject> mock = std::make_shared<MockGameObject>();

    // Act
    mover.move(mock, kf::Direction::NORTH, 1.0f);
    mover.move(mock, kf::Direction::EAST, 1.0f);
    mover.move(mock, kf::Direction::SOUTH, 1.0f);
    mover.move(mock, kf::Direction::WEST, 1.0f);

    // Assert
    REQUIRE(mock->getSpeedCalls == 4);
}

TEST_CASE("WhenCalled_Move_ShouldCallSetPositionOnTheGameObjectWhenDirectionIsAnyDirection")
{
    // Arrange
    kf::GameObjectMover mover;
    std::shared_ptr<MockGameObject> mock = std::make_shared<MockGameObject>();

    // Act
    mover.move(mock, kf::Direction::NORTH, 1.0f);
    mover.move(mock, kf::Direction::EAST, 1.0f);
    mover.move(mock, kf::Direction::SOUTH, 1.0f);
    mover.move(mock, kf::Direction::WEST, 1.0f);

    // Assert
    REQUIRE(mock->setPositionCalls == 4);
}

TEST_CASE("WhenCalled_Move_ShouldMoveGameObjectToNorthBySpeedOfGameObject")
{
    // Arrange
    float speed{10.0f};
    kf::GameObjectMover mover;
    std::shared_ptr<MockGameObject> mock = std::make_shared<MockGameObject>();
    mock->getSpeedReturn = speed;

    // Act
    mover.move(mock, kf::Direction::NORTH, 1.0f);

    // Assert

    REQUIRE(mock->getPosition() == sf::Vector2f{0.0f, -speed});
}

TEST_CASE("WhenCalled_Move_ShouldMoveGameObjectToSouthBySpeedOfGameObject")
{
    // Arrange
    float speed{10.0f};
    kf::GameObjectMover mover;
    std::shared_ptr<MockGameObject> mock = std::make_shared<MockGameObject>();
    mock->getSpeedReturn = speed;

    // Act
    mover.move(mock, kf::Direction::SOUTH, 1.0f);

    // Assert
    REQUIRE(mock->getPosition() == sf::Vector2f{0.0f, speed});
}

TEST_CASE("WhenCalled_Move_ShouldMoveGameObjectToEastBySpeedOfGameObject")
{
    // Arrange
    float speed{10.0f};
    kf::GameObjectMover mover;
    std::shared_ptr<MockGameObject> mock = std::make_shared<MockGameObject>();
    mock->getSpeedReturn = speed;

    // Act
    mover.move(mock, kf::Direction::EAST, 1.0f);

    // Assert
    REQUIRE(mock->getPosition() == sf::Vector2f{speed, 0.0f});
}
TEST_CASE("WhenCalled_Move_ShouldMoveGameObjectToWestBySpeedOfGameObject")
{
    // Arrange
    float speed{10.0f};
    kf::GameObjectMover mover;
    std::shared_ptr<MockGameObject> mock = std::make_shared<MockGameObject>();
    mock->getSpeedReturn = speed;

    // Act
    mover.move(mock, kf::Direction::WEST, 1.0f);

    // Assert
    REQUIRE(mock->getPosition() == sf::Vector2f{-speed, 0.0f});
}