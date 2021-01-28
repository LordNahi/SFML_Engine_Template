#pragma once

#include <memory>
#include <stack>

#include "Screen.hpp"

namespace CMB
{
    typedef std::unique_ptr<Screen> StateRef;

    class ScreenManager
    {
    public:
        void AddState(StateRef newState, bool isReplacing = true);
        void RemoveState();
        void ProcessStateChanges();

        StateRef &GetActiveState();

    private:
        std::stack<StateRef> _states;
        StateRef _newState;

        bool _isRemoving;
        bool _isAdding;
        bool _isReplacing;
    };
} // namespace CMB