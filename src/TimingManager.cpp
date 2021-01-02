#include "TimingManager.hpp"

namespace GameTools
{
    void TimingManager::CallDelay(std::function<void()> func, unsigned int interval, bool &isRepeatingParam)
    {
        const auto callback = [func, interval](bool &isRepeating) {
            if (isRepeating)
            {
                while (isRepeating)
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
        };

        std::thread(callback, std::ref(isRepeatingParam)).detach();
    }
} // namespace GameTools