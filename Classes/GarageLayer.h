#pragma once
#include "includes.h"
#include "MenuLayer.h"

class GarageLayer : public Layer {
public:
    static Scene* scene();
    bool init();
    void keyBackClicked();
    CREATE_FUNC(GarageLayer);
};