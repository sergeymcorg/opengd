#pragma once

#include "includes.h"
#include "../imgui/CCImGuiLayer.h"

class DebugLayer : public Layer {
protected:
    int id;
    std::string sid;
    bool detached;
public:
    std::string getRandomName();
    void beginImGui(ImGuiLayer *layer);
    void removeSelf();
    bool init();
    CREATE_FUNC(DebugLayer);
};