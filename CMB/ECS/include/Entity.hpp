#pragma once

#include <vector>
#include <memory>
#include <bitset>
#include <array>

namespace ECS
{
    // Forward decl ...
    class Component;

    using ComponentID = std::size_t;

    inline ComponentID getComponentID()
    {
        static ComponentID lastId = 0;
        return lastId++;
    }

    template <typename T> inline ComponentID getComponentTypeID() noexcept
    {
        static ComponentID typeID = getComponentID();
        return typeID;
    }

    constexpr std::size_t maxComponents = 32;

    using ComponentBitSet = std::bitset<maxComponents>;
    using ComponentArray = std::array<Component*, maxComponents>;

    class Entity
    {
        public:
            void update(const float dt);
            void draw(const float dt);
            bool getIsActive() const { return isActive; }
            void destroy() { isActive = false; }
            template <typename T> bool hasComponent() const;
            template <typename T, typename... TArgs> T& addComponent(TArgs&&... mArgs);
            template <typename T> T& getComponent() const;

        private:
            bool isActive = true;
            std::vector<std::shared_ptr<Component>> components;

            ComponentArray componentArray;
            ComponentBitSet componentBitSet;
    };
}