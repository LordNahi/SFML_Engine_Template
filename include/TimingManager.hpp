#include <iostream>
#include <chrono>
#include <thread>
#include <functional>

namespace GameTools
{
    class TimingManager
    {
    public:
        void CallDelay(std::function<void()> func, unsigned int interval, bool &isRepeating);
    };
} // namespace GameTools