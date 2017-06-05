// Copyright 2017 Dominik 'dreamsComeTrue' Jasiński. All Rights Reserved.

#include "Resources.h"

namespace aga
{
    //--------------------------------------------------------------------------------------------------

    Resource g_Resources[] = {
        { MAIN_MENU, "gfx", "main_menu.png" },

        //  Cursors
        { CURSOR_NORMAL, "gfx/cursors", "cursor_normal.png" }
    };

    //--------------------------------------------------------------------------------------------------

    const std::string GetResourcePath (ResourceID id)
    {
        std::string path = "../Data/";
        Resource res = g_Resources[id];

        path += res.Dir + std::string ("/") + res.Name;

        return path;
    }

    //--------------------------------------------------------------------------------------------------
}
