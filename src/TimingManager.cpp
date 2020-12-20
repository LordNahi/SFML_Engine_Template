#include "TimingManager.hpp"

namespace GameTools
{
    void TimingManager::CallDelay(std::function<void()> func, unsigned int interval, bool repeat)
    {
        std::thread([func, interval, repeat]() {
            if (repeat)
            {
                while (true)
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(interval));
                    func();
                }
            }
            else
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(interval));
                func();
            }
        }).detach();
    }
} // namespace GameTools