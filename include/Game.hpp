#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

#include "Managers/ScreenManager.hpp"
#include "Managers/AssetManager.hpp"
#include "Managers/CallbackManager.hpp"
#include "GameConfig.hpp"

namespace CMB
{
    struct GameData
    {
        sf::RenderWindow window;
        ScreenManager screenManager;
        AssetManager assetManager;
        CallbackManager callbackManager;
    };

    using GameDataRef = std::shared_ptr<GameData>;

    class Game
    {
    public:
        Game(int width, int height, std::string title);
        void Run();

    private:
        const double _targetFrameDuration = 1000 / TARGET_FPS;
        sf::Clock _clock;

        GameDataRef _data = std::make_shared<GameData>();
    };
} // namespace CMB