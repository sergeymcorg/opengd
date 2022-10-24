#pragma once
#include "includes.h"

#include "PlayerObject.h"

class PlayLayer : public Layer {
protected:
    void addExitButton();

public:
    Point startPos;
    float timer;

    bool m_demo;

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
    bool init(bool demo);
    bool init();
    //CREATE_FUNC(PlayLayer);
    static PlayLayer* create() { PlayLayer *pRet = new(std::nothrow) PlayLayer(); if (pRet && pRet->init()) { pRet->autorelease(); return pRet; } else { delete pRet; pRet = nullptr; return nullptr; } }
    static PlayLayer* create(bool demo) { PlayLayer *pRet = new(std::nothrow) PlayLayer(); if (pRet && pRet->init(demo)) { pRet->autorelease(); return pRet; } else { delete pRet; pRet = nullptr; return nullptr; } }
};