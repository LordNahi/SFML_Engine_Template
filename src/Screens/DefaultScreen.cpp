#include <sstream>
#include <iostream>

#include "Screens/DefaultScreen.hpp"
#include "GameConfig.hpp"

namespace CMB
{
    DefaultScreen::DefaultScreen(GameDataRef game) : _game(game)
    {
    }

    void DefaultScreen::Init()
    {
        std::cout << "Init Default..." << std::endl;

        _game->assetManager.LoadTexture("default", "res/graphics/default.png");
        _game->assetManager.LoadTexture("run_down", "res/graphics/run_down.png");
        _game->assetManager.LoadTexture("test", "res/graphics/test.png");

        _defaultSprite.setTexture(_game->assetManager.GetTexture("test"));
        _defaultSprite.setScale({7, 7});
        _defaultSprite.setSpritesheet(32, 32, 8);

        const sf::FloatRect defaultBounds = _defaultSprite.getGlobalBounds();

        _defaultSprite.setPosition({SCREEN_WIDTH / 2 - defaultBounds.width / 2, SCREEN_HEIGHT / 2 - defaultBounds.height / 2});
    }

    void DefaultScreen::HandleInput()
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

    void DefaultScreen::Update(float dt)
    {
        // Note: Example of adding a new state
        // _game->stateManager.AddState(ScreenRef(new YourNewScreen(_game)), true);
    }

    void DefaultScreen::Draw(float dt)
    {
        _game->window.clear(sf::Color{92, 219, 88, 255});
        _game->window.draw(_defaultSprite);
        _game->window.display();
    }
} // namespace CMB