#pragma once

#include <SFML/Graphics.hpp>

#include "Sprite.hpp"
#include "Game.hpp"

namespace CMB
{
    class Player : public Sprite
    {
    public:
        Player() = default;
        Player(GameDataRef game);

        void create();
        void update(float dt);

        sf::Vector2i _movementVec{0, 0};
        GameDataRef _game;
    };
} // namespace CMB