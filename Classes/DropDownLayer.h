#pragma once
#include "includes.h"

class DropDownLayer : public Layer {
private:
    bool init(const char* title, float height);

    // Inherit this function to add your custom code
    virtual void setup() {};
    
    LayerColor* m_pBGLayer;
    Menu* m_pButtonsMenu;
    Point m_eEndPos;
    Point m_eStartPos;

public:
    static DropDownLayer* create(const char* title, float height = 220);

    virtual void hideLayer(bool instant);
    virtual void showLayer(bool instant);
};