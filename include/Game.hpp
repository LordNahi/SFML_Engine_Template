#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

#include "StateManager.hpp"
#include "Assetmanager.hpp"
#include "InputManager.hpp"

#define TARGET_FRAME_RATE 60.0f

namespace GameTools
{
    struct GameData
    {
        sf::RenderWindow window;
        StateManager stateManager;
        AssetManager assetManager;
        InputManager InputManager;
    };

    typedef std::shared_ptr<GameData> GameDataRef;

    class Game
    {
    public:
        Game(int width, int height, std::string title);

    private:
        const float dt = 1.0f / TARGET_FRAME_RATE;
        sf::Clock _clock;

        GameDataRef _data = std::make_shared<GameData>();

        void Run();
    };
} // namespace GameTools