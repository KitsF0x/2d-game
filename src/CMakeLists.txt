add_subdirectory(core)
add_subdirectory(filesystem)
add_subdirectory(game-objects)
add_subdirectory(managers)
add_subdirectory(tiles)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE game-objects managers core filesystem tiles)