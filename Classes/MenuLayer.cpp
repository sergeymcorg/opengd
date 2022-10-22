#include "MenuLayer.h"

Scene* MenuLayer::scene() {
    auto scene = Scene::create();
    scene->addChild(MenuLayer::create());
    return scene;
}

bool MenuLayer::init(){
    if (!Layer::init()) return false;

    auto winSize = Director::getInstance()->getWinSize();
    
    auto menu = Menu::create();
    this->addChild(menu);

    auto btn = MenuItemSpriteExtra::create("GJ_closeBtn_001.png", [&](Node* btn) {
        log << "test button clicked!";
    });

    menu->addChild(btn);

    return true;
}
