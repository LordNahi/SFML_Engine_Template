#include <sstream>

#include "GameOverScreen.hpp"
#include "GameConfig.hpp"

#include <iostream>

namespace GameTools
{
    GameOverScreen::GameOverScreen(GameDataRef data) : _data(data)
    {
    }

    void GameOverScreen::Init()
    {
        std::cout << "Init GameOver..." << std::endl;

        // Load Assets ...
        _data->assetManager.LoadTexture("gameOverBackground", "res/graphics/bg.png");

        // Create our sprites ...
        _background.setTexture(this->_data->assetManager.GetTexture("gameOverBackground"));
    }

    void GameOverScreen::HandleInput()
    {
        sf::Event event;

        while (_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                _data->window.close();
            }
        }
    }

    void GameOverScreen::Update(float dt)
    {
    }

    void GameOverScreen::Draw(float dt)
    {
        _data->window.clear(sf::Color{255, 255, 255, 255});
        _data->window.draw(_background);
        _data->window.display();
    }
} // namespace GameTools