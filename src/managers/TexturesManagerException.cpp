#include "TexturesManagerException.hpp"

kf::TexturesManagerException::TexturesManagerException(const std::string &textureName, const std::string &cause)
    : std::runtime_error("TexturesManagerException: " + textureName + " " + cause)
{
}