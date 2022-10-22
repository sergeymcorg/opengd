#pragma once
#include "includes.h"

class MenuLayer : public Layer {
public:
    static Scene* scene();
    bool init();
    CREATE_FUNC(MenuLayer);
};