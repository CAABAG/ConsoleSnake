#pragma once

#include "unitclass.h"

namespace con
{
    const int SCREEN_WIDTH              = 62;
    const int SCREEN_HEIGHT             = 36;
    const int INITIAL_X_VELOCITY        = 1;
    const int INITIAL_Y_VELOCITY        = 0;
    const int HALF_THE_WIDTH            = SCREEN_WIDTH / 2;
    const int HALF_THE_HEIGTH           = SCREEN_HEIGHT / 2;
    const int POINTS_X_POS              = 42;
    const int POINTS_Y_POS              = 36;
    const unsigned int INITIAL_POINTS   = 0;
    const char* PATH_TO_LEVEL           = "level.txt";
    const Direction INITIAL_DIRECTION   = Direction::rightdir;
    const bool INITIAL_DEAD_STATUS      = false;
    const bool INITIAL_EXIT_STATUS      = false;
}
