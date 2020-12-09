#pragma once

#include <SFML/Graphics.hpp>

namespace GameTools
{
    class InputManager
    {
    public:
        InputManager() {}
        ~InputManager() {}
        bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
        sf::Vector2i GetMousePosition(sf::RenderWindow &window);
    };
} // namespace GameTools