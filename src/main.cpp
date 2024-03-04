#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameObjectsManager.hpp"
#include "PlayerGameObject.hpp"
#include "DeltaTime.hpp"

int main(int argc, char *argv[])
{
    kf::GameObjectsManager manager{};
    manager.add(std::make_shared<kf::PlayerGameObject>());
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