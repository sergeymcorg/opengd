#pragma once
#include "includes.h"
#include "GameObject.h"
#include "CircleWave.h"

class PlayerObject : public GameObject {
private:
    void updateJump(float dt);
    bool init(int, Layer*);
    void runRotateAction();
    void stopRotation();

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
    double m_dJumpHeight = 11.180032;

    bool m_bUpsideDown;
    bool m_bOnGround;

    float m_fSpeed = 0.9f;
    
    bool m_bIsDead;
    bool m_bIsLocked;

    bool m_bIsHolding;

    bool m_bFlying;

    Point m_obLastGroundPos;

public:
    static PlayerObject* create(int, Layer*);
     
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

    void setMainColor(Color3B col);
    void setSecondaryColor(Color3B col);
    void setShipColor(Color3B col);

    Color3B getMainColor();
    Color3B getSecondaryColor();
    Color3B getShipColor();

    void jump();

    bool isFlying();
    bool isUpsideDown();
    GETTER(m_bIsDead, IsDead)

    Point getLastGroundPos();
    void update(float dt);
};