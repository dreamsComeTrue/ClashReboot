// Copyright 2017 Dominik 'dreamsComeTrue' Jasiński. All Rights Reserved.

#ifndef __STATE_MANAGER_H__
#define __STATE_MANAGER_H__

#include "Lifecycle.h"

namespace aga
{
    class Screen;

    class StateManager : public Lifecycle
    {
    public:
        StateManager (Screen* screen);
        virtual ~StateManager ();
        bool Initialize ();
        bool Destroy ();

        bool Update ();
        void Render ();

    private:
        Screen* m_Screen;
    };
}

#endif //   __STATE_MANAGER_H__
