// Copyright 2017 Dominik 'dreamsComeTrue' Jasiński. All Rights Reserved.

#include "Screen.h"
#include "Common.h"

namespace aga
{
    //--------------------------------------------------------------------------------------------------

    const float TARGET_FPS = 60;
    const char* GAME_TITLE = "Clash Reboot";

    //--------------------------------------------------------------------------------------------------

    Screen::Screen (unsigned width, unsigned height)
        : m_Width (width)
        , m_Height (height)
        , m_RealWidth (width)
        , m_RealHeight (height)
        , m_Redraw (false)
    {
    }

    //--------------------------------------------------------------------------------------------------

    Screen::~Screen ()
    {
        if (!IsDestroyed ())
        {
            Destroy ();
        }

        Lifecycle::Destroy ();
    }

    //--------------------------------------------------------------------------------------------------

    bool Screen::Initialize ()
    {
        if (!al_init ())
        {
            fprintf (stderr, "Failed to initialize allegro!\n");
            return false;
        }

        al_set_new_display_flags (ALLEGRO_RESIZABLE);
        m_Display = al_create_display (m_Width, m_Height);

        if (!m_Display)
        {
            fprintf (stderr, "Failed to create display!\n");
            return false;
        }

        if (!al_init_image_addon ())
        {
            al_show_native_message_box (m_Display, "Error", "Error",
                "Failed to initialize al_init_image_addon!",
                nullptr, ALLEGRO_MESSAGEBOX_ERROR);
            return false;
        }

        m_DisplayTimer = al_create_timer (1.0 / TARGET_FPS);

        if (!m_DisplayTimer)
        {
            fprintf (stderr, "Failed to create timer!\n");
            return false;
        }

        m_EventQueue = al_create_event_queue ();

        if (!m_EventQueue)
        {
            fprintf (stderr, "Failed to create event_queue!\n");
            al_destroy_display (m_Display);
            return false;
        }

        al_register_event_source (m_EventQueue,
            al_get_display_event_source (m_Display));
        al_register_event_source (m_EventQueue, al_get_timer_event_source (m_DisplayTimer));

        al_set_window_title (m_Display, GAME_TITLE);
        al_set_window_position (m_Display, 0, 0);

        al_start_timer (m_DisplayTimer);

        Lifecycle::Initialize ();

        return true;
    }

    //--------------------------------------------------------------------------------------------------

    bool Screen::Destroy ()
    {
        if (m_DisplayTimer != nullptr)
        {
            al_destroy_timer (m_DisplayTimer);
            m_DisplayTimer = nullptr;
        }

        if (m_EventQueue != nullptr)
        {
            al_destroy_event_queue (m_EventQueue);
            m_EventQueue = nullptr;
        }

        if (m_Display != nullptr)
        {
            al_destroy_display (m_Display);
            m_Display = nullptr;
        }

        Lifecycle::Destroy ();
    }

    //--------------------------------------------------------------------------------------------------

    bool Screen::Update ()
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event (m_EventQueue, &ev);

        if (ev.type == ALLEGRO_EVENT_TIMER)
        {
            m_Redraw = true;
        }
        else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            return false;
        }
        else if (ev.type == ALLEGRO_EVENT_DISPLAY_RESIZE)
        {
            m_RealWidth = ev.display.width;
            m_RealHeight = ev.display.height;

            al_acknowledge_resize (m_Display);
        }

        if (m_Redraw && al_is_event_queue_empty (m_EventQueue))
        {
            m_Redraw = false;
            al_clear_to_color (al_map_rgb (0, 0, 0));

            if (RenderFunction != nullptr)
            {
                RenderFunction ();
            }

            al_flip_display ();
        }

        return true;
    }

    //--------------------------------------------------------------------------------------------------

    void Screen::SetMouseCursor (const char* path)
    {
        ALLEGRO_BITMAP* bitmap = al_load_bitmap (path);
        ALLEGRO_MOUSE_CURSOR* cursor = al_create_mouse_cursor (bitmap, 0, 0);

        al_set_mouse_cursor (m_Display, cursor);
    }

    //--------------------------------------------------------------------------------------------------

    const Point Screen::GetScreenSize ()
    {
        return Point{ m_RealWidth, m_RealHeight };
    }

    //--------------------------------------------------------------------------------------------------
}
