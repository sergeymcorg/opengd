#include "DebugLayer.h"
#include "../imgui/imgui/imgui.h"
#include "../imgui/CCIMGUI.h"
// Scene* DebugLayer::scene() {
//     auto scene = Scene::create();
//     scene->addChild(DebugLayer::create());
//     return scene;
// }

int frames = 0;

void DebugLayer::beginImGui(ImGuiLayer *layer) {
    // enable docking
    auto& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    // add ui callbacks
    CCIMGUI::getInstance()->addCallback([=](){
        ImGui::Text("Hello, world!");
        ImGui::NewLine();
        ImGui::Text("Frames: %d", frames);
        frames++;
        // create button with Sprite, auto pushID / popID with texture id
    }, "hello");
    // remove ui callbacks to stop rendering
    //CCIMGUI::getInstance()->removeCallback("hello");
}

std::string DebugLayer::getRandomName() {
    return " ";
}

ImGuiLayer *__DebugLayer_currentGui;
bool debugmade = false;

void DebugLayer::removeSelf() {
    Logger() << "Removing ImGui window";
    ImGuiLayer *layer = dynamic_cast<ImGuiLayer*>(Director::getInstance()->getRunningScene()->getChildByName("ImGui"));
    if(debugmade) CCIMGUI::getInstance()->removeCallback("hello");
    if(layer) {
        layer->retain();
        layer->removeFromParent();
        __DebugLayer_currentGui = nullptr;
    } else {
        Logger() << "Window not found";
    }
}

bool DebugLayer::init() {
    if (!Layer::init()) return false;

    std::string layerName = "ImGui";
    detached = false;
    auto order = INT_MAX;
    auto layer = ImGuiLayer::create();
    if(!layer) return false;
    __DebugLayer_currentGui = layer;
    Director::getInstance()->getRunningScene()->addChild(layer, order, "ImGui");

    auto e = Director::getInstance()->getEventDispatcher();
    e->addCustomEventListener(Director::EVENT_BEFORE_SET_NEXT_SCENE, [&](EventCustom*){
        layer = dynamic_cast<ImGuiLayer*>(Director::getInstance()->getRunningScene()->getChildByName("ImGui"));
        if (layer) {
            debugmade = false;
            layer->retain();
            layer->removeFromParent();
            detached = true;
        }
    });
    e->addCustomEventListener(Director::EVENT_AFTER_SET_NEXT_SCENE, [&](EventCustom*){
        if (__DebugLayer_currentGui && detached) {
            if(__DebugLayer_currentGui->getParent() == nullptr) {
                Director::getInstance()->getRunningScene()->addChild(__DebugLayer_currentGui, order, "ImGui");
                //__DebugLayer_currentGui->release();
                debugmade = true;
                detached = false;
                DebugLayer::create();
            }
        }
    });

    beginImGui(layer);

    return true;
}