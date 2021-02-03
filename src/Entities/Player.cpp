#include <algorithm>

#include "Entities/Player.hpp"

namespace CMB
{
    Player::Player(GameDataRef game) : _game(game)
    {
        setTexture(_game->assetManager.GetTexture("run_down"));
        setScale({4, 4});
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

        // Reset movement vec ...
        _movementVec = {0, 0};

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            setTexture(_game->assetManager.GetTexture("run_left"));
            _movementVec.x = -1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            setTexture(_game->assetManager.GetTexture("run_right"));
            _movementVec.x = 1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            setTexture(_game->assetManager.GetTexture("run_up"));
            _movementVec.y = -1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            setTexture(_game->assetManager.GetTexture("run_down"));
            _movementVec.y = 1;
        }

        if (_movementVec.x != 0 || _movementVec.y != 0)
        {
            // Moving ...
            animationPlay("walk", 8, true);

            const int speed = 15;
            const float xx = speed * dt * _movementVec.x;
            const float yy = speed * dt * _movementVec.y;

            position.x += xx;
            position.y += yy;
        }
        else
        {
            animationStop();
        }

        setPosition(position);
    }

} // namespace CMB