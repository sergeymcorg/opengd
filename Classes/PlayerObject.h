#pragma once
#include "GameObject.h"

class PlayerObject : public GameObject {
public:
    Layer* gameLayer;
    bool inPlayLayer;

    Sprite* mainSprite;
    Sprite* secondarySprite;
    Sprite* shipFrame;

    ParticleSystemQuad* dragEffect1;
    ParticleSystemQuad* dragEffect2;
    ParticleSystemQuad* dragEffect3;
    ParticleSystemQuad* shipDragEffect;
    ParticleSystemQuad* landEffect1;
    ParticleSystemQuad* landEffect2;

    MotionStreak* motionStreak;

public:
    bool init(int, Layer*);
    void jump();

    void update(float delta);

    static PlayerObject* create(int, Layer*);
};