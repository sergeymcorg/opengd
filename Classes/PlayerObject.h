#pragma once
#include "GameObject.h"

class PlayerObject : public GameObject {
private:
    void update(float delta);
    bool init(int, Layer*);

    void logValues();

    Layer* gameLayer;
    bool inPlayLayer;

    Sprite* m_pMainSprite;
    Sprite* m_pSecondarySprite;
    Sprite* m_pShipSprite;

    ParticleSystemQuad* dragEffect1;
    ParticleSystemQuad* dragEffect2;
    ParticleSystemQuad* dragEffect3;
    ParticleSystemQuad* shipDragEffect;
    ParticleSystemQuad* landEffect1;
    ParticleSystemQuad* landEffect2;

    MotionStreak* motionStreak;

    double m_dXVel = 5.770002;
    double m_dYVel = 0;
    double m_dGravity = 0.958199;
    double m_dJump = 11.180032;

    bool m_bUpsideDown;
    bool m_bOnGround;

    float m_fSpeed = 0.9f;
    
    bool m_bIsDead;
    bool m_bIsLocked;

public:
    static PlayerObject* create(int, Layer*);

    void setMainColor(Color3B col);
    void setSecondaryColor(Color3B col);
};