// Copyright 2017 Dominik 'dreamsComeTrue' Jasiński. All Rights Reserved.

#include "MainLoop.h"
#include "Common.h"
#include "Screen.h"
#include "StateManager.h"

namespace aga
{
    //--------------------------------------------------------------------------------------------------

    MainLoop::MainLoop (Screen* screen)
        : m_Screen (screen)
    {
    }

    //--------------------------------------------------------------------------------------------------

    MainLoop::~MainLoop ()
    {
        if (!IsDestroyed ())
        {
            Destroy ();
        }

        Lifecycle::Destroy ();
    }

    //--------------------------------------------------------------------------------------------------

    bool MainLoop::Initialize ()
    {
        m_StateManager = new StateManager (m_Screen);
        m_StateManager->Initialize ();

        m_Screen->RenderFunction = [&]() {
            m_StateManager->Render ();
        };

        Lifecycle::Initialize ();
    }

    //--------------------------------------------------------------------------------------------------

    bool MainLoop::Destroy ()
    {
        SAFE_DELETE (m_StateManager);
        Lifecycle::Destroy ();
    }

    //--------------------------------------------------------------------------------------------------

    void MainLoop::Start ()
    {
        while (true)
        {
            if (!m_StateManager->Update ())
            {
                break;
            }
        }
    }

    //--------------------------------------------------------------------------------------------------
}
