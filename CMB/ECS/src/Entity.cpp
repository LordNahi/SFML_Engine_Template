#include "Entity.hpp"
#include "Component.hpp"

namespace ECS
{
    void Entity::update(const float dt)
    {
        for (auto& c : components) c->update(dt);
    }

    void Entity::draw(const float dt)
    {
        for (auto& c : components) c->draw(dt);
    }

    template <typename T> bool Entity::hasComponent() const
    {
        return componentBitSet[getComponentID<T>()];
    }

    template <typename T, typename... TArgs> T& Entity::addComponent(TArgs&&... mArgs)
    {
        auto c = std::make_shared<T>(std::forward<TArgs>(mArgs)...);
        c->entity = this;
        components.emplace_back(c);

        componentArray[getComponentTypeID<T>()] = c;
        componentBitSet[getComponentTypeID<T>()] = true; // I think a bool is being used in place of a bit? (as in, 1 or 0) ...

        c->init();

        return *c;
    }

    template <typename T> T& Entity::getComponent() const
    {
        auto ptr(componentArray[getComponentTypeID<T>()]);
        return *static_cast<T*>(ptr);
    }
}
