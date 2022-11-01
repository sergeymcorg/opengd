#pragma once
#include "includes.h"
#include "MenuLayer.h"
#include "SimplePlayer.h"
#include "ui/CocosGUI.h"
#include "GameToolbox.h"

class GarageLayer : public Layer {
private:
    Sprite* m_pSelectionFrame;
    Sprite* m_pSelectionFrame2;
    Sprite* m_pSelectionFrame3;
    int m_nSelectedCube;
    int m_nSelectedMC;
    int m_nSelectedSC;
    SimplePlayer* m_pPreviewPlayer;
    cocos2d::ui::TextField* m_pUsernamefield;
public:
    static Scene* scene();
    bool init();
    CREATE_FUNC(GarageLayer);
};