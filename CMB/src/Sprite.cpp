#include <cmath>
#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>

#include "Sprite.hpp"

namespace CMB
{
    // Public ...

    void Sprite::update(float dt)
    {
        // Animation ...

        if (m_activeAnim.first != "" && !m_activeAnim.second.empty())
        {
            const auto frames = m_activeAnim.second;

            if (m_animClock.getElapsedTime().asMilliseconds() > 1000 / m_animSpeed)
            {
                std::cout << "Anim tick" << std::endl;
                std::cout << "Anim Index: " << m_animFrameIndex << std::endl;

                m_animFrameIndex = (m_animFrameIndex + 1) % frames.size();
                m_frameIndex = m_animFrameIndex;

                updateFrame();

                m_animClock.restart();

                if (m_animFrameIndex == frames.size() - 1 && !m_animRepeat)
                {
                    animationStop();
                }
            }
        }
    }

    void Sprite::animationAdd(const std::string key, const std::vector<int> frames)
    {
        m_anims.insert_or_assign(key, frames);
    }

    void Sprite::animationRemove(const std::string key)
    {
        m_anims.erase(key);
    }

    void Sprite::animationPlay(const std::string key, const int speed, const bool repeat = true)
    {
        const auto result = m_anims.find(key);

        if (result != m_anims.end())
        {
            m_animSpeed = speed;
            m_animRepeat = repeat;
            m_activeAnim = {result->first, result->second};
        }
    }

    void Sprite::animationStop()
    {
        m_activeAnim = {"", {}};
    }

    bool Sprite::setSpritesheet(const int &frameWidth, const int &frameHeight, const int &frameCount)
    {
        if (!getTexture())
        {
            return false;
        }

        hasSetSpritesheet = true;

        m_frameIndex = 0;
        m_frame.width = frameWidth;
        m_frame.height = frameHeight;
        m_frameMax = frameCount;

        setTextureRect(m_frame);

        return true;
    }

    // Private ...

    void Sprite::updateFrame()
    {
        // Is this too spenny ...
        const int texWidth = getTexture()->getSize().x;  // Tex width
        const int texHeight = getTexture()->getSize().y; // Tex height

        int col = texWidth / m_frame.width;
        int row = texHeight / m_frame.height;

        int col_i = m_frameIndex % col;
        int row_i = std::floor((float)m_frameIndex / (float)m_frameMax * row);

        m_frame.left = m_frame.width * col_i;
        m_frame.top = m_frame.height * row_i;

        setTextureRect(m_frame);
    }
} // namespace CMB