add_library(filesystem STATIC TexturesLoader.cpp)
target_include_directories(filesystem PUBLIC .)
target_link_libraries(filesystem PUBLIC managers)