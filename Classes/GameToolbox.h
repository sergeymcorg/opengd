#pragma once
#include "includes.h"

//general purpose class for helper functions that can be useful with any class at any moment
//(just as robtop)

class GameToolbox {

public:

    static int randomInt(int min, int max);
    static int randomInt(int max);
    static float randomFloat(int min, int max);
    static float randomFloat(int max);
    static Color3B randomColor3B();
    
};