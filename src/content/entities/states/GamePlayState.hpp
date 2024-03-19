#pragma once

#include "IState.hpp"

#include "TilesManager.hpp"
#include "RandomTileGenerator.hpp"
#include "GameObjectsManager.hpp"
#include "GuiManager.hpp"
#include "Camera.hpp"
#include "PlayerGameObject.hpp"
#include "RockGameObject.hpp"
#include "Cursor.hpp"

namespace kf
{
    class GamePlayState : public IState
    {
    private:
        kf::TilesManager *tilesManager;
        kf::RandomTileGenerator randomTileGenerator{20, 20};
        kf::GameObjectsManager gameObjectsManager;
        kf::GuiManager guiManager;
        kf::Camera *camera;

        sf::RenderWindow &window;

        std::shared_ptr<kf::IGameObject> player;

    public:
        GamePlayState(kf::TexturesManager &texturesManager, sf::RenderWindow &window);
        void handleEvents(sf::Event &event) override;
        void draw(sf::RenderWindow &window) override;
        void update(float deltaTime) override;
        ~GamePlayState();
    };
}