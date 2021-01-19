#include <sstream>

#include "Screens/GameScreen.hpp"
#include "Game.hpp"
#include "GameConfig.hpp"

#include <iostream>
#include <string>

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
        _data->assetManager.LoadTexture("pepe", "res/graphics/pepe.png");
        _data->assetManager.LoadFont("welbut", "res/fonts/Welbut.ttf");

        // Create Background sprite ...
        _background.setTexture(this->_data->assetManager.GetTexture("gameBackground"));

        // Create Pipe Manager ...
        pipeManager = PipeManager{_data};
        pipeManager.OnScore([this]() { this->score += 1; });

        // Create Pepe ...
        pepe = Pepe{_data};

        // Create Debug Text...
        scoreText.setFont(_data->assetManager.GetFont("welbut"));
        scoreText.setString("0");
        scoreText.setCharacterSize(32);
        scoreText.setFillColor(sf::Color::White);
        scoreText.setPosition(12, 12);
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

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    if (!pipeManager.GetIsRunning())
                        pipeManager.Start();

                    pepe.Flap();
                }
            }
        }
    }

    void GameScreen::Update(float dt)
    {
        scoreText.setString(std::to_string(score));
        pipeManager.Update(dt);
        pepe.Update(dt);

        if (pipeManager.IsColliding(pepe))
        {
            std::cout << "COLLIDING" << std::endl;

            pipeManager.Reset();
            pepe.Reset();
            score = 0;
        }
    }

    void GameScreen::Draw(float dt)
    {
        _data->window.clear(sf::Color{255, 255, 255, 255});

        _data->window.draw(_background);
        _data->window.draw(pepe);
        _data->window.draw(scoreText);
        pipeManager.Draw(dt);

        _data->window.display();
    }
} // namespace GameTools
