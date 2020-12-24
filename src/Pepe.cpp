#include <algorithm>

#include "Pepe.hpp"

namespace GameTools
{
    Pepe::Pepe(GameDataRef data) : _data(data)
    {
        setTexture(_data->assetManager.GetTexture("pepe"));
        scale(0.7, 0.7);
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

            auto const pos = getPosition();

            setPosition(pos.x, pos.y + fallSpeed);

            std::cout << fallSpeed << std::endl;
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