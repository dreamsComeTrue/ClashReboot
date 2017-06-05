// Copyright 2017 Dominik 'dreamsComeTrue' Jasiński. All Rights Reserved.

#include "StateManager.h"
#include "Common.h"
#include "Point.h"
#include "Resources.h"
#include "Screen.h"

namespace aga
{
    //--------------------------------------------------------------------------------------------------

    StateManager::StateManager (Screen* screen)
        : m_Screen (screen)
    {
    }

    //--------------------------------------------------------------------------------------------------

    StateManager::~StateManager ()
    {
        if (!IsDestroyed ())
        {
            Destroy ();
        }

        Lifecycle::Destroy ();
    }

    //--------------------------------------------------------------------------------------------------

    ALLEGRO_BITMAP* bitmap;

    bool StateManager::Initialize ()
    {
        bitmap = al_load_bitmap (GetResourcePath (ResourceID::MAIN_MENU).c_str ());

        Lifecycle::Initialize ();
    }

    //--------------------------------------------------------------------------------------------------

    bool StateManager::Destroy ()
    {
        al_destroy_bitmap (bitmap);

        Lifecycle::Destroy ();
    }

    //--------------------------------------------------------------------------------------------------

    bool StateManager::Update ()
    {
        if (!m_Screen->Update ())
        {
            return false;
        }

        return true;
    }

    //--------------------------------------------------------------------------------------------------

    void StateManager::Render ()
    {
        Point size = m_Screen->GetScreenSize ();
        al_draw_scaled_bitmap (bitmap, 0, 0, al_get_bitmap_width (bitmap),
            al_get_bitmap_height (bitmap), 0, 0, size.Width, size.Height, 0);
    }

    //--------------------------------------------------------------------------------------------------
}
