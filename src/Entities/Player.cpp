#include <algorithm>

#include "Entities/Player.hpp"

namespace CMB
{
    Player::Player(GameDataRef data) : _game(data)
    {
        setTexture(_game->assetManager.GetTexture("pepe"));
        setOrigin(getGlobalBounds().width / 2, getGlobalBounds().height / 2);
    }

    void Player::Update(float dt)
    {
    }
} // namespace CMB