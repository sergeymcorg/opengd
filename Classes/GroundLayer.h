#pragma once
#include "includes.h"

class GroundLayer : public Layer {
private:
    Sprite* m_pSprite;
    float m_fOneGroundSize;

public:
    void update(float dt);
    bool init(int groundID);
    static GroundLayer* create(int groundID);

    float m_fSpeed = 700; // Points per second
};