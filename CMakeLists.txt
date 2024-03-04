cmake_minimum_required(VERSION 3.0.0)
project(2d-game)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
find_package(Catch2 CONFIG REQUIRED)

add_subdirectory(src)
add_subdirectory(test)