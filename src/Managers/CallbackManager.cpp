#include "CallbackManager.hpp"

namespace GameTools
{
    void CallbackManager::Register(std::string name, std::function<void()> func, unsigned int interval, bool isRepeating)
    {
        // Call once, and if `isRepeating` is true, repeat...
        const auto delayedCallback = [isRepeating, func, interval](std::future<void> signalFuture) {
            while (signalFuture.wait_for(std::chrono::milliseconds(interval)) == std::future_status::timeout)
            {
                func();
            }
        };

        /**
         * NOTE: Initially was passing `std::ref(isRepeatingParam)` as the only way we could
         * get threads to close was having the while loop bool value managed from outside
         * the callback manager, now the functions will simply run indefinitely until cancel
         * is called ...
         */

        std::thread callbackThread;
        std::promise<void> signalExit;
        std::future<void> signalFuture = signalExit.get_future();

        callbackThread = std::thread(delayedCallback, std::move(signalFuture));
        callbackThread.detach();

        callbackMap[name] = std::move(signalExit);
    }

    void CallbackManager::Cancel(std::string name)
    {
        const auto item = callbackMap.find(name);

        if (item != callbackMap.end())
        {
            // Map is a collection of pairs, we found a pair that
            // contains your callback, we access it with `second` ...
            item->second.set_value();
            callbackMap.erase(item);
        }
    }
} // namespace GameTools