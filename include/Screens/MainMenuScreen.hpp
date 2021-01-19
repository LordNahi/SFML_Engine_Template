#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"

namespace GameTools
{
    class MainMenuScreen : public State
    {
    public:
        MainMenuScreen(GameDataRef data);

        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        GameDataRef _data;

        sf::Sprite _background;
        sf::Sprite _title;
        sf::Sprite _playButton;
    };
} // namespace GameTools