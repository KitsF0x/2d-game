#include <catch2/catch_test_macros.hpp>

#include "TilesManager.hpp"
#include "MockTile.hpp"

TEST_CASE("WhenCalled_Add_ShouldIncrementSizeOfTheManager", "[TilesManager]")
{
    // Arrange
    kf::TexturesManager texturesManager{};
    kf::TilesManager manager{texturesManager};

    // Act
    manager.add(std::make_shared<MockTile>(), sf::Vector2f{0.0f, 0.0f});

    // Assert
    REQUIRE(manager.size() == 1);
}

TEST_CASE("WhenCalled_Add_ShouldSetPositionOfTheTile", "[TilesManager]")
{
    // Arrange
    kf::TexturesManager texturesManager{};
    kf::TilesManager manager{texturesManager};
    std::shared_ptr<MockTile> tile = std::make_shared<MockTile>();

    // Act
    manager.add(tile, sf::Vector2f{10.0f, 20.0f});

    // Assert
    REQUIRE(tile->getPosition() == sf::Vector2f{10.0f, 20.0f});
}

TEST_CASE("WhenCalled_Add_ShouldSetTextureOfTheTile", "[TilesManager]")
{
    // Arrange
    kf::TexturesManager texturesManager{};
    kf::TilesManager manager{texturesManager};
    std::shared_ptr<MockTile> tile = std::make_shared<MockTile>();

    // Act
    manager.add(tile, sf::Vector2f{10.0f, 20.0f});

    // Assert
    REQUIRE(tile->setTextureFromManagerCalls == 1);
}
TEST_CASE("WhenCalled_DrawAll_ShouldCallDrawOnAllTiles", "[TilesManager]")
{
    // Arrange
    sf::RenderWindow window{};
    kf::TexturesManager texturesManager{};
    kf::TilesManager manager{texturesManager};
    std::shared_ptr<MockTile> tile = std::make_shared<MockTile>();
    std::shared_ptr<MockTile> tile2 = std::make_shared<MockTile>();
    manager.add(tile, sf::Vector2f{0.0f, 0.0f});
    manager.add(tile2, sf::Vector2f{0.0f, 0.0f});

    // Act
    manager.drawAll(window);

    // Assert
    REQUIRE(tile->drawCalls == 1);
    REQUIRE(tile2->drawCalls == 1);
}