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
    Menu *bgSprites;
    float bgStartPos;
    float sep;
    float bsizeX;

public:
    void processPlayerMovement(float delta);
    void processBackground(float delta);
    void update(float delta);
    void updateVisibility(float delta);

    static Scene* scene();
    bool init();
    CREATE_FUNC(MenuGameLayer);
};