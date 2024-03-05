#pragma once

#include <stdexcept>

namespace kf
{
    class TexturesManagerException : public std::runtime_error
    {
    public:
        TexturesManagerException(const std::string &textureName, const std::string &cause);
    };
}