// Copyright 2017 Dominik 'dreamsComeTrue' Jasiński. All Rights Reserved.

#ifndef __STATE_H__
#define __STATE_H__

#include "Lifecycle.h"

namespace aga
{
    class State : public Lifecycle
    {
    public:
        State (const char* name)
            : m_Name (name)
        {
        }

        virtual ~State ();
        bool Initialize ();
        bool Destroy ();

        virtual void Update () = 0;
        virtual void Render () = 0;

    private:
        char* m_Name;
    };
}

#endif //   __STATE_H__
