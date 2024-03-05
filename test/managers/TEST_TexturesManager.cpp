#include <catch2/catch_test_macros.hpp>

#include "TexturesManager.hpp"

TEST_CASE("WhenCalled_AddTexture_ShouldIncrementSizeOfTheManager")
{
    // Arrange
    kf::TexturesManager texturesManager;
    sf::Texture texture{};

    // Act
    texturesManager.addTexture("test", texture);

    // Assert
    REQUIRE(texturesManager.size() == 1);
}

TEST_CASE("WhenCalled_GetTexture_ShouldReturnTextureWithGivenName")
{
    // Arrange
    kf::TexturesManager texturesManager;
    sf::Texture texture{};
    texturesManager.addTexture("test", texture);

    // Act + Assert
    REQUIRE_NOTHROW(texturesManager.getTexture("test"));
}

TEST_CASE("WhenCalled_GetTexture_ShouldThrowTexturesManagerExceptionWhenTextureWithGivenNameWasNotFound")
{
    // Arrange
    kf::TexturesManager texturesManager;

    // Act + Assert
    REQUIRE_THROWS_AS(texturesManager.getTexture("test"), kf::TexturesManagerException);
}

TEST_CASE("WhenCalled_RemoveTexture_ShouldDecrementSizeOfTexture")
{
    // Arrange
    kf::TexturesManager texturesManager;
    sf::Texture texture{};
    texturesManager.addTexture("test", texture);

    // Act
    texturesManager.removeTexture("test");

    // Assert
    REQUIRE(texturesManager.size() == 0);
}

TEST_CASE("WhenCalled_RemoveTexture_ShouldThrowTexturesManagerExceptionWhenTextureWithGivenNameWasNotFound")
{
    // Arrange
    kf::TexturesManager texturesManager;

    // Act + Assert
    REQUIRE_THROWS_AS(texturesManager.removeTexture("test"), kf::TexturesManagerException);
}