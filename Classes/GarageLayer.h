#pragma once
#include "includes.h"
#include "MenuLayer.h"
#include "SimplePlayer.h"
#include "ui/CocosGUI.h"

class GarageLayer : public Layer {
private:
    const vector<Color3B> m_colors = {
        {125, 255, 0}, 
        {0, 255, 0}, 
        {0, 255, 125}, 
        {0, 255, 255}, 
        {0, 125, 255}, 
        {0, 0, 255}, 
        {125, 0, 255}, 
        {255, 0, 255}, 
        {255, 0, 125},
        {255, 0, 0},
        {255, 125, 0},
        {255, 255, 0}
    };

    Sprite* m_pSelectionFrame;
    int m_nSelectedCube;
    SimplePlayer* m_pPreviewPlayer;
    cocos2d::ui::TextField* m_pUsernamefield;
public:
    static Scene* scene();
    bool init();
    CREATE_FUNC(GarageLayer);
};