add_library(tiles STATIC GrassTile.cpp SandTile.cpp TileConsts.cpp)
target_include_directories(tiles PUBLIC .)
target_link_libraries(tiles PUBLIC sfml-system sfml-network sfml-graphics sfml-window managers entities-interfaces)