#pragma once
#include "includes.h"

#include "PlayerObject.h"
#include "GroundLayer.h"
#include "MenuLayer.h"

class PlayLayer : public Layer {
protected:

public:
    Point startPos;
    float timer;

    bool m_demo;

    int jumps;
    int attempts;
    Sprite* bgSpr;
    
    PlayerObject* player;
    GroundLayer* groundLayer;

public:
   // void update(float delta);
    void updateVisibility(float delta);

    static Scene* scene();
    bool init();
    CREATE_FUNC(PlayLayer);
};