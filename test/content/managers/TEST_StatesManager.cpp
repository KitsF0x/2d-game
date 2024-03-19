#include <catch2/catch_test_macros.hpp>

#include "StatesManager.hpp"
#include "MockIState.hpp"

TEST_CASE("WhenCalled_UpdateAll_ShouldCallUpdateOnAllStates", "StatesManager")
{
    // Arrange
    kf::StatesManager manager;
    auto state1 = std::make_shared<MockIState>();
    auto state2 = std::make_shared<MockIState>();
    manager.add(state1);
    manager.add(state2);

    // Act
    manager.updateAll(0.0f);

    // Assert
    REQUIRE(state1->updateCalls == 1);
    REQUIRE(state2->updateCalls == 1);
}

TEST_CASE("WhenCalled_DrawAll_ShouldCallDrawOnAllStates", "StatesManager")
{
    // Arrange
    kf::StatesManager manager;
    auto state1 = std::make_shared<MockIState>();
    auto state2 = std::make_shared<MockIState>();
    manager.add(state1);
    manager.add(state2);
    sf::RenderWindow window{};

    // Act
    manager.drawAll(window);

    // Assert
    REQUIRE(state1->drawCalls == 1);
    REQUIRE(state2->drawCalls == 1);
}

TEST_CASE("WhenCalled_HandleEvents_ShouldCallDrawOnAllStates", "StatesManager")
{
    // Arrange
    kf::StatesManager manager;
    auto state1 = std::make_shared<MockIState>();
    auto state2 = std::make_shared<MockIState>();
    manager.add(state1);
    manager.add(state2);
    sf::Event event{};

    // Act
    manager.handleEvents(event);

    // Assert
    REQUIRE(state1->handleEventsCalls == 1);
    REQUIRE(state2->handleEventsCalls == 1);
}