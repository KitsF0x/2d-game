add_library(states STATIC GamePlayState.cpp InventoryState.cpp)
target_include_directories(gui-components PUBLIC .)
target_link_libraries(states PUBLIC sfml-system sfml-network sfml-graphics sfml-window entities-interfaces map gui-components)