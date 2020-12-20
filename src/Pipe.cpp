#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameConfig.hpp"
#include "Game.hpp"
#include "Pipe.hpp"
#include "Util.hpp"

namespace GameTools
{
    Pipe::Pipe(GameDataRef data) : _data(data)
    {
        pipeTop.setTexture(data->assetManager.GetTexture("pipe"));
        pipeTop.setRotation(180);

        pipeBottom.setTexture(data->assetManager.GetTexture("pipe"));
    }

    void Pipe::Spawn()
    {
        std::cout << "Pipe Spawned..." << std::endl;

        position.x = SCREEN_WIDTH;
        position.y = Util::Math::randRange(SCREEN_HEIGHT * 0.3, SCREEN_HEIGHT * 0.7);

        isActive = true;
    }

    void Pipe::Kill()
    {
        std::cout << "Pipe Killed..." << std::endl;

        isActive = false;
    }

    void Pipe::Update(float dt)
    {
        if (isActive)
        {
            position.x -= speed * dt;

            float texWidth = pipeTop.getGlobalBounds().width;

            pipeTop.setPosition({position.x + texWidth, position.y});
            pipeBottom.setPosition(position);

            if (position.x < -texWidth)
            {
                Kill();
            }
        }
    }

    void Pipe::Draw()
    {
        _data->window.draw(pipeTop);
        _data->window.draw(pipeBottom);
    }
} // namespace GameTools