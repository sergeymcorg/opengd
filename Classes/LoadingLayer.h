#pragma once
#include "includes.h"
#include "utils.h"
#include "MenuLayer.h"
#include "AchievementManager.h"
#include "AchievementNotifier.h"
#include <filesystem>

class LoadingLayer : public Layer {
public:
	const char* getSplash();
    static Scene* scene();
    bool init();
    void loadAssets();
    void assetLoaded(Ref *sender);
    CREATE_FUNC(LoadingLayer);
    
    int m_nAssetsLoaded = 0;
    int m_nTotalAssets = 0;
    Sprite* m_pBarSprite = nullptr;
    Sprite* m_pGrooveSprite = nullptr;
    float m_fTotalBarWidth = 0.0f;
};