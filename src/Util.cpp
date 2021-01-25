#include <random>

namespace Util::Math
{
    namespace Random
    {
        int randRange(int min, int max)
        {
            // Will this cause a memory leak if I call this func a million times ...
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distrib(min, max);

            return distrib(gen);
        };

        float randRange(float min, float max)
        {
            // Will this cause a memory leak if I call this func a million times ...
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<> distrib(min, max);

            return distrib(gen);
        }
    } // namespace Random
} // namespace Util::Math
