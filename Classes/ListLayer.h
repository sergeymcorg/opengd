#pragma once

#include "includes.h"
#include "DropDownLayer.h"

class ListLayer : public DropDownLayer
{
public:
    ListLayer();

    ListLayer(const char*);

    ~ListLayer();

    static ListLayer* create(const char* title);


private:
    void setup() override;
    
    const char* m_Title;
};