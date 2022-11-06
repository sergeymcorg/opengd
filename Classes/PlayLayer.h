#pragma once
#include "includes.h"

#include "PlayerObject.h"
#include "GroundLayer.h"
#include "MenuLayer.h"

class PlayLayer : public Layer {
private:
    bool init();

    Sprite* m_pBG;
    GroundLayer* m_pGround;
    PlayerObject* m_pPlayer;
    Point m_obCamPos;

    float m_fCameraYCenter;
    bool m_bFirstAttempt = true;
    bool m_bMoveCameraX;
    bool m_bMoveCameraY;
    bool m_bShakingCamera;
    float m_fEndOfLevel = 2000;
    float m_fShakeIntensity = 1;

public:
    void update(float delta);
    void updateCamera(float dt);
    static Scene* scene();
    CREATE_FUNC(PlayLayer);
};