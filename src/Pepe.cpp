#include <algorithm>

#include "Pepe.hpp"

namespace GameTools
{
    Pepe::Pepe(GameDataRef data) : _data(data)
    {
        setTexture(_data->assetManager.GetTexture("pepe"));
        setOrigin(getGlobalBounds().width / 2, getGlobalBounds().height / 2);
        Reset();
    }

    void Pepe::Update(float dt)
    {
        if (isActive)
        {
            // Clamp the fallspeed ...
            fallSpeed = fallSpeed + gravity;
            if (fallSpeed > fallSpeedMax)
            {
                fallSpeed = fallSpeedMax;
            }

            // Clamp rotation ...
            const auto currentRot = getRotation();
            const auto newRot = currentRot + 1;
            if (fallSpeed < 0)
            {
                setRotation(rotationMin);
            }
            else
            {
                currentRot > rotationMax ? setRotation(rotationMax) : setRotation(newRot);
                currentRot < rotationMin ? setRotation(rotationMin) : setRotation(newRot);
            }

            auto const pos = getPosition();
            setPosition(pos.x, pos.y + fallSpeed);
        }
    }

    void Pepe::Reset()
    {
        isActive = false;
        fallSpeed = 0.0f;

        setPosition(
            SCREEN_WIDTH / 2 - getTextureRect().width / 2,
            SCREEN_HEIGHT / 2 - getTextureRect().height / 2);
    }

    void Pepe::Flap()
    {
        if (isActive)
        {
            fallSpeed = -jumpGain;
        }
        else
        {
            isActive = true;
        }
    }
} // namespace GameTools