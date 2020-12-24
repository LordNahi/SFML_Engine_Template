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
        pipeTop.setPosition({-999, 0});
        pipeTop.setRotation(180);

        pipeBottom.setTexture(data->assetManager.GetTexture("pipe"));
        pipeBottom.setPosition({-999, 0});

        // Cheat way to set the initial position? ...
        Kill();
    }

    void Pipe::Spawn()
    {
        std::cout << "Pipe Spawned..." << std::endl;

        isActive = true;
    }

    void Pipe::Kill()
    {
        std::cout << "Pipe Killed..." << std::endl;

        isActive = false;

        auto const resetPos = sf::Vector2i{SCREEN_WIDTH, Util::Math::randRange(SCREEN_HEIGHT * 0.3, SCREEN_HEIGHT * 0.7)};

        position.x = resetPos.x;
        position.y = resetPos.y;

        float texWidth = pipeTop.getGlobalBounds().width;

        pipeTop.setPosition({resetPos.x + texWidth, position.y - pipeGap / 2});
        pipeBottom.setPosition({resetPos.x, position.y + pipeGap / 2});
    }

    void Pipe::Update(float dt)
    {
        if (isActive)
        {
            position.x -= speed;

            float texWidth = pipeTop.getGlobalBounds().width;

            pipeTop.setPosition({position.x + texWidth, position.y - pipeGap / 2});
            pipeBottom.setPosition({position.x, position.y + pipeGap / 2});

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

    bool Pipe::IsColliding(sf::Sprite sprite)
    {
        auto const spriteBounds = sprite.getGlobalBounds();
        auto const pipeTopBounds = pipeTop.getGlobalBounds();
        auto const pipeBottomBounds = pipeBottom.getGlobalBounds();

        if (spriteBounds.intersects(pipeTopBounds) || spriteBounds.intersects(pipeBottomBounds))
        {
            return true;
        }

        return false;
    }
} // namespace GameTools