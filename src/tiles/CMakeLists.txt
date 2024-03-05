add_library(tiles STATIC GrassTile.cpp)
target_include_directories(tiles PUBLIC .)
target_link_libraries(tiles PUBLIC sfml-system sfml-network sfml-graphics sfml-window managers)