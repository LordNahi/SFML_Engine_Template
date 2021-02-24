#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <unordered_map>

namespace CMB
{
    typedef std::pair<std::string, std::vector<int>> Anim;

    class Sprite : public sf::Sprite
    {
    public:
        virtual void update(float dt);
        void animationAdd(const std::string key, const std::vector<int> frames);
        void animationRemove(const std::string key);
        void animationPlay(const std::string key, const int speed, const bool repeat);
        void animationStop();
        bool setSpritesheet(const int &frameWidth, const int &frameHeight, const int &frameCount);
        void setFrameIndex(const int index);
        Anim getActiveAnim();
        int getNumFrames();

    private:
        bool hasSetSpritesheet = false;
        int m_frameMax = 0;
        int m_frameIndex = 0;
        int m_frameWidth = 0;
        int m_frameHeight = 0;

        sf::Clock m_animClock;
        int m_animSpeed = 0;
        int m_animFrameIndex = 0;
        bool m_animRepeat = true;
        Anim m_activeAnim = {"", {}};
        std::unordered_map<std::string, std::vector<int>> m_anims;
        sf::IntRect m_frame;

        void updateFrame();
    };
} // namespace CMB