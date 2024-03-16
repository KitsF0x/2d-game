add_library(managers STATIC 
    GameObjectsManager.cpp 
    GameObjectsManagerException.cpp 
    TexturesManager.cpp 
    TexturesManagerException.cpp 
    TilesManager.cpp
    GuiManager.cpp
    AManager.cpp
)

target_include_directories(managers PUBLIC .)
target_link_libraries(managers PUBLIC game-objects tiles)