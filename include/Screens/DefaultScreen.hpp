#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"

namespace CMB
{
    class DefaultScreen : public State
    {
    public:
        DefaultScreen(GameDataRef data);

        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        GameDataRef _data;

        sf::Clock _clock;
        sf::Sprite _defaultSprite;
    };
} // namespace CMB