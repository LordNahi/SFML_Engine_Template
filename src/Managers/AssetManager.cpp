#include <iostream>

#include "Managers/AssetManager.hpp"

namespace CMB
{
    // TODO: Create a default asset to return for each asset type...

    void AssetManager::LoadTexture(std::string name, std::string filePath)
    {
        sf::Texture tex;

        if (tex.loadFromFile(filePath))
        {
            _textures[name] = tex;
        }
    }

    sf::Texture &AssetManager::GetTexture(std::string name)
    {
        return _textures.at(name);
    }

    void AssetManager::LoadFont(std::string name, std::string filePath)
    {
        sf::Font fnt;

        if (fnt.loadFromFile(filePath))
        {
            _fonts[name] = fnt;
            std::cout << "Font Loaded Successfully!" << std::endl;
        }
    }

    sf::Font &AssetManager::GetFont(std::string name)
    {
        return _fonts.at(name);
    }
} // namespace CMB