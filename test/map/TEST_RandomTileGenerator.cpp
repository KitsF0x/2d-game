#include <catch2/catch_test_macros.hpp>

#include "RandomTileGenerator.hpp"

TEST_CASE("WhenCalled_Constructor_ShouldXCountAndYCount", "[RandomTileGenerator]")
{
    // Arrange
    kf::RandomTileGenerator rtg(10, 20);

    // Assert
    REQUIRE(rtg.getXCount() == 10);
    REQUIRE(rtg.getYCount() == 20);
}

TEST_CASE("WhenCalled_Generate_ShouldGenerateCorrectAmountOfTiles", "[RandomTileGenerator]")
{
    // Arrange
    kf::RandomTileGenerator rtg(10, 20);
    kf::TexturesManager texturesManager{};
    texturesManager.addTexture("SAND", sf::Texture{});
    texturesManager.addTexture("GRASS", sf::Texture{});
    kf::TilesManager tilesManager{texturesManager};

    // Assert
    rtg.generate(tilesManager, sf::Vector2f{0.0f, 0.0f});
    REQUIRE(tilesManager.size() == 200);
}

TEST_CASE("WhenCalled_Generate_ShouldGenerateTilesOnGivenPosition", "[RandomTileGenerator]")
{
    // Arrange
    kf::RandomTileGenerator rtg(1, 1);
    kf::TexturesManager texturesManager{};
    texturesManager.addTexture("SAND", sf::Texture{});
    texturesManager.addTexture("GRASS", sf::Texture{});
    kf::TilesManager tilesManager{texturesManager};

    // Act
    rtg.generate(tilesManager, sf::Vector2f{0.0f, 0.0f});

    // Assert
    REQUIRE(tilesManager.getTileById(0)->getPosition() == sf::Vector2f{0.0f, 0.0f});
}

TEST_CASE("WhenCalled_Generate_ShouldGenerateOffsetTilesBySize", "[RandomTileGenerator]")
{
    // Arrange
    kf::RandomTileGenerator rtg(2, 2);
    kf::TexturesManager texturesManager{};
    texturesManager.addTexture("SAND", sf::Texture{});
    texturesManager.addTexture("GRASS", sf::Texture{});
    kf::TilesManager tilesManager{texturesManager};

    // Act
    rtg.generate(tilesManager, sf::Vector2f{0.0f, 0.0f});

    // Assert
    REQUIRE(tilesManager.getTileById(0)->getPosition() == sf::Vector2f{0.0f, 0.0f});
    REQUIRE(tilesManager.getTileById(1)->getPosition() == sf::Vector2f{0.0f, static_cast<float>(kf::TileConsts::TILE_SIZE)});
    REQUIRE(tilesManager.getTileById(2)->getPosition() == sf::Vector2f{static_cast<float>(kf::TileConsts::TILE_SIZE), 0.0f});
    REQUIRE(tilesManager.getTileById(3)->getPosition() == sf::Vector2f{static_cast<float>(kf::TileConsts::TILE_SIZE), static_cast<float>(kf::TileConsts::TILE_SIZE)});
}