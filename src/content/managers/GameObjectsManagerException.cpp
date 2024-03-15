#include "GameObjectsManagerException.hpp"

kf::GameObjectsManagerException::GameObjectsManagerException(const std::string &gameObjectname, const std::string &cause)
    : std::runtime_error("GameObjectsManagerException: " + gameObjectname + " " + cause)
{
}