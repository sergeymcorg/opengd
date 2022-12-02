#pragma once

#include "includes.h"

class LoadingCircleLayer : public Layer {
public:
    Sprite *m_pCircle;

    bool init();
    CREATE_FUNC(LoadingCircleLayer);

    void update(float delta);
};
