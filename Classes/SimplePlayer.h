#pragma once
#include "includes.h"

class SimplePlayer : public Sprite {
private:
    bool init(int cubeID);

    Sprite* m_pMainSprite;
    Sprite* m_pSecondarySprite;
    
public:
    static SimplePlayer* create(int cubeID);

    void setMainColor(Color3B col);
    void setSecondaryColor(Color3B col);
};