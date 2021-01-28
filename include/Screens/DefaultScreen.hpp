#pragma once

#include <SFML/Graphics.hpp>

#include "Screen.hpp"
#include "Sprite.hpp"
#include "Game.hpp"

namespace CMB
{
    class DefaultScreen : public Screen
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
        CMB::Sprite _defaultSprite;
    };
} // namespace CMB