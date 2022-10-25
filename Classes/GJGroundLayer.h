#pragma once
#include "includes.h"

class GJGroundLayer : public Layer {
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
    static GJGroundLayer* create(int groundID, bool menuLayer);
};