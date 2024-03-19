#pragma once
#include <string>

#include <SFML/Graphics.hpp>

#include "IManageable.hpp"

namespace kf
{
    class IState : public IManageable
    {
    public:
        virtual void handleEvents(sf::Event &event) = 0;
        virtual ~IState() = default;
    };
}