#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
#include <string>
#include <future>
#include <map>

namespace GameTools
{
    class CallbackManager
    {
    public:
        void Register(std::string name, std::function<void()> func, unsigned int interval, bool isRepeating);
        void Cancel(std::string name);

    private:
        std::map<std::string, std::promise<void>> callbackMap;
    };
} // namespace GameTools