#include <sstream>
#include <iostream>

#include "Screens/DefaultScreen.hpp"
#include "GameConfig.hpp"

namespace CMB
{
    DefaultScreen::DefaultScreen(GameDataRef data) : _data(data)
    {
    }

    void DefaultScreen::Init()
    {
        std::cout << "Init Default..." << std::endl;

        _data->assetManager.LoadTexture("default", "res/graphics/default.png");
        _data->assetManager.LoadTexture("run_down", "res/graphics/run_down.png");
        _data->assetManager.LoadTexture("test", "res/graphics/test.png");

        _defaultSprite.setTexture(this->_data->assetManager.GetTexture("test"));
        _defaultSprite.setScale({7, 7});
        _defaultSprite.setSpritesheet(32, 32, 8);

        _data->callbackManager.Register(
            "changeFrame", [this]() { _defaultSprite.frameForward(); }, 500, true);

        const sf::FloatRect defaultBounds = _defaultSprite.getGlobalBounds();

        _defaultSprite.setPosition({SCREEN_WIDTH / 2 - defaultBounds.width / 2, SCREEN_HEIGHT / 2 - defaultBounds.height / 2});
    }

    void DefaultScreen::HandleInput()
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

    void DefaultScreen::Update(float dt)
    {
        // Note: Example of adding a new state
        // _data->stateManager.AddState(StateRef(new YourNewScreen(_data)), true);
    }

    void DefaultScreen::Draw(float dt)
    {
        _data->window.clear(sf::Color{92, 219, 88, 255});
        _data->window.draw(_defaultSprite);
        _data->window.display();
    }
} // namespace CMB