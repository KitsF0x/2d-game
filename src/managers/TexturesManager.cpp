#include "TexturesManager.hpp"

void kf::TexturesManager::addTexture(const std::string &name, sf::Texture texture)
{
    textures[name] = texture;
}

sf::Texture &kf::TexturesManager::getTexture(const std::string &name)
{
    if (textures.find(name) == textures.end())
    {
        throw kf::TexturesManagerException(name, "Texture not found");
    }
    return textures.at(name);
}

void kf::TexturesManager::removeTexture(const std::string &name)
{
    if (textures.find(name) == textures.end())
    {
        throw kf::TexturesManagerException(name, "Texture not found");
    }
    textures.erase(name);
}

std::size_t kf::TexturesManager::size() const
{
    return textures.size();
}
