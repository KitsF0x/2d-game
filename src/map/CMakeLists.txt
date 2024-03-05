add_library(map RandomTileGenerator.cpp)
target_include_directories(map PUBLIC .)
target_link_libraries(map PRIVATE managers tiles)