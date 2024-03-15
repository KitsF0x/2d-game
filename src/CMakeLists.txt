add_subdirectory(content)
add_subdirectory(system)
add_subdirectory(map)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE game-objects managers game-system filesystem tiles map)