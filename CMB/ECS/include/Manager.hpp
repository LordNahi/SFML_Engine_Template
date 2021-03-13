#pragma once

#include <algorithm>

#include "Entity.hpp"
#include "Component.hpp"

namespace ECS
{
    class Manager
    {
        public:
            void update(const float dt);
            void draw(const float dt);
            void refresh();
            Entity& addEntity();

        private:
            std::vector<std::shared_ptr<Entity>> m_entities;
    };
}