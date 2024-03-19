add_executable(${PROJECT_NAME}-tests
    # Test 
    "content/managers/TEST_GameObjectsManager.cpp" 
    "content/managers/TEST_TexturesManager.cpp"
    "content/managers/TEST_TilesManager.cpp"
    "content/managers/TEST_AManager.cpp"
    "content/managers/TEST_StatesManager.cpp"
    "system/game-system/TEST_Camera.cpp"
    "system/game-system/TEST_DeltaTime.cpp"
    "game-objects/TEST_GameObjectMover.cpp"
    "map/TEST_RandomTileGenerator.cpp"

    # Mocks
    "mocks/MockGameObject.cpp"
    "mocks/MockTile.cpp"
    "mocks/MockAManager.cpp"
    "mocks/MockIManageable.cpp"
    "mocks/MockIState.cpp"
)
target_include_directories(${PROJECT_NAME}-tests PUBLIC managers mocks)
target_link_libraries(${PROJECT_NAME}-tests PRIVATE 
    # Test
    Catch2::Catch2 
    Catch2::Catch2WithMain 

    # Components
    managers 
    game-objects
    game-system
    tiles
    map
    entities-interfaces
)