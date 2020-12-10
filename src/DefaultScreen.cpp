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
        _background.setTexture(this->_data->assetManager.GetTexture("success"));
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
        std::cout << "Updating..." << std::endl;
    }

    void DefaultScreen::Draw(float dt)
    {
        _data->window.clear(sf::Color{255, 255, 255, 255});
        _data->window.draw(_background);
        _data->window.display();
    }
} // namespace GameTools