#pragma once
#include "includes.h"

class GroundLayer : public Layer {
private:
    Sprite* m_pSprite;
    float m_fOneGroundSize;

    CC_SYNTHESIZE(float, m_fSpeed, Speed)

public:
    void update(float dt);
    bool init(int groundID);
    static GroundLayer* create(int groundID);
};