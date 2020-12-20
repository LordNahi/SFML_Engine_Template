#include <iostream>
#include <chrono>
#include <thread>

#include "Game.hpp"
#include "DefaultScreen.hpp"

namespace GameTools
{
    Game::Game(int width, int height, std::string title)
    {
        _data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
        _data->stateManager.AddState(StateRef(new DefaultScreen(_data)));
        Run();
    }

    void Game::Run()
    {
        float newTime, frameTime, interpolation;

        float currentTime = _clock.getElapsedTime().asMilliseconds();
        float accumulator = 0.0f;

        while (_data->window.isOpen())
        {
            _data->stateManager.ProcessStateChanges();

            newTime = _clock.getElapsedTime().asMilliseconds();
            frameTime = newTime - currentTime;

            // This is limiting the game from spending too long
            // running in the input/update section ...
            if (frameTime > 0.25f)
            {
                frameTime = 0.25f;
            }

            currentTime = newTime;
            accumulator += frameTime;

            while (accumulator >= dt)
            {
                // Input/Update operations go here ...
                _data->stateManager.GetActiveState()->HandleInput();
                _data->stateManager.GetActiveState()->Update(dt);

                accumulator -= dt;
            }

            // Interpolation is calculated to be used in "Far Seeing", essentially
            // used to make accurate calculation of where to draw something moving.
            //
            //
            // My interpretation from https://bell0bytes.eu/the-game-loop/
            //
            // 'interpolation' will contain a normalized value representing how far ahead
            // we can render objects. If we have a movement speed of 500px per frame, we
            // can instead run 500*interpolation to get more accurate rendering...

            interpolation = accumulator / dt;
            _data->stateManager.GetActiveState()->Draw(interpolation);
        }
    }
} // namespace GameTools
