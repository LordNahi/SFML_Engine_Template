#pragma once

#include <SFML/Graphics.hpp>

#include "Screen.hpp"
#include "Entities/Player.hpp"

namespace CMB
{
    class DefaultScreen : public Screen
    {
    public:
        DefaultScreen(GameDataRef game);

        void Init();
        void Update(float dt);
        void Draw(float dt);

    private:
        GameDataRef _game;
        Player _player;
    };
} // namespace CMB