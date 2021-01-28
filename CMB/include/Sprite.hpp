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
        bool addAnimation(const std::string key, std::vector<int> frames);
        bool removeAnimation(const std::string key);

        // Test ...
        void frameForward();
        void frameBack();

    private:
        bool hasSetSpritesheet = false;
        int m_frameMax;
        int m_frameIndex;
        int m_frameWidth;
        int m_frameHeight;

        std::unordered_map<std::string, std::vector<int>> m_frames;
        sf::IntRect m_frame;

        // void frameForward();
        // void frameBack();
        void updateFrame();
    };
} // namespace CMB