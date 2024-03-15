add_library(game-objects STATIC PlayerGameObject.cpp RockGameObject.cpp)
target_include_directories(game-objects PUBLIC .)
target_link_libraries(game-objects PUBLIC sfml-system sfml-network sfml-graphics sfml-window managers game-system entities-interfaces)