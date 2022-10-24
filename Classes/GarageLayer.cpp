#include "GarageLayer.h"

Scene* GarageLayer::scene() {
    auto scene = Scene::create();
    scene->addChild(GarageLayer::create());
    return scene;
}

bool GarageLayer::init() {
    auto background = Sprite::create("GJ_gradientBG.png");
    auto winSize = Director::getInstance()->getWinSize();
    auto size = background->getContentSize();

    background->setScaleX(winSize.width / size.width);
    background->setScaleY(winSize.height / size.height);
    background->setAnchorPoint({0, 0});
    background->setColor({175, 175, 175});
    this->addChild(background);


    auto leftcorner = Sprite::createWithSpriteFrameName("GJ_sideArt_001.png");
    leftcorner->setPosition({0, winSize.height});
    leftcorner->setAnchorPoint({0, 0});
    leftcorner->setFlippedY(true);
    this->addChild(leftcorner);

    auto rightcorner = Sprite::createWithSpriteFrameName("GJ_sideArt_001.png");
    rightcorner->setPosition({winSize.width, winSize.height});
    rightcorner->setAnchorPoint({0, 1});
    rightcorner->setFlippedY(true);
    rightcorner->setFlippedX(true);
    this->addChild(rightcorner); 

    auto floor = Sprite::create("floor.png");
    floor->setPosition({winSize.width / 2, (winSize.height / 2) + 10});
    this->addChild(floor);

    auto square = ui::Scale9Sprite::create("square02_001.png");
    square->setAnchorPoint({0.5, 1});
    square->setPosition({winSize.width / 2, (winSize.height / 2) - 10});
    square->setContentSize({winSize.width - (winSize.width / 6), 100});
    square->setOpacity(75);
    this->addChild(square);

    auto iconsmenu = Menu::create();
    for(int i = 0; i < this->cubescount; i++){
        log_ << i;
        auto sprite1 = Sprite::createWithSpriteFrameName(string("player_").append(std::to_string(i / 10)).append(std::to_string(i % 10)).append("_001.png").c_str());
        auto sprite2 = Sprite::createWithSpriteFrameName(string("player_").append(std::to_string(i / 10)).append(std::to_string(i % 10)).append("_2_001.png").c_str());
        log_ << "Sprites created";
        auto node = Node::create();
        log_ << "Node created";
        node->addChild(sprite1);
        node->addChild(sprite2);
        log_ << "Now sprites are childs";
        auto menuitem = MenuItemSpriteExtra::createWithNode(node,  [&](Node* btn) {
            log_ << "cube clicked";
        });
        log_ << "Menu item created";
        iconsmenu->addChild(menuitem);
        log_ << "menu item now child";
    }
    log_ << "loop ended";
    iconsmenu->setAnchorPoint({0.5, 1});
    iconsmenu->setPosition({winSize.width / 2, (winSize.height / 2) - 10});
    iconsmenu->alignItemsHorizontallyWithPadding(10);
    this->addChild(iconsmenu);
    

    auto backbtn = MenuItemSpriteExtra::create("GJ_arrow_03_001.png", [&](Node* btn) {
        this->keyBackClicked();
    });

    auto menu = Menu::create();
    menu->addChild(backbtn);
    menu->setPosition({50, winSize.height - 50});
    addChild(menu);

    return true;
}

void GarageLayer::keyBackClicked() {
    Director::getInstance()->replaceScene(TransitionFade::create(0.5f, MenuLayer::scene()));
}