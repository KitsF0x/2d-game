add_executable(${PROJECT_NAME}-tests "managers/TEST_GameObjectsManager.cpp" "mocks/MockGameObject.cpp")
target_include_directories(${PROJECT_NAME}-tests PUBLIC managers mocks)
target_link_libraries(${PROJECT_NAME}-tests PRIVATE 
    # Test
    Catch2::Catch2 
    Catch2::Catch2WithMain 

    # Components
    managers 
    game-objects
    
)