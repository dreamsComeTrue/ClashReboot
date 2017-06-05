// Copyright 2017 Dominik 'dreamsComeTrue' Jasiński. All Rights Reserved.

#ifndef __MAIN_LOOP_H__
#define __MAIN_LOOP_H__

#include "Lifecycle.h"

namespace aga
{
    class StateManager;
    class Screen;

    class MainLoop : public Lifecycle
    {
    public:
        MainLoop (Screen* screen);
        virtual ~MainLoop ();
        bool Initialize ();
        bool Destroy ();

        void Start ();

    private:
        Screen* m_Screen;
        StateManager* m_StateManager;
    };
}

#endif //   __MAIN_LOOP_H__
