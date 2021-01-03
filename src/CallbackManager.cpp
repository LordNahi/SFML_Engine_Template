#include "CallbackManager.hpp"

namespace GameTools
{
    void CallbackManager::Register(std::string name, std::function<void()> func, unsigned int interval, bool isRepeating)
    {
        // Call once, and if `isRepeating` is true, repeat...
        const auto delayedCallback = [isRepeating, func, interval]() {
            do
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(interval));
                func();
            } while (isRepeating);
        };

        /**
         * NOTE: Initially was passing `std::ref(isRepeatingParam)` as the only way we could
         * get threads to close was having the while loop bool value managed from outside
         * the callback manager, now the functions will simply run indefinitely until cancel
         * is called ...
         */

        std::thread callbackThread;
        callbackThread = std::thread(delayedCallback);

        /**
         * NOTE: Supposedly the most elegant way for cancelling threads is to call the 
         * native thread terminator, and to do so, you need to store a reference to the
         * native thread handle, we store it in a map to be used for termination ...
         * 
         * Based on:
         * https://www.bo-yang.net/2017/11/19/cpp-kill-detached-thread
         */

        callbackMap[name] = callbackThread.native_handle();
        callbackThread.detach();
    }

    void CallbackManager::Cancel(std::string name)
    {
        const auto item = callbackMap.find(name);

        if (item != callbackMap.end())
        {
            // Map is a collection of pairs, we found a pair that
            // contains your callback, we access it with `second` ...
            pthread_cancel(item->second);
            callbackMap.erase(item);
        }
    }
} // namespace GameTools