#include <catch2/catch_test_macros.hpp>

#include "GameObjectsManager.hpp"

#include "MockGameObject.hpp"
#include "GameObjectsManagerException.hpp"

TEST_CASE("WhenCalled_Add_ShouldIncrementSizeOfTheManager")
{
    // Arrange
    kf::GameObjectsManager manager;
    kf::TexturesManager texturesManager{};

    // Act
    manager.add(std::make_shared<MockGameObject>(), texturesManager);

    // Assert
    REQUIRE(manager.size() == 1);
}

TEST_CASE("WhenCalled_Add_ShouldAddGameObjectToTheManager")
{
    // Arrange
    kf::GameObjectsManager manager;
    kf::TexturesManager texturesManager{};
    std::shared_ptr<MockGameObject> gameObject = std::make_shared<MockGameObject>();

    // Act
    manager.add(gameObject, texturesManager);

    // Assert
    REQUIRE(manager.getGameObjectsByName("MockGameObject").at(0) == gameObject);
}

TEST_CASE("WhenCalled_UpdateAll_ShouldCallUpdateOnAllGameObjects")
{
    // Arrange
    kf::GameObjectsManager manager;
    kf::TexturesManager texturesManager{};
    std::shared_ptr<MockGameObject> gameObject = std::make_shared<MockGameObject>();
    manager.add(gameObject, texturesManager);

    // Act
    manager.updateAll(1.0f);

    // Assert
    REQUIRE(gameObject->updateCalls == 1);
}

TEST_CASE("WhenCalled_DrawAll_ShouldCallDrawOnAllGameObjects")
{
    // Arrange
    kf::GameObjectsManager manager;
    kf::TexturesManager texturesManager{};
    std::shared_ptr<MockGameObject> gameObject = std::make_shared<MockGameObject>();
    manager.add(gameObject, texturesManager);
    sf::RenderWindow window{};
    // Act
    manager.drawAll(window);

    // Assert
    REQUIRE(gameObject->drawCalls == 1);
}

TEST_CASE("WhenCalled_GetGameObjectsByName_ShouldReturnAllGameObjectsWithGivenName")
{
    // Arrange
    kf::GameObjectsManager manager;
    kf::TexturesManager texturesManager{};
    manager.add(std::make_shared<MockGameObject>(), texturesManager);
    manager.add(std::make_shared<MockGameObject>(), texturesManager);
    manager.add(std::make_shared<MockGameObject>(), texturesManager);

    // Act
    auto result = manager.getGameObjectsByName("MockGameObject");

    // Assert
    REQUIRE(result.at(0)->getName() == "MockGameObject");
    REQUIRE(result.size() == 3);
}

TEST_CASE("WhenCalled_Add_ShouldNotAddGameObjectToTheManagerIfItAlreadyExists")
{
    // Arrange
    kf::GameObjectsManager manager;
    kf::TexturesManager texturesManager{};
    std::shared_ptr<MockGameObject> gameObject = std::make_shared<MockGameObject>();
    manager.add(gameObject, texturesManager);

    // Act
    REQUIRE_THROWS(manager.add(gameObject, texturesManager));
    auto result = manager.getGameObjectsByName("MockGameObject");

    // Assert
    REQUIRE(result.size() == 1);
}

TEST_CASE("WhenCalled_Add_ShouldThrowGameObjectsManagerExceptionIfGameObjectAlreadyExists")
{
    // Arrange
    kf::GameObjectsManager manager;
    kf::TexturesManager texturesManager{};
    std::shared_ptr<MockGameObject> gameObject = std::make_shared<MockGameObject>();
    manager.add(gameObject, texturesManager);

    REQUIRE_THROWS_AS(manager.add(gameObject, texturesManager), kf::GameObjectsManagerException);
}

TEST_CASE("WhenCalled_Remove_ShouldDecrementSizeOfTheManager")
{
    // Arrange
    kf::GameObjectsManager manager;
    kf::TexturesManager texturesManager{};
    std::shared_ptr<MockGameObject> gameObject = std::make_shared<MockGameObject>();
    manager.add(gameObject, texturesManager);
    // Act
    manager.remove(gameObject);

    // Assert
    REQUIRE(manager.size() == 0);
}

TEST_CASE("WhenCalled_Remove_ShouldRemoveGameObjectFromTheManager")
{
    // Arrange
    kf::GameObjectsManager manager;
    kf::TexturesManager texturesManager{};
    std::shared_ptr<MockGameObject> gameObject = std::make_shared<MockGameObject>();
    manager.add(gameObject, texturesManager);

    // Act
    manager.remove(gameObject);

    // Assert
    REQUIRE(manager.getGameObjectsByName("MockGameObject").size() == 0);
}

TEST_CASE("WhenCalled_Remove_ShouldNotDecrementSizeOfTheManagerIfGameObjectDoesNotExist")
{
    // Arrange
    kf::GameObjectsManager manager;
    kf::TexturesManager texturesManager{};
    manager.add(std::make_shared<MockGameObject>(), texturesManager);

    std::shared_ptr<MockGameObject> gameObject = std::make_shared<MockGameObject>();

    // Act
    REQUIRE_THROWS(manager.remove(gameObject));

    // Assert
    REQUIRE(manager.size() == 1);
}

TEST_CASE("WhenCalled_Remove_ShouldThrowGameObjectsManagerExceptionIfGameObjectDoesNotExist")
{
    // Arrange
    kf::GameObjectsManager manager;

    // Act + Assert
    REQUIRE_THROWS_AS(manager.remove(std::make_shared<MockGameObject>()), kf::GameObjectsManagerException);
}