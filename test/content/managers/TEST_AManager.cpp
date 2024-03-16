#include <catch2/catch_test_macros.hpp>

#include "AManager.hpp"
#include "MockAManager.hpp"
#include "MockIManageable.hpp"

TEST_CASE("WhenCalled_Add_ShouldAddEntityToTheManager", "[AManager]")
{
    // Arrange
    MockAManager manager;

    // Act
    manager.add(std::make_shared<MockIManageable>());

    // Assert
    REQUIRE(manager.size() == 1);
}

TEST_CASE("WhenCalled_Remove_ShouldAddEntityToTheManager", "[AManager]")
{
    // Arrange
    MockAManager manager;
    auto entity = std::make_shared<MockIManageable>();
    manager.add(entity);

    // Act
    manager.remove(entity);

    // Assert
    REQUIRE(manager.size() == 0);
}