#pragma once
#include "includes.h"

class SimplePlayer : public Sprite {
private:
    bool init(int cubeID);
    
public:
    static SimplePlayer* create(int cubeID);

    Sprite* m_pMainSprite;
    Sprite* m_pSecondarySprite;
};