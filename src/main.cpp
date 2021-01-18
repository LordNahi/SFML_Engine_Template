#include <iostream>

#include "GameConfig.hpp"
#include "Game.hpp"

int main()
{
    auto game = GameTools::Game(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);

    game.Run();

    return EXIT_SUCCESS;
}