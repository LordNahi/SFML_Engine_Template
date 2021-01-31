#pragma once

namespace CMB
{
    class Screen
    {
    public:
        virtual void Init() = 0;

        virtual void Update(float dt) = 0;
        virtual void Draw(float dt) = 0;

        virtual void Pause(){};
        virtual void Resume(){};
    };
} // namespace CMB