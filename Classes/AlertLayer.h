#pragma once

#include "includes.h"
#include "GarageLayer.h"
#include "PopupLayer.h"
#include "ui/CocosGUI.h"

class AlertLayer : public Layer {
private:
    bool init(const char* title, float height);

    // Inherit this function to add your custom code
    virtual void setup() {};
    
    Layer* m_pMainLayer;
    LayerColor* m_pBGLayer;
    Menu* m_pButtonsMenu;
    Point m_eEndPos;
    Point m_eStartPos;
    static inline bool popupOpen = false;
public:
    static AlertLayer* create(const char* title, float height = 220);

    virtual void hideLayer(bool instant, bool removeFromParent);
    virtual void showLayer(bool instant);
    void close(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
};