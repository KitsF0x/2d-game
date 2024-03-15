#pragma once

#include <stdexcept>

namespace kf
{
    class GameObjectsManagerException : public std::runtime_error
    {
    public:
        GameObjectsManagerException(const std::string &gameObjectname, const std::string &cause);
    };
}