#include <SFML/Graphics.hpp>

#include "Game.hpp"

namespace CMB
{
    class Player : public sf::Sprite
    {
    public:
        Player() = default;
        Player(GameDataRef data);
        void Init();
        void Update(float dt);

        GameDataRef _data;
    };
} // namespace CMB