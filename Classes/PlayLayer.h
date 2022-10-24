#pragma once
#include "includes.h"

class PlayLayer : public Layer {
public:
    
    int jumps;
    int attempts;
    Sprite* bgSpr;
    Sprite* groundSpr;
    
    Menu* groundMenu;
    float groundStartPosition;
    float gsizeX;
    
    void update(float delta);
    void updateVisibility(float delta);
    void updateGround(float delta);
    

    static Scene* scene();
    bool init();
    CREATE_FUNC(PlayLayer);
};