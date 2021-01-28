#include <cmath>
#include <iostream>

#include "Sprite.hpp"

namespace CMB
{
    // Public ...

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

    void Sprite::frameForward()
    {
        if (!hasSetSpritesheet)
        {
            return;
        }

        m_frameIndex = (m_frameIndex + 1) % m_frameMax;

        updateFrame();
    }

    void Sprite::frameBack()
    {
        if (!hasSetSpritesheet)
        {
            return;
        }

        if (m_frameIndex - 1 < 0)
        {
            m_frameIndex = m_frameMax - 1;
        }
        else
        {
            m_frameIndex--;
        }

        updateFrame();
    }

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