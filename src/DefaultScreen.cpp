#include <sstream>

#include "DefaultScreen.hpp"
#include "GameConfig.hpp"

#include <iostream>

namespace GameTools
{
    DefaultScreen::DefaultScreen(GameDataRef data) : _data(data)
    {
    }

    void DefaultScreen::Init()
    {
        std::cout << "Init..." << std::endl;

        _data->assetManager.LoadTexture("success", "res/graphics/success.png");
        _defaultSprite.setTexture(this->_data->assetManager.GetTexture("success"));

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
        if (_clock.getElapsedTime().asSeconds() > 3)
        {
            std::cout << "FUCK" << std::endl;
        }
    }

    void DefaultScreen::Draw(float dt)
    {
        _data->window.clear(sf::Color{255, 255, 255, 255});
        _data->window.draw(_defaultSprite);
        _data->window.display();
    }
} // namespace GameTools