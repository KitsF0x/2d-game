#include <catch2/catch_test_macros.hpp>

#include "Camera.hpp"

TEST_CASE("WhenCalled_Constructor_ShouldSetViewSize", "[Camera]")
{
    // Arrange
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML Camera Test");
    kf::Camera camera(window);

    // Act
    sf::Vector2f viewSize = window.getView().getSize();

    // Assert
    REQUIRE(viewSize.x == window.getSize().x);
    REQUIRE(viewSize.y == window.getSize().y);
}

TEST_CASE("WhenCalled_Constructor_ShouldSetWindowCenterToZero", "[Camera]")
{
    // Arrange
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Camera Test");
    kf::Camera camera(window);

    // Act
    sf::Vector2f viewCenter = window.getView().getCenter();

    // Assert
    REQUIRE(viewCenter.x == 0.0f);
    REQUIRE(viewCenter.y == 0.0f);
}

TEST_CASE("WhenCalled_Update_ShouldSetCenterToGivenPosition", "[Camera]")
{
    // Arrange
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Camera Test");
    kf::Camera camera(window);

    // Act
    sf::Vector2f newPosition(100.0f, 150.0f);
    camera.update(newPosition);

    // Assert
    sf::Vector2f viewCenter = window.getView().getCenter();
    REQUIRE(viewCenter.x == newPosition.x);
    REQUIRE(viewCenter.y == newPosition.y);
}

TEST_CASE("WhenCalled_Update_ShouldCallSetViewOnRenderWindow", "[Camera]")
{
    // Arrange
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Camera Test");
    kf::Camera camera(window);

    // Act
    sf::Vector2f newPosition(100.0f, 150.0f);
    camera.update(newPosition);

    // Assert
    sf::View view = window.getView();
    sf::Vector2f viewCenter = view.getCenter();
    REQUIRE(viewCenter.x == newPosition.x);
    REQUIRE(viewCenter.y == newPosition.y);
}
