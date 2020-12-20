#include <sstream>

#include "Game.hpp"
#include "GameScreen.hpp"
#include "GameConfig.hpp"

#include <iostream>

namespace GameTools
{
    GameScreen::GameScreen(GameDataRef data) : _data(data)
    {
    }

    void GameScreen::Init()
    {
        std::cout << "Init GameScreen..." << std::endl;

        // Load Assets ...
        _data->assetManager.LoadTexture("gameBackground", "res/graphics/bg.png");
        _data->assetManager.LoadTexture("pipe", "res/graphics/pipe.png");
        _data->assetManager.LoadFont("welbut", "res/fonts/Welbut.ttf");

        // Create Background sprite ...
        _background.setTexture(this->_data->assetManager.GetTexture("gameBackground"));

        // Create Pipe Manager ...
        pipeManager = PipeManager{_data};
        pipeManager.Start();

        // Create Debug Text...
        debugText.setFont(_data->assetManager.GetFont("welbut"));
        debugText.setString("Debug Text:");
        debugText.setCharacterSize(32);
        debugText.setFillColor(sf::Color::White);
        debugText.setPosition(12, 12);
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
        pipeManager.Update(dt);
    }

    void GameScreen::Draw(float dt)
    {
        _data->window.clear(sf::Color{255, 255, 255, 255});

        _data->window.draw(_background);
        pipeManager.Draw(dt);

        if (isDebugging)
        {
            debugValue = "Debug:\n";
            debugValue += "DT: " + std::to_string(dt) + "\n";

            debugText.setString(debugValue);

            _data->window.draw(debugText);
        }

        _data->window.display();
    }
} // namespace GameTools
