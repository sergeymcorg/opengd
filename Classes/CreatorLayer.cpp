#include "CreatorLayer.h"

Scene* CreatorLayer::scene() {
    auto scene = Scene::create();
    scene->addChild(CreatorLayer::create());
    return scene;
}

bool CreatorLayer::init() {
    if (!Layer::init()) return false;

    auto winSize = Director::getInstance()->getWinSize();

    auto bg = Sprite::create("GJ_gradientBG.png");
    bg->setScaleX(winSize.width / bg->getContentSize().width);
    bg->setScaleY(winSize.height / bg->getContentSize().height);
    bg->setAnchorPoint({0, 0});
    bg->setColor({0, 102, 255});
    this->addChild(bg);

    auto corn1 = Sprite::createWithSpriteFrameName("GJ_sideArt_001.png");
    this->addChild(corn1);
    corn1->setPosition({0, 0});
    corn1->setAnchorPoint({0, 0});

    auto corn2 = Sprite::createWithSpriteFrameName("GJ_sideArt_001.png");
    this->addChild(corn2);
    corn2->setPosition({0, winSize.height});
    corn2->setAnchorPoint({0, 1});
    corn2->setFlippedY(true);

    auto corn3 = Sprite::createWithSpriteFrameName("GJ_sideArt_001.png");
    this->addChild(corn3);
    corn3->setPosition(winSize);
    corn3->setAnchorPoint({1, 1});
    corn3->setFlippedX(true);
    corn3->setFlippedY(true);

    auto corn4 = Sprite::createWithSpriteFrameName("GJ_sideArt_001.png");
    this->addChild(corn4);
    corn4->setPosition({winSize.width, 0});
    corn4->setAnchorPoint({1, 0});
    corn4->setFlippedX(true);

    auto menu = Menu::create();
    this->addChild(menu);

    auto createBtn = MenuItemSpriteExtra::create("GJ_createBtn_001.png", [&](Node*) {
        log_ << "create";
    });
    menu->addChild(createBtn);

    auto savedBtn = MenuItemSpriteExtra::create("GJ_savedBtn_001.png", [&](Node*) {
        log_ << "saved";
    });
    menu->addChild(savedBtn);

    auto featuredBtn = MenuItemSpriteExtra::create("GJ_featuredBtn_001.png", [&](Node*) {
        log_ << "featured";
    });
    menu->addChild(featuredBtn);

    auto searchBtn = MenuItemSpriteExtra::create("GJ_searchBtn_001.png", [&](Node*) {
        log_ << "search";
    });
    menu->addChild(searchBtn);

    menu->alignItemsInColumnsWithArray({Value(2), Value(2)}, 52);

    menu->setPosition(winSize / 2 + Size(250, 15));

    auto backBtn = MenuItemSpriteExtra::create("GJ_arrow_03_001.png", [&](Node*) {
        Director::getInstance()->replaceScene(TransitionFade::create(.5, MenuLayer::scene()));
    });
    menu->addChild(backBtn);
    backBtn->setPosition(menu->convertToNodeSpace({48, winSize.height - 46}));

    return true;
}