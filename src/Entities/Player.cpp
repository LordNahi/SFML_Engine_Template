#include <cmath>
#include <algorithm>

#include "Entities/Player.hpp"
#include "GameConfig.hpp"
#include "Util.hpp"

namespace CMB
{
    Player::Player(GameDataRef game) : m_game(game)
    {
        // Setup body ...
        m_body.setTexture(m_game->assetManager.GetTexture("body_lowered"));
        m_body.setScale({GAME_SCALE, GAME_SCALE});
        m_body.setSpritesheet(32, 32, 8);
        m_body.setOrigin(m_body.getLocalBounds().width / 2.0f, 0);

        // Setup legs ...
        m_legs.setTexture(m_game->assetManager.GetTexture("legs_walk_vertical"));
        m_legs.setScale({4, 4});
        m_legs.setSpritesheet(32, 32, 4);
        m_legs.animationAdd("walk", {0, 1, 2, 3});
        m_legs.setOrigin(m_legs.getLocalBounds().width / 2.0f, 0);

        // Set initial position ...
        m_body.setPosition({SCREEN_WIDTH / 2 - m_body.getGlobalBounds().width / 2,
                            SCREEN_HEIGHT / 2 - m_body.getGlobalBounds().height / 2});
        m_legs.setPosition(m_body.getPosition());
    }

    void Player::update(float dt)
    {
        m_body.update(dt);
        m_legs.update(dt);

        setBodyAngle();

        // Reset movement vec ...
        m_movementVec = {0, 0};

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            // m_body.setTexture(m_game->assetManager.GetTexture("body_walk_left"));
            m_legs.setTexture(m_game->assetManager.GetTexture("legs_walk_horizontal"));
            m_legs.setScale({GAME_SCALE, GAME_SCALE});

            m_movementVec.x = -1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            // m_body.setTexture(m_game->assetManager.GetTexture("body_walk_right"));
            m_legs.setTexture(m_game->assetManager.GetTexture("legs_walk_horizontal"));
            m_legs.setScale({-GAME_SCALE, GAME_SCALE});

            m_movementVec.x = 1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            // m_body.setTexture(m_game->assetManager.GetTexture("body_walk_up"));
            m_legs.setTexture(m_game->assetManager.GetTexture("legs_walk_vertical"));

            m_movementVec.y = -1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            // m_body.setTexture(m_game->assetManager.GetTexture("body_walk_down"));
            m_legs.setTexture(m_game->assetManager.GetTexture("legs_walk_vertical"));

            m_movementVec.y = 1;
        }

        if (m_movementVec.x == 0 && m_movementVec.y == 0)
        {
            m_legs.animationStop();
        }

        updatePosition(dt);
    }

    void Player::draw(float dt)
    {
        m_game->window.draw(m_legs);
        m_game->window.draw(m_body);
    }

    void Player::updatePosition(float dt)
    {
        // TODO: Fix classic diagonal speed issue ...

        const int speed = 15 * dt;
        auto position = m_body.getPosition();

        if (m_movementVec.x != 0 || m_movementVec.y != 0)
        {
            // Moving ...
            m_legs.animationPlay("walk", 8, true);

            const int speed = 15;
            const float xx = speed * dt * m_movementVec.x;
            const float yy = speed * dt * m_movementVec.y;

            position.x += xx;
            position.y += yy;

            // TODO: Consider createing a group class where you
            // can move multiple sprites as a unit ...

            m_body.setPosition(position);
            m_legs.setPosition(m_body.getPosition());
        }
    }

    void Player::setBodyAngle()
    {
        // Ideally player's exact center, this will do for now ...
        const sf::Vector2f legPos = m_legs.getPosition();

        // Get Mouse position in window ...
        const sf::Vector2i mousePos = sf::Mouse::getPosition(m_game->window);

        // Convert to world position ...
        const sf::Vector2f worldMousePos = m_game->window.mapPixelToCoords(mousePos);

        const auto angleVec = sf::Vector2f{
            worldMousePos.x,
            worldMousePos.y};

        const float angle = Util::Math::Trig::getAngleBetween(legPos, angleVec);

        const int index = static_cast<int>((angle / 360.0f) * m_body.getNumFrames());

        m_body.setFrameIndex(index);
    }
} // namespace CMB