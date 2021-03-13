#include "Manager.hpp"

namespace ECS
{
    void Manager::update(const float dt)
    {
        for (auto& e : m_entities) e->update(dt);
    }

    void Manager::draw(const float dt)
    {
        for (auto& e : m_entities) e->draw(dt);
    }

    void Manager::refresh()
    {
        m_entities.erase(
        std::remove_if
        (
            std::begin(m_entities),
            std::end(m_entities),
            [](const std::shared_ptr<Entity> &mEntity)
            {
                return !mEntity->getIsActive();
            }
        ),
        std::end(m_entities));
    }

    Entity& Manager::addEntity()
    {
        auto e = std::make_shared<Entity>();
        m_entities.emplace_back(e);

        return *e;
    }
}