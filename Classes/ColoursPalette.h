#pragma once

#include "includes.h"
#include "GarageLayer.h"
#include "PopupLayer.h"
#include "ui/CocosGUI.h"


class ColoursPalette : public PopupLayer {
	/*
    SimplePlayer * cubeIcon;
    SimplePlayer * shipIcon;
    SimplePlayer * ballIcon;
    SimplePlayer * birdIcon;
    SimplePlayer * dartIcon;
    SimplePlayer * robotIcon;
    SimplePlayer * spiderIcon;
    SimplePlayer * swingIcon;
    CCMenuItemSpriteExtra * clr1Btn;
    CCMenuItemSpriteExtra * clr2Btn;
    GJGarageLayer * garageLayer;
    int colorType = 0;
    bool glow = false;
    CCSprite * color1Selector = nullptr;
    CCSprite * color2Selector = nullptr;
	*/
	GarageLayer* garageLayer;

    static inline bool popupOpen = false;
public:
    static ColoursPalette* create(GarageLayer * garageLayer)
    {
        ColoursPalette* pRet = new ColoursPalette();
        if (pRet && pRet->init(garageLayer)) {
            pRet->autorelease();
            return pRet;
        } else {
            delete pRet;
            pRet = nullptr;
            return nullptr;
        }
    }
    bool init(GarageLayer * garageLayer);



    void addColorButton(Menu * father,float posX,float posY,int id);
    void onColorClick(Ref * sender);
    void onColor1Click(Ref * sender);
    void onColor2Click(Ref * sender);
    void onGlow(Ref * sender);
	void close(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
	
   // virtual void keyBackClicked() { this->close(nullptr); }
	
};

