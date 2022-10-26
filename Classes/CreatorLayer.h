#pragma once
#include "includes.h"
#include "MenuLayer.h"

class CreatorLayer : public Layer {
public:
    CREATE_FUNC(CreatorLayer)
    bool init();
    static Scene* scene();
};