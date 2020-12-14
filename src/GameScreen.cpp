#include <sstream>

#include "GameScreen.hpp"
#include "GameOverScreen.hpp"
#include "GameConfig.hpp"

#include <iostream>

namespace GameTools
{
    GameScreen::GameScreen(GameDataRef data) : _data(data)
    {
    }

    void GameScreen::Init()
    {
        std::cout << "Init..." << std::endl;

        // Load Assets ...
        _data->assetManager.LoadTexture("gameBackground", "res/graphics/bg.png");

        // Create our sprites ...
        _background.setTexture(this->_data->assetManager.GetTexture("gameBackground"));
    }

    void GameScreen::HandleInput()
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

    void GameScreen::Update(float dt)
    {
    }

    void GameScreen::Draw(float dt)
    {
        _data->window.clear(sf::Color{255, 255, 255, 255});
        _data->window.draw(_background);
        _data->window.display();
    }
} // namespace GameTools
