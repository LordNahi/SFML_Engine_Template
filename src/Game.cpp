#include <iostream>
#include <chrono>
#include <thread>

#include "Screens/DefaultScreen.hpp"
#include "Game.hpp"

namespace CMB
{
    Game::Game(int width, int height, std::string title)
    {
        _game->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
        _game->screenManager.AddScreen(ScreenRef(new DefaultScreen(_game)));
    }

    void Game::HandleWindowEvent()
    {
        sf::Event event;

        while (_game->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                _game->window.close();
            }
        }
    }

    void Game::Run()
    {
        double previousFrameDuration = 0;
        double accumulator = 0;

        int currentTime, interpolation;
        int previousTime = _clock.getElapsedTime().asMilliseconds();

        while (_game->window.isOpen())
        {
            // Begin by checking if we need to transition screen ...
            _game->screenManager.ProcessScreenChanges();

            // Calculate time taken to render last frame ...
            currentTime = _clock.getElapsedTime().asMilliseconds();
            previousFrameDuration = currentTime - previousTime;

            /**
             * Here we clamp the max update duration (milliseconds) to prevent slow PCs
             * spending too long in the Update loop and move onto drawing something
             * to the screen.
             * 
             * `maxUpdateDuration`, measured in ms, determines how much the update
             * loop will be allowed to catch up before a new frame is drawn.
             * 
             * The idea here being that if the game begins to do expensive draw operations
             * and the time spent drawing exceeds our `_targetFrameDuration`, we handle
             * input then update our game logic negate, _targetFrameDuration from the
             * accumulator and continue drawing ...
             **/
            const int maxUpdateDuration = 250;
            if (previousFrameDuration > maxUpdateDuration)
            {
                previousFrameDuration = maxUpdateDuration;
            }

            // previousTime reset
            previousTime = currentTime;
            accumulator += previousFrameDuration;

            // Update loop ...
            while (accumulator >= _targetFrameDuration)
            {
                _game->screenManager.GetActiveState()->Update(_targetFrameDuration / 100);

                accumulator -= _targetFrameDuration;
            }

            // Interpolation is calculated to be used in "Far Seeing", essentially
            // used to make accurate calculation of where to draw something moving.
            //
            // My interpretation from https://bell0bytes.eu/the-game-loop/
            //
            // 'interpolation' will contain a normalized value representing how far ahead
            // we can render objects. If we have a movement speed of 500px per frame, we
            // can instead run 500*interpolation to get more accurate rendering...

            interpolation = accumulator / _targetFrameDuration;
            _game->screenManager.GetActiveState()->Draw(interpolation);

            HandleWindowEvent();
        }
    }
} // namespace CMB
