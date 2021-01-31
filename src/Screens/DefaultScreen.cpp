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

        _game->assetManager.LoadTexture("run_up", "res/graphics/run_up.png");
        _game->assetManager.LoadTexture("run_down", "res/graphics/run_down.png");
        _game->assetManager.LoadTexture("run_left", "res/graphics/run_left.png");
        _game->assetManager.LoadTexture("run_right", "res/graphics/run_right.png");

        // Player ...
        _player = Player{_game};
        _player.setPosition({SCREEN_WIDTH / 2 - _player.getGlobalBounds().width / 2,
                             SCREEN_HEIGHT / 2 - _player.getGlobalBounds().height / 2});
    }

    void DefaultScreen::Update(float dt)
    {
        _player.update(dt);
    }

    void DefaultScreen::Draw(float dt)
    {
        _game->window.clear(sf::Color{92, 219, 88, 255});
        _game->window.draw(_player);
        _game->window.display();
    }
} // namespace CMB