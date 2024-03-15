add_library(game-system STATIC DeltaTime.cpp Camera.cpp GameObjectMover.cpp)
target_include_directories(game-system PUBLIC .)
target_link_libraries(game-system PUBLIC sfml-system sfml-network sfml-graphics sfml-window game-objects)