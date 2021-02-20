#pragma once

#include <SFML/Graphics.hpp>

#include "Sprite.hpp"
#include "Game.hpp"

namespace CMB
{
    class Player
    {
    public:
        Player() = default;
        Player(GameDataRef game);

        void create();
        void update(float dt);
        void draw(float dt);
        void updatePosition(float dt);

    private:
        Sprite m_body;
        Sprite m_legs;
        sf::Vector2i m_movementVec{0, 0};
        GameDataRef m_game;
    };
} // namespace CMB