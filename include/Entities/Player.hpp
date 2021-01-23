#include <SFML/Graphics.hpp>

#include "Game.hpp"

namespace GameTools
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
} // namespace GameTools