#include <iostream>

#include "GameConfig.hpp"
#include "Managers/AssetManager.hpp"

namespace CMB
{
    AssetManager::AssetManager()
    {
        // Load necessary default assets ...
        _defaultTexture.loadFromFile(SPRITE_DEFAULT);
    }

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
        if (_textures.contains(name))
        {
            return _textures.at(name);
        }
        else
        {
            return _defaultTexture;
        }
    }

    void AssetManager::LoadFont(std::string name, std::string filePath)
    {
        sf::Font fnt;

        if (fnt.loadFromFile(filePath))
        {
            _fonts[name] = fnt;
        }
    }

    sf::Font &AssetManager::GetFont(std::string name)
    {
        return _fonts.at(name);
    }
} // namespace CMB