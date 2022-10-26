#pragma once
#include "includes.h"

class GroundLayer : public Layer {
protected:

public:

    Menu* groundMenu;
    float groundStartPosition;
    float gsizeX;
    bool menuGameLayer;
    float sep;


public:

    void update(float delta);
    bool init(int groundID, bool menuLayer);
    static GroundLayer* create(int groundID, bool menuLayer);
};