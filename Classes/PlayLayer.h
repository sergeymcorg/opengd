#pragma once
#include "includes.h"

#include "PlayerObject.h"

class PlayLayer : public Layer {
protected:
    void addExitButton();

public:
    Point startPos;
    float timer;

    int jumps;
    int attempts;
    Sprite* bgSpr;
    Sprite* groundSpr;
    
    Menu* groundMenu;
    float groundStartPosition;
    float gsizeX;

    PlayerObject* player;

public:
    void update(float delta);
    void updateVisibility(float delta);
    void updateGround(float delta);
    

    static Scene* scene();
    bool init();
    CREATE_FUNC(PlayLayer);
};