#include <iostream>
#include <chrono>
#include <thread>

#include "Screens/DefaultScreen.hpp"
#include "Game.hpp"

namespace CMB
{
    Game::Game(int width, int height, std::string title)
    {
        _data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
        _data->stateManager.AddState(StateRef(new DefaultScreen(_data)));
    }

    void Game::Run()
    {
        int frameTime, currentTime, interpolation;

        int previousTime = _clock.getElapsedTime().asMilliseconds();
        int accumulator = 0;

        while (_data->window.isOpen())
        {
            _data->stateManager.ProcessStateChanges();

            currentTime = _clock.getElapsedTime().asMilliseconds();
            frameTime = currentTime - previousTime;

            /**
             * Here we clamp the max frame time (milliseconds) to prevent slow PCs
             * spending too long in the Update loop. We will need to save time for
             * the drawing phase ...
             **/
            const int maxFrameTime = 250;
            if (frameTime > maxFrameTime)
            {
                frameTime = maxFrameTime;
            }

            // previousTime reset
            previousTime = currentTime;
            accumulator += frameTime;

            // Update loop ...
            while (accumulator >= dt)
            {
                _data->stateManager.GetActiveState()->HandleInput();
                _data->stateManager.GetActiveState()->Update(dt);

                accumulator -= dt;
            }

            // Interpolation is calculated to be used in "Far Seeing", essentially
            // used to make accurate calculation of where to draw something moving.
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
} // namespace CMB
