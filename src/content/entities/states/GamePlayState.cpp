#include "GamePlayState.hpp"

kf::GamePlayState::GamePlayState(kf::TexturesManager &texturesManager, sf::RenderWindow &window)
    : window(window)
{
    tilesManager = new kf::TilesManager{texturesManager};
    randomTileGenerator.generate(*tilesManager, {0.0f, 0.0f});

    gameObjectsManager.add(std::make_shared<kf::PlayerGameObject>(), texturesManager);
    gameObjectsManager.add(std::make_shared<kf::RockGameObject>(), texturesManager);

    guiManager.add(std::make_shared<kf::Cursor>(window));
    camera = new kf::Camera{window};

    player = gameObjectsManager.getGameObjectsByName("Player").at(0);
}

void kf::GamePlayState::handleEvents(sf::Event &event)
{

    if (event.type == sf::Event::MouseWheelMoved)
    {
        if (event.mouseWheel.delta == 1)
        {
            camera->zoomIn();
        }
        else if (event.mouseWheel.delta == -1)
        {
            camera->zoomOut();
        }
    }
}

void kf::GamePlayState::draw(sf::RenderWindow &window)
{
    tilesManager->drawAll(window);
    gameObjectsManager.drawAll(window);
    guiManager.drawAll(window);
}

void kf::GamePlayState::update(float deltaTime)
{
    camera->update(player->getPosition());
    gameObjectsManager.updateAll(deltaTime);
    guiManager.updateAll(deltaTime);
}

kf::GamePlayState::~GamePlayState()
{
    delete tilesManager;
    delete camera;
}
