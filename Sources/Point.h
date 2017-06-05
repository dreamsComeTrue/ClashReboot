// Copyright 2017 Dominik 'dreamsComeTrue' Jasiński. All Rights Reserved.

#ifndef __POINT_H__
#define __POINT_H__

namespace aga
{
    struct Point
    {
        union {
            struct
            {
                unsigned X, Y;
            };
            struct
            {
                unsigned Width, Height;
            };
        };
    };
}

#endif //   __POINT_H__
