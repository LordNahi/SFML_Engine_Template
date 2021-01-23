#include <algorithm>

#include "Entities/Player.hpp"

namespace GameTools
{
    Player::Player(GameDataRef data) : _data(data)
    {
        setTexture(_data->assetManager.GetTexture("pepe"));
        setOrigin(getGlobalBounds().width / 2, getGlobalBounds().height / 2);
    }

    void Player::Update(float dt)
    {
        }
} // namespace GameTools