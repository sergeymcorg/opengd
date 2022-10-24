#include "GarageLayer.h"

Scene* GarageLayer::scene() {
    auto scene = Scene::create();
    scene->addChild(GarageLayer::create());
    return scene;
}

bool GarageLayer::init() {
    if(!Layer::init()) return false;

    auto background = Sprite::create("GJ_gradientBG.png");
    auto winSize = Director::getInstance()->getWinSize();
    auto size = background->getContentSize();

    background->setScaleX(winSize.width / size.width);
    background->setScaleY(winSize.height / size.height);
    background->setAnchorPoint({0, 0});
    background->setColor({175, 175, 175});
    addChild(background);

    auto backbtn = MenuItemSpriteExtra::create("GJ_arrow_01_001.png", [&](Node* btn) {
        Director::getInstance()->replaceScene(TransitionFade::create(0.5f, MenuLayer::scene()));
    });
    auto menu = Menu::create();
    menu->addChild(backbtn);
    menu->setPosition({50, winSize.height - 50});
    addChild(menu);

    return true;
}

void GarageLayer::keyBackClicked() {
    
}
