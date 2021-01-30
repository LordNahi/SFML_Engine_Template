#include "Managers/ScreenManager.hpp"

namespace CMB
{
    /**
     * Add a new state to your game.
     * 
     * This will tell the ScreenManager to add a new state or "screen"
     * to the world.
     * 
     * @param newScreen screen to be used in game
     * @param isReplacing if true, the game will switch to this screen immediately
     */
    void ScreenManager::AddScreen(ScreenRef newScreen, bool isReplacing)
    {
        _isAdding = true;
        _isReplacing = isReplacing;
        _newScreen = std::move(newScreen);
    }

    void ScreenManager::RemoveScreen()
    {
        _isRemoving = true;
    }

    void ScreenManager::ProcessScreenChanges()
    {
        if (_isRemoving && !_states.empty())
        {
            _states.pop();

            if (!_states.empty())
            {
                _states.top()->Resume();
            }

            _isRemoving = false;
        }

        if (_isAdding)
        {
            if (!_states.empty())
            {
                if (_isReplacing)
                {
                    _states.pop();
                }
                else
                {
                    _states.top()->Pause();
                }
            }

            _states.push(std::move(_newScreen));
            _states.top()->Init();
            _isAdding = false;
        }
    }

    ScreenRef &ScreenManager::GetActiveState()
    {
        return _states.top();
    }
} // namespace CMB