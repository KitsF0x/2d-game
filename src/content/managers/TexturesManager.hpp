#pragma once
#include <unordered_map>
#include <string>
#include <memory>

#include <SFML/Graphics.hpp>

#include "TexturesManagerException.hpp"

namespace kf
{
    class TexturesManager
    {
    private:
        std::unordered_map<std::string, sf::Texture> textures;

    public:
        void addTexture(const std::string &name, sf::Texture texture);
        sf::Texture &getTexture(const std::string &name);
        void removeTexture(const std::string &name);
        std::size_t size() const;
    };
}