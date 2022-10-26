#pragma once
#include "includes.h"

#include "PlayerObject.h"
#include "GroundLayer.h"

class MenuGameLayer : public Layer {
protected:

public:
    Point startPos;
    PlayerObject* player;
    GroundLayer* groundLayer;
    Sprite* bgSpr;

public:
   // void update(float delta);
    void updateVisibility(float delta);

    static Scene* scene();
    bool init();
    CREATE_FUNC(MenuGameLayer);
};