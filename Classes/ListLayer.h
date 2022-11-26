#pragma once

#include "includes.h"
#include "DropDownLayer.h"

class ListLayer : public DropDownLayer
{
public:
    Menu *getCCButtonMenu();

    Layer *getCCMainLayer();

    ListLayer();

    ListLayer(const char*);

    ~ListLayer();

    static ListLayer* create(const char* title);
protected:
    void setup() override;
    
    const char* m_Title;
};