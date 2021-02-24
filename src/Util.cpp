#include <iostream>
#include <random>
#include <cmath>
#include <SFML/Graphics.hpp>

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

    namespace Trig
    {
        float getAngleBetween(sf::Vector2f p1, sf::Vector2f p2)
        {
            // NOTE: Remember that most math has the Y axis as positive above the X.
            // However, for screens we have Y as positive below. For this reason,
            // the Y values are inverted to get the expected results.
            float deltaY = (p1.y - p2.y);
            float deltaX = (p2.x - p1.x);
            float result = std::atan2(deltaY, deltaX) * 57.2958;

            return (result < 0) ? (360 + result) : result;
        }
    }
} // namespace Util::Math
