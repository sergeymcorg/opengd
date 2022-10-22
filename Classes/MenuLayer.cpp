#include "MenuLayer.h"

Scene* MenuLayer::scene() {
    auto scene = Scene::create();
    scene->addChild(MenuLayer::create());
    return scene;
}

bool MenuLayer::init(){
    if (!Layer::init()) return false;

    auto winSize = Director::getInstance()->getWinSize();
    
    auto logoSpr = Sprite::createWithSpriteFrameName("GJ_logo_001.png");
    logoSpr->setPosition({ winSize.width / 2, winSize.height / 2 + 220 });
    this->addChild(logoSpr);
    
    auto mainBtns = Menu::create();
    this->addChild(mainBtns);

    auto playBtn = MenuItemSpriteExtra::create("GJ_playBtn_001.png", [&](Node* btn) {
        log << "test button clicked!";
    });
    
    auto garageBtn = MenuItemSpriteExtra::create("GJ_garageBtn_001.png", [&](Node* btn) {
        log << "test button clicked!";
    });
    
    
    auto creatorBtn = MenuItemSpriteExtra::create("GJ_creatorBtn_001.png", [&](Node* btn) {
        log << "test button clicked!";
    });
    
    garageBtn->setPositionX(-250);
    creatorBtn->setPositionX(250);
    
    mainBtns->addChild(playBtn);
    mainBtns->addChild(garageBtn);
    mainBtns->addChild(creatorBtn);
    
    
    auto bottomMenu = Menu::create();
    this->addChild(bottomMenu);
    
    auto achievementsBtn = MenuItemSpriteExtra::create("GJ_achBtn_001.png", [&](Node* btn) {
        log << "test button clicked!";
    });
    
    auto optionsBtn = MenuItemSpriteExtra::create("GJ_optionsBtn_001.png", [&](Node* btn) {
        log << "test button clicked!";
    });
    
    auto statsBtn = MenuItemSpriteExtra::create("GJ_statsBtn_001.png", [&](Node* btn) {
        log << "test button clicked!";
    });
    
    auto ngBtn = MenuItemSpriteExtra::create("GJ_ngBtn_001.png", [&](Node* btn) {
        log << "test button clicked!";
    });

    //auto bottomMenu = Menu::create(achievementsBtn, optionsBtn, statsBtn, ngBtn);
    //crash ^
    
    bottomMenu->addChild(achievementsBtn);
    bottomMenu->addChild(optionsBtn);
    bottomMenu->addChild(statsBtn);
    bottomMenu->addChild(ngBtn);
    
    bottomMenu->setPositionY(winSize.height / 2 - 250);
    bottomMenu->alignItemsHorizontallyWithPadding(15);
    

    auto socialsMenu = Menu::create();
    this->addChild(socialsMenu);
    
    auto rbBtn = MenuItemSpriteExtra::create("robtoplogo_small.png", [&](Node* btn) {
        log << "test button clicked!";
    });
    
    auto fbBtn = MenuItemSpriteExtra::create("gj_fbIcon_001.png", [&](Node* btn) {
        log << "test button clicked!";
    });

    auto twBtn = MenuItemSpriteExtra::create("gj_twIcon_001.png", [&](Node* btn) {
        log << "test button clicked!";
    });
    
    auto ytBtn = MenuItemSpriteExtra::create("gj_ytIcon_001.png", [&](Node* btn) {
        log << "test button clicked!";
    });
    
    socialsMenu->setPosition({winSize.width / 2 - 550, winSize.height / 2 - 280});

    rbBtn->setScale(.6);
    fbBtn->setScale(.6);
    twBtn->setScale(.6);
    ytBtn->setScale(.6);

    rbBtn->setPosition({0, -30});
    fbBtn->setPosition({-45, 20});
    twBtn->setPosition({0, 20});
    ytBtn->setPosition({45, 20});
    
    socialsMenu->addChild(rbBtn);
    socialsMenu->addChild(fbBtn);
    socialsMenu->addChild(twBtn);
    socialsMenu->addChild(ytBtn);
    
    return true;
}
