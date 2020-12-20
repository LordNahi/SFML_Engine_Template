#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

#include "GameConfig.hpp"
#include "StateManager.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"
#include "TimingManager.hpp"

namespace GameTools
{
    struct GameData
    {
        sf::RenderWindow window;
        StateManager stateManager;
        AssetManager assetManager;
        InputManager inputManager;
        TimingManager timingManager;
    };

    using GameDataRef = std::shared_ptr<GameData>;

    class Game
    {
    public:
        Game(int width, int height, std::string title);

    private:
        const float dt = 1.0f / TARGET_FPS;
        sf::Clock _clock;

        GameDataRef _data = std::make_shared<GameData>();

        void Run();
    };
} // namespace GameTools