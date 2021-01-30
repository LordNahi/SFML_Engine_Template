#pragma once

#include <memory>
#include <stack>

#include "Screen.hpp"

namespace CMB
{
    typedef std::unique_ptr<Screen> ScreenRef;

    class ScreenManager
    {
    public:
        void AddScreen(ScreenRef newScreen, bool isReplacing = true);
        void RemoveScreen();
        void ProcessScreenChanges();

        ScreenRef &GetActiveState();

    private:
        std::stack<ScreenRef> _states;
        ScreenRef _newScreen;

        bool _isRemoving;
        bool _isAdding;
        bool _isReplacing;
    };
} // namespace CMB