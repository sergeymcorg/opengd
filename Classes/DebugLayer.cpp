#include "DebugLayer.h"
#include "../imgui/imgui/imgui.h"
#include "../imgui/CCIMGUI.h"
// Scene* DebugLayer::scene() {
//     auto scene = Scene::create();
//     scene->addChild(DebugLayer::create());
//     return scene;
// }

void DebugLayer::beginImGui(ImGuiLayer *layer) {
    // enable docking
    auto& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    // add ui callbacks
    CCIMGUI::getInstance()->addCallback([=](){
        ImGui::Text("Hello, world!");
        // create button with Sprite, auto pushID / popID with texture id
    }, "hello");
    // remove ui callbacks to stop rendering
    //CCIMGUI::getInstance()->removeCallback("hello");
}

std::string DebugLayer::getRandomName() {
    return sid;
}

ImGuiLayer *__DebugLayer_currentGui;

void DebugLayer::removeSelf() {
    Logger() << "Removing ImGui window";
    ImGuiLayer *layer = dynamic_cast<ImGuiLayer*>(Director::getInstance()->getRunningScene()->getChildByName(getRandomName()));
    Logger() << "1";
    if(layer) {
        Logger() << "2";
        layer->retain();
        Logger() << "3";
        layer->removeFromParent();
        Logger() << "4";
        detached = true;
        Logger() << "5";
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
    Director::getInstance()->getRunningScene()->addChild(layer, order, layerName);

    auto e = Director::getInstance()->getEventDispatcher();
    sid.clear();
    sid.append("First ImGui");
    e->addCustomEventListener(Director::EVENT_BEFORE_SET_NEXT_SCENE, [&](EventCustom*){
        layer = dynamic_cast<ImGuiLayer*>(Director::getInstance()->getRunningScene()->getChildByName(getRandomName()));
        if (layer) {
            layer->retain();
            layer->removeFromParent();
            detached = true;
        }
    });
    e->addCustomEventListener(Director::EVENT_AFTER_SET_NEXT_SCENE, [&](EventCustom*){
        if (__DebugLayer_currentGui && detached) {
            if(__DebugLayer_currentGui->getParent() == nullptr) {
                id = rand();
                sid.clear();
                sid.append(std::to_string(id));
                Director::getInstance()->getRunningScene()->addChild(__DebugLayer_currentGui, order, sid);
                //__DebugLayer_currentGui->release();
                detached = false;
            }
        }
    });

    beginImGui(layer);

    return true;
}