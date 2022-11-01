#pragma once
#include "includes.h"

//general purpose class for helper functions that can be useful with any class at any moment
//(just as robtop)

namespace GameToolbox {
    const vector<Color3B> iconColors = {
        {125, 255, 0},
        {0, 255, 0},
        {0, 255, 125},
        {0, 255, 255},
        {0, 125, 255},
        {0, 0, 255},
        {125, 0, 255},
        {255, 0, 255},
        {255, 0, 125},
        {255, 0, 0},
        {255, 125, 0},
        {255, 255, 0}
    };

    int randomInt(int min, int max);
    int randomInt(int max);
    float randomFloat(int min, int max);
    float randomFloat(int max);
    Color3B randomColor3B();
    
};