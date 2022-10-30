#pragma once
#include "includes.h"
#include "MenuLayer.h"
#include "SimplePlayer.h"

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

public:
    static Scene* scene();
    bool init();
    CREATE_FUNC(GarageLayer);
};