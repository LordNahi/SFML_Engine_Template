#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <chrono>
#include <thread>

#include "Util.hpp"
#include "GameConfig.hpp"
#include "Game.hpp"
#include "PipeManager.hpp"
#include "Pipe.hpp"

namespace GameTools
{
    PipeManager::PipeManager(GameDataRef data) : _data(data)
    {
        for (int i = 0; i < pipePoolSize; i++)
        {
            pipes.push_back(Pipe{_data});
        }
    }

    void PipeManager::Start()
    {
        isRunning = true;

        // Pipe Spawn Loop ...
        int spawnFrequency = 2000;
        _data->timingManager.CallDelay([this]() { SpawnPipe(); }, spawnFrequency, true);
    }

    void PipeManager::Stop()
    {
        isRunning = false;
    }

    void PipeManager::Update(float dt)
    {
        if (isRunning)
        {
            // Update Pipes ...
            for (auto &pipe : pipes)
            {
                if (pipe.GetIsActive())
                {
                    pipe.Update(dt);
                }
            }
        }
    }

    void PipeManager::Draw(float dt)
    {
        // Draw Pipes ...
        for (auto &pipe : pipes)
        {
            if (pipe.GetIsActive())
            {
                pipe.Draw();
            }
        }
    }

    void PipeManager::SpawnPipe()
    {
        for (auto &pipe : pipes)
        {
            if (!pipe.GetIsActive())
            {
                pipe.Spawn();
                return;
            }
        }

        std::cout << "Failed to spawn pipe ..." << std::endl;
    }

    void PipeManager::Reset()
    {
        isRunning = false;

        for (auto &pipe : pipes)
        {
            pipe.Kill();
        }
    }

    bool PipeManager::GetIsRunning()
    {
        return isRunning;
    }

    bool PipeManager::IsColliding(sf::Sprite sprite)
    {
        for (auto &pipe : pipes)
        {
            if (pipe.IsColliding(sprite))
            {
                return true;
            }
        }

        return false;
    }
} // namespace GameTools