#pragma once
#include "includes.h"
#include "MenuLayer.h"
#include "SimplePlayer.h"

class GarageLayer : public Layer {
public:
    int cubescount = 13;
    int currentcube = 1;
    int currentFirstColor = 0;
    int currentSecondColor = 3;
    const vector<Color3B> colors = {
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

    static Scene* scene();
    bool init();
    bool cubeClicked();
    CREATE_FUNC(GarageLayer);
};