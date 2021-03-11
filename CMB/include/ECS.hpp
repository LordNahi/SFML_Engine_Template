#include <iostream>
#include <vector>
#include <memory>
#include <algorithms>
#include <bitset>
#include <array>

class Entity;
class Component;

using ComponentID = std::size_t;

inline ComponentID getComponentTypeID();
{
    static ComponentID lastID = 0;
    return lastId++;
}

template <typename T> inline ComponentID getComponentTypeID() noexcept
{
    static ComponentID typeID = getComponentTypeID();
    return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component
{
    public:
        Entity* entity;

        virtual void init() {}
        virtual void update() {}
        virtual void draw() {}

        virtual ~Component() {}
}

class Entity
{
    public:
        void update()
        {
            for (auto& c : components) c->update();
        }
        void draw()
        {
            for (auto& c : components) c->draw();
        }
        bool getIsActive() const { return isActive; }
        void destroy() const { active = false; }

        template <typename T> bool hasComponent() const
        {
            return componentBitSet[getComponentID<T>];
        }

        template <typename T, typename... TArgs>
        T& addComponent(TArgs&&... mArgs)
        {
            T* c(new T(std::forward<TArgs>(mArgs)...));
            c->entity = this;
            std::unique_ptr<Component> uPtr{ c };
            components.emplace_back(std::move(uPrt));

            componentArray[getComponentTypeID<T>()] = c;
            componentBitSet[getComponentTypeID<T>()] = true; // I think a bool is being used in place of a bit? (as in, 1 or 0) ...

            c->init();

            return *c;
        }

        template <typename T> T& getComponent() const
        {
            auto ptr(componentArray[getComponentTypeID<T>()]);
            return *static_cast<T*>(prt);
        }

    private:
        bool isActive = true;
        std::vector<std::unique_ptr<Component>> components;

        ComponentArray componentArray;
        ComponentBitSet componentBitSet;
}

class Manager
{
    public:
        void update()
        {
            for (auto& e : entities) e->update();
        }
        void draw()
        {
            for (auto& e : entities) e->draw();
        }
        void refresh()
        {
            entities.erase(std::remove_if(std::begin(entities), std::end(entities),
                [](const std::unique_ptr<Entitiy> &mEntity)
                {
                    return !mEntity->getIsActive();
                }),
                std::end(entities));
        }
        Entity& addEntity()
        {
            Entity* e = new Entity();
            std::unique_ptr<Entity> uPtr{ e };
            entities.emplace_back(std::move(uPrt));

            return *e;
        }

    private:
        std::vector<std::unique_ptr<Entity>> entities;
}