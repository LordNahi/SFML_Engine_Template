#include <SFML/Graphics.hpp>

#include "Game.hpp"

namespace GameTools
{
    class Pepe : public sf::Sprite
    {
    public:
        Pepe() = default;
        Pepe(GameDataRef data);
        void Init();
        void Update(float dt);
        void Flap();
        void Reset();

    private:
        bool isActive = false;
        float gravity = 0.5f;
        float jumpGain = 10.0f;
        float fallSpeed = 0.0f;
        float fallSpeedMax = 10.0f;
        float rotationMin = -25.0f;
        float rotationMax = 25.0f;

        GameDataRef _data;
    };
} // namespace GameTools