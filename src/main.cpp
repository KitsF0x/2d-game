#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameObjectsManager.hpp"
#include "PlayerGameObject.hpp"
#include "Log.hpp"
#include "DeltaTime.hpp"

int main(int argc, char *argv[])
{
    kf::Log::enableLogging = true;
    kf::Log::showTime = true;
    kf::Log::info("Starting game.");

    kf::Log::info("Creating game objects manager.");
    kf::GameObjectsManager manager{};

    kf::Log::info("Creating player game object.");
    manager.add(std::make_shared<kf::PlayerGameObject>());

    kf::Log::info("Creating SFML window.");
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");

    // Delta time
    kf::DeltaTime deltaTime;
    sf::Clock deltaClock;
    sf::Time firstMeasurement;
    sf::Time secondMeasurement;

    while (window.isOpen())
    {
        firstMeasurement = deltaClock.getElapsedTime();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                kf::Log::info("Detected window close event. Closing window.");
                window.close();
            }
        }
        window.clear();

        manager.updateAll(deltaTime.getDeltaTime());
        manager.drawAll(window);

        window.display();
        secondMeasurement = deltaClock.getElapsedTime();
        deltaTime.calculateDeltaTime(firstMeasurement, secondMeasurement);
    }

    return 0;
}