#include <algorithm>

#include "Entities/Player.hpp"

namespace CMB
{
    Player::Player(GameDataRef game) : _game(game)
    {
        setTexture(_game->assetManager.GetTexture("run_down"));
        setScale({7, 7});
        setSpritesheet(32, 32, 4);

        animationAdd("walk", {0, 1, 2, 3});
    }

    void Player::update(float dt)
    {
        Sprite::update(dt);

        const int speed = 15 * dt;
        auto position = getPosition();

        // Movement ...
        // TODO: Fix classic diagonal speed issue ...

        animationStop(); // ):<
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            setTexture(_game->assetManager.GetTexture("run_left"));
            animationPlay("walk", 5, true);
            position.x -= speed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            setTexture(_game->assetManager.GetTexture("run_right"));
            animationPlay("walk", 5, true);
            position.x += speed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            setTexture(_game->assetManager.GetTexture("run_up"));
            animationPlay("walk", 5, true);
            position.y -= speed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            setTexture(_game->assetManager.GetTexture("run_down"));
            animationPlay("walk", 5, true);
            position.y += speed;
        }

        setPosition(position);
    }

} // namespace CMB