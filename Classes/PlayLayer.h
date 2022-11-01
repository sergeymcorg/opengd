#pragma once
#include "includes.h"

#include "PlayerObject.h"
#include "GroundLayer.h"
#include "MenuLayer.h"

class PlayLayer : public Layer {
public:
    bool init();

    Sprite* m_pBG;
    GroundLayer* m_pGround;
    PlayerObject* m_pPlayer;

public:
    void update(float delta);
    static Scene* scene();
    CREATE_FUNC(PlayLayer);
};