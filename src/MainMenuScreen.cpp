#include <sstream>

#include "MainMenuScreen.hpp"
#include "GameConfig.hpp"

#include <iostream>

namespace GameTools
{
    MainMenuScreen::MainMenuScreen(GameDataRef data) : _data(data)
    {
    }

    void MainMenuScreen::Init()
    {
        std::cout << "Init..." << std::endl;

        // Load Assets ...
        _data->assetManager.LoadTexture("background", "res/graphics/bg.png");
        _data->assetManager.LoadTexture("title", "res/graphics/title.png");
        _data->assetManager.LoadTexture("playButton", "res/graphics/play.png");

        // Create our sprites ...
        _background.setTexture(this->_data->assetManager.GetTexture("background"));

        _title.setTexture(this->_data->assetManager.GetTexture("title"));
        _title.setOrigin({_title.getGlobalBounds().width / 2, _title.getGlobalBounds().height / 2});
        _title.setPosition({SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.3f});

        _playButton.setTexture(this->_data->assetManager.GetTexture("playButton"));
        _playButton.setOrigin({_playButton.getGlobalBounds().width / 2, _playButton.getGlobalBounds().height / 2});
        _playButton.setPosition({SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f});
    }

    void MainMenuScreen::HandleInput()
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

    void MainMenuScreen::Update(float dt)
    {
    }

    void MainMenuScreen::Draw(float dt)
    {
        _data->window.clear(sf::Color{255, 255, 255, 255});
        _data->window.draw(_background);
        _data->window.draw(_playButton);
        _data->window.draw(_title);
        _data->window.display();
    }
} // namespace GameTools