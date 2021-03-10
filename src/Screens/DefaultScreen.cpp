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
        std::cout << "Init Default Screen ..." << std::endl;

        // Load image assets ...
        // TODO: This will eventually move to a loading screen ...
        // TODO: Consider making asset packages that can be loaded in groups
        // when needed, packs will be set up in a loading screen then loaded
        // in and out on different screens ...

        // Player Body ...
        _game->assetManager.LoadTexture("body_lowered", "res/graphics/player/body_lowered.png");
        _game->assetManager.LoadTexture("body_raised", "res/graphics/player/body_raised.png");

        // Player Legs ...
        _game->assetManager.LoadTexture("legs_walk_horizontal", "res/graphics/player/legs_walk_horizontal.png");
        _game->assetManager.LoadTexture("legs_walk_vertical", "res/graphics/player/legs_walk_vertical.png");

        // Player ...
        _player = Player{_game};
    }

    void DefaultScreen::Update(float dt)
    {
        _player.update(dt);
    }

    void DefaultScreen::Draw(float dt)
    {
        _game->window.clear(sf::Color{92, 219, 88, 255});
        _player.draw(dt);
        _game->window.display();
    }
} // namespace CMB