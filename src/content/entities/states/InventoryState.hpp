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
#include "StatesManager.hpp"

namespace kf
{
    class InventoryState : public IState
    {
    private:
        kf::StatesManager &statesManager;   

    public:
        InventoryState(kf::StatesManager &statesManager);
        void handleEvents(sf::Event &event) override;
        void draw(sf::RenderWindow &window) override;
        void update(float deltaTime) override;
    };
}