add_executable(${PROJECT_NAME}-tests
    # Test 
    "managers/TEST_GameObjectsManager.cpp" 
    "managers/TEST_TexturesManager.cpp"
    "managers/TEST_TilesManager.cpp"
    "core/TEST_Camera.cpp"
    "core/TEST_DeltaTime.cpp"
    "game-objects/TEST_GameObjectMover.cpp"
    "map/TEST_RandomTileGenerator.cpp"

    # Mocks
    "mocks/MockGameObject.cpp"
    "mocks/MockTile.cpp"
)
target_include_directories(${PROJECT_NAME}-tests PUBLIC managers mocks)
target_link_libraries(${PROJECT_NAME}-tests PRIVATE 
    # Test
    Catch2::Catch2 
    Catch2::Catch2WithMain 

    # Components
    managers 
    game-objects
    core
    tiles
    map
)