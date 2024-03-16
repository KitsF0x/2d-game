add_library(gui-components STATIC Cursor.cpp)
target_include_directories(gui-components PUBLIC .)
target_link_libraries(gui-components PUBLIC sfml-system sfml-network sfml-graphics sfml-window entities-interfaces)