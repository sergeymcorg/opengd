#pragma once

#include "includes.h"
#include "ListLayer.h"

class GJMoreGamesLayer : public Layer {
private:
    ListLayer *m_pL;
public:
    // Currently uses 2.1 thing
    bool init();

    CREATE_FUNC(GJMoreGamesLayer);
};