#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "State.hpp"
#include "Pepe.hpp"
#include "PipeManager.hpp"

struct GameData;

namespace GameTools
{
    class GameScreen : public State
    {
    public:
        GameScreen(std::shared_ptr<GameData> data);

        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        std::shared_ptr<GameData> _data;
        sf::Sprite _background;
        Pepe pepe;

        //Debuggin ...
        bool isDebugging = false;
        sf::Text debugText;
        std::string debugValue;

        PipeManager pipeManager;
    };
} // namespace GameTools