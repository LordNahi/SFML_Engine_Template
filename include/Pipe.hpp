#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

struct GameData;

namespace GameTools
{
    class Pipe
    {
    public:
        Pipe(std::shared_ptr<GameData> data);

        void Spawn();
        void Kill();
        void Destroy();
        void Update(float dt);
        void Draw();
        bool GetIsActive() const { return isActive; };

    private:
        std::shared_ptr<GameData> _data;

        bool isActive = false;
        float speed = 5.0f;
        int pipeGap = 50;

        sf::Vector2f position;
        sf::Sprite pipeTop;
        sf::Sprite pipeBottom;
    };
} // namespace GameTools