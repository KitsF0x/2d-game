#pragma once

#include <SFML/System/Time.hpp>

namespace kf
{
    class DeltaTime
    {
    private:
        float deltaTime{0};

    public:
        float getDeltaTime() const;
        void calculateDeltaTime(sf::Time firstMeasurement, sf::Time secondMeasurement);
    };
}