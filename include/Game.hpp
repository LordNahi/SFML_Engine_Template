#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

#include "Managers/StateManager.hpp"
#include "Managers/AssetManager.hpp"
#include "Managers/CallbackManager.hpp"
#include "GameConfig.hpp"

namespace GameTools
{
    struct GameData
    {
        sf::RenderWindow window;
        StateManager stateManager;
        AssetManager assetManager;
        InputManager inputManager;
        CallbackManager callbackManager;
    };

    using GameDataRef = std::shared_ptr<GameData>;

    class Game
    {
    public:
        Game(int width, int height, std::string title);
        void Run();

    private:
        const double dt = 1000 / TARGET_FPS;
        sf::Clock _clock;

        GameDataRef _data = std::make_shared<GameData>();
    };
} // namespace GameTools