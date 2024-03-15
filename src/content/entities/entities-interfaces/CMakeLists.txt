add_library(entities-interfaces INTERFACE)
target_include_directories(entities-interfaces INTERFACE .)
target_link_libraries(entities-interfaces INTERFACE sfml-system sfml-network sfml-graphics sfml-window managers game-system)