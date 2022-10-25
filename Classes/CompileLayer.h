#pragma once

#include "includes.h"

#define BUILD_TIME __TIME__

class CompileLayer : public Layer {
protected:
    int next;
    std::string rand();
public:
    std::string getRandom();
    bool init();
    CREATE_FUNC(CompileLayer);
};