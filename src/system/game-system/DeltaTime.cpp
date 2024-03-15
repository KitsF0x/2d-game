#include "DeltaTime.hpp"

float kf::DeltaTime::getDeltaTime() const
{
    return deltaTime;
}

void kf::DeltaTime::calculateDeltaTime(sf::Time firstMeasurement, sf::Time secondMeasurement)
{
    deltaTime = secondMeasurement.asSeconds() - firstMeasurement.asSeconds();
}
