add_library(game-objects STATIC PlayerGameObject.cpp GameObjectMover.cpp RockGameObject.cpp)
target_include_directories(game-objects PUBLIC .)
target_link_libraries(game-objects PUBLIC sfml-system sfml-network sfml-graphics sfml-window managers)