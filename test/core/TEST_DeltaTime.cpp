#include <catch2/catch_test_macros.hpp>
#include <SFML/System/Time.hpp>

#include "DeltaTime.hpp"

TEST_CASE("WhenCalled_CalculateDeltaTime_ShouldSetDeltaTime", "[DeltaTime]")
{
    // Arrange
    kf::DeltaTime deltaTime;

    sf::Time firstMeasurement = sf::seconds(1);
    sf::Time secondMeasurement = sf::seconds(10);

    // Act
    deltaTime.calculateDeltaTime(firstMeasurement, secondMeasurement);

    // Assert
    REQUIRE(deltaTime.getDeltaTime() == 9);
}