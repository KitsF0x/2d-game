#pragma once

#include "IManageable.hpp"

namespace kf
{
    class AManager
    {
    protected:
        std::vector<std::shared_ptr<IManageable>> entities;

    public:
        void add(std::shared_ptr<IManageable> entity);
        void remove(std::shared_ptr<IManageable> entity);
        std::size_t size() const;

        virtual void updateAll(float deltaTime) = 0;
        virtual void drawAll(sf::RenderWindow &window) = 0;
        virtual ~AManager() = default;
    };
}