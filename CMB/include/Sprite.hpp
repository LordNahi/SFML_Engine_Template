#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <unordered_map>

namespace CMB
{
    class Sprite : public sf::Sprite
    {
    public:
        using sf::Sprite::Sprite;

        /**
         * Tell Sprite it is being used with a spritesheet.
         * 
         * Calling this will splice the images into specified
         * frame sizes and enable animation functionality.
         */
        bool setSpritesheet(const int &frameWidth, const int &frameHeight, const int &frameCount);
        void animationAdd(const std::string key, const std::vector<int> frames);
        bool animationRemove(const std::string key);
        bool animationPlay(const std::string key, const bool repeat);
        bool animationStop(const std::string key);

    private:
        bool hasSetSpritesheet = false;
        int m_frameMax;
        int m_frameIndex;
        int m_frameWidth;
        int m_frameHeight;

        std::unordered_map<std::string, std::vector<int>> m_anims;
        sf::IntRect m_frame;

        void updateFrame();
    };
} // namespace CMB