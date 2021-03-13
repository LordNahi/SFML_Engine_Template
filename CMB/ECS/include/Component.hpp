#pragma once

#include "Entity.hpp"

namespace ECS
{
    class Component
    {
        public:
            Entity* entity;

            virtual void init() {}
            virtual void update(const float dt) {}
            virtual void draw(const float dt) {}

            virtual ~Component() {}
    };
}