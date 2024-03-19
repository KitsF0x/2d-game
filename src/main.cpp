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
#include "GuiManager.hpp"
#include "Cursor.hpp"

#include "StatesManager.hpp"
#include "GamePlayState.hpp"

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

    kf::StatesManager statesManager;
    statesManager.add(std::make_shared<kf::GamePlayState>(texturesManager, window, statesManager));

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
            statesManager.handleEvents(event);
        }

        // Render
        window.clear();

        statesManager.drawAll(window);
        statesManager.updateAll(deltaTime.getDeltaTime());

        // Delta time
        window.display();
        secondMeasurement = deltaClock.getElapsedTime();
        deltaTime.calculateDeltaTime(firstMeasurement, secondMeasurement);
    }

    return 0;
}