#pragma once

#include <string>
#include <filesystem>
#include <iostream>
#include <sys/stat.h>

#include "TexturesManager.hpp"

namespace kf
{
    class TexturesLoader
    {
    public:
        void loadTexturesFromDirectory(std::string path, kf::TexturesManager &texturesManager);
    };
}