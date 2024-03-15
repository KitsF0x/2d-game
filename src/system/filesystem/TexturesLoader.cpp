#include "TexturesLoader.hpp"

void kf::TexturesLoader::loadTexturesFromDirectory(std::string path, kf::TexturesManager &texturesManager)
{
    for (auto &el : std::filesystem::directory_iterator(path))
    {
        std::filesystem::path outFilename = el.path();
        std::string filename = outFilename.filename().string();

        std::string filenameWithoutExtension = filename.substr(0, filename.find_last_of('.'));

        for (int i = 0; i < filenameWithoutExtension.size(); i++)
        {
            filenameWithoutExtension[i] = std::toupper(filenameWithoutExtension[i]);
            if (filenameWithoutExtension[i] == ' ')
            {
                filenameWithoutExtension[i] = '_';
            }
        }

        sf::Texture texture;
        texture.loadFromFile(path + "/" + filename);
        texturesManager.addTexture(filenameWithoutExtension, texture);
        std::cout << "Loaded texture: " << path + "/" + filename << " as " << filenameWithoutExtension << std::endl;
    }

    std::cout << "Added " << texturesManager.size() << " textures" << std::endl;
}