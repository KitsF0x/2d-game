#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameObjectsManager.hpp"
#include "PlayerGameObject.hpp"
#include "Log.hpp"

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

    while (window.isOpen())
    {
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

        manager.updateAll(1);
        manager.drawAll(window);

        window.display();
    }

    return 0;
}