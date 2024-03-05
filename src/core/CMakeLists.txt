add_library(core STATIC DeltaTime.cpp Camera.cpp)
target_include_directories(core PUBLIC .)
target_link_libraries(core PUBLIC sfml-system sfml-network sfml-graphics sfml-window)