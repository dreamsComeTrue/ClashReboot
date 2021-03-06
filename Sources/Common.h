// Copyright 2017 Dominik 'dreamsComeTrue' Jasiński. All Rights Reserved.

#ifndef __COMMON_H__
#define __COMMON_H__

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>

#include <string>

#define SAFE_DELETE(x)    \
    {                     \
        if (x != nullptr) \
        {                 \
            delete x;     \
            x = nullptr;  \
        }                 \
    }

namespace aga
{
}

#endif //   __COMMON_H__
