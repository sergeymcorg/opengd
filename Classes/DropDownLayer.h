#pragma once
#include "includes.h"

class DropDownLayer : public Layer {
private:

    // Inherit this function to add your custom code
    
    Layer* m_pMainLayer;
    LayerColor* m_pBGLayer;
    Menu* m_pButtonsMenu;
    Point m_eEndPos;
    Point m_eStartPos;

protected:
    // Getters
    Menu* getButtonsMenu();
    Layer* getMainLayer();


public:
    
    virtual void setup()=0;

    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    virtual void hideLayer(bool instant, bool removeFromParent);
    virtual void showLayer(bool instant);
    
    bool init();
};