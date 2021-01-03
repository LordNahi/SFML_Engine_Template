#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
#include <string>
#include <map>

namespace GameTools
{
    class CallbackManager
    {
    public:
        void Register(std::string name, std::function<void()> func, unsigned int interval, bool isRepeating);
        void Cancel(std::string name);

    private:
        std::unordered_map<std::string, std::thread::native_handle_type> callbackMap;
    };
} // namespace GameTools