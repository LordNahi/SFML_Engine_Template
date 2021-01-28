#include "Managers/ScreenManager.hpp"

namespace CMB
{
    /**
     * Add a new state to your game.
     * 
     * This will tell the ScreenManager to add a new state or "screen"
     * to the world.
     * 
     * @param newState state or "screen" object to be used in game
     * @param isReplacing if true, the game will switch to this screen immediately
     */
    void ScreenManager::AddState(StateRef newState, bool isReplacing)
    {
        this->_isAdding = true;
        this->_isReplacing = isReplacing;
        this->_newState = std::move(newState);
    }

    void ScreenManager::RemoveState()
    {
        this->_isRemoving = true;
    }

    void ScreenManager::ProcessStateChanges()
    {
        if (this->_isRemoving && !this->_states.empty())
        {
            this->_states.pop();

            if (!this->_states.empty())
            {
                this->_states.top()->Resume();
            }

            this->_isRemoving = false;
        }

        if (this->_isAdding)
        {
            if (!this->_states.empty())
            {
                if (this->_isReplacing)
                {
                    this->_states.pop();
                }
                else
                {
                    this->_states.top()->Pause();
                }
            }

            this->_states.push(std::move(this->_newState));
            this->_states.top()->Init();
            this->_isAdding = false;
        }
    }

    StateRef &ScreenManager::GetActiveState()
    {
        return this->_states.top();
    }
} // namespace CMB