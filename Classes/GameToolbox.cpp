#include "includes.h"
#include "GameToolbox.h"
#include <cstdlib>

//general purpose class for helper functions that can be useful anywhere
//(just as robtop)

int GameToolbox::randomInt(int min, int max) {
    return rand() % max + min;
}
int GameToolbox::randomInt(int max) {
    return GameToolbox::randomInt(0, max);
}
float GameToolbox::randomFloat(int min, int max) {
    return (float) GameToolbox::randomInt(min, max);
}
float GameToolbox::randomFloat(int max) {
   return (float) GameToolbox::randomInt(max);
}

Color3B GameToolbox::randomColor3B() {
    
    uint8_t r = GameToolbox::randomInt(255);
    uint8_t g = GameToolbox::randomInt(255);
    uint8_t b = GameToolbox::randomInt(255);
    
    return {r, g, b};
}