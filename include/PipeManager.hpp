#pragma once

#include <vector>

#include "Pipe.hpp"

struct GameData;

namespace GameTools
{
    class PipeManager
    {
    public:
        PipeManager() = default;
        PipeManager(std::shared_ptr<GameData> data);

        void Start();
        void Stop();
        void SpawnPipe();
        void Update(float dt);
        void Draw(float dt);
        void Reset();
        bool IsColliding(sf::Sprite sprite);
        bool GetIsRunning();

    private:
        sf::Clock _clock;
        std::shared_ptr<GameData> _data;
        std::vector<Pipe> pipes;

        int pipePoolSize = 5;
        bool isRunning = false;
    };
} // namespace GameTools