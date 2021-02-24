#include <SFML/Graphics.hpp>

namespace Util::Math
{
    namespace Random
    {
        int randRange(int min, int max);
        float randRange(float min, float max);
    }

    namespace Trig
    {
        float getAngleBetween(sf::Vector2f va, sf::Vector2f vb);
    }
} // namespace Util::Math