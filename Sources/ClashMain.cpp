// Copyright 2017 Dominik 'dreamsComeTrue' Jasiński. All Rights Reserved.

#include "Common.h"
#include "Screen.h"
#include <iostream>

using namespace std;

// The attributes of the screen
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

aga::Screen* g_Screen;

int main (int argc, char* argv[])
{
    g_Screen = new aga::Screen (SCREEN_WIDTH, SCREEN_HEIGHT);

    if (!g_Screen->Initialize ())
    {
        printf ("Failed to initialize!\n");
    }

    g_Screen->SetMouseCursor ("../Data/cursors/normal_cursor.png");
    g_Screen->MainLoop ();
    g_Screen->Destroy ();

    return 0;
}
