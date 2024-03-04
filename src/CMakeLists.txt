add_subdirectory(game-objects)
add_subdirectory(log)
add_subdirectory(managers)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE log game-objects managers)