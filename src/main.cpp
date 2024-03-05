#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameObjectsManager.hpp"
#include "PlayerGameObject.hpp"
#include "DeltaTime.hpp"
#include "TexturesLoader.hpp"
#include "TexturesManager.hpp"
#include "TilesManager.hpp"
#include "GrassTile.hpp"
#include "SandTile.hpp"
#include "Camera.hpp"
#include "RandomTileGenerator.hpp"
#include "RockGameObject.hpp"

int main(int argc, char *argv[])
{
    // Textures
    kf::TexturesManager texturesManager{};
    kf::TexturesLoader texturesLoader{};
    texturesLoader.loadTexturesFromDirectory("../../../assets/textures/", texturesManager);

    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");

    // Delta time
    kf::DeltaTime deltaTime;
    sf::Clock deltaClock;
    sf::Time firstMeasurement;
    sf::Time secondMeasurement;

    // Tiles
    kf::TilesManager tilesManager{texturesManager};
    kf::RandomTileGenerator randomTileGenerator{20, 20};
    randomTileGenerator.generate(tilesManager, {0.0f, 0.0f});

    // Game objects
    kf::GameObjectsManager gameObjectsManager{};
    gameObjectsManager.add(std::make_shared<kf::PlayerGameObject>(), texturesManager);
    gameObjectsManager.add(std::make_shared<kf::RockGameObject>(), texturesManager);

    kf::Camera camera{window};
    std::shared_ptr<kf::IGameObject> player = gameObjectsManager.getGameObjectsByName("Player").at(0);

    while (window.isOpen())
    {
        firstMeasurement = deltaClock.getElapsedTime();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::MouseWheelMoved)
            {
                if (event.mouseWheel.delta == 1)
                {
                    camera.zoomIn();
                }
                else if (event.mouseWheel.delta == -1)
                {
                    camera.zoomOut();
                }
            }
        }

        // Render
        window.clear();
        camera.update(player->getPosition());
        tilesManager.drawAll(window);
        gameObjectsManager.updateAll(deltaTime.getDeltaTime());
        gameObjectsManager.drawAll(window);

        // Delta time
        window.display();
        secondMeasurement = deltaClock.getElapsedTime();
        deltaTime.calculateDeltaTime(firstMeasurement, secondMeasurement);
    }

    return 0;
}