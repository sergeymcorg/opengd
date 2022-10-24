#pragma once
#include "includes.h"
#include "MenuLayer.h"

class GarageLayer : public Layer {
public:
    int cubescount = 13;

    static Scene* scene();
    bool init();
    void keyBackClicked();
    bool cubeClicked();
    CREATE_FUNC(GarageLayer);
};