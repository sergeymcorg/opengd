#include "MenuLayer.h"
#include "GarageLayer.h"
#include "DropDownLayer.h"
#include "DebugLayer.h"
#include "PlayLayer.h"
#include "GitHubLayer.h"

Scene* MenuLayer::scene() {
    auto scene = Scene::create();
    scene->addChild(MenuLayer::create());
    return scene;
}

bool MenuLayer::init(){
    if (!Layer::init()) return false;
    

    //auto dl = DebugLayer::create();

    // auto background = Sprite::create("GJ_gradientBG.png");
    auto winSize = Director::getInstance()->getWinSize();
    // auto size = background->getContentSize();

    // background->setScaleX(winSize.width / size.width);
    // background->setScaleY(winSize.height / size.height);
    // background->setAnchorPoint({0, 0});
    // background->setColor({0, 0, 175});
    // addChild(background);

    PlayLayer *demo = PlayLayer::create(true);
    addChild(demo);
    
    auto logoSpr = Sprite::createWithSpriteFrameName("GJ_logo_001.png");
    logoSpr->setPosition({ winSize.width / 2, winSize.height - 100 });
    this->addChild(logoSpr);
    
    auto menu = Menu::create();
    this->addChild(menu);

    auto playBtn = MenuItemSpriteExtra::create("GJ_playBtn_001.png", [&](Node* btn) {
        auto scene = PlayLayer::scene();
        Director::getInstance()->pushScene(TransitionFade::create(0.5f, scene));
    });
    
    auto garageBtn = MenuItemSpriteExtra::create("GJ_garageBtn_001.png", [&](Node* btn) {
        Director::getInstance()->replaceScene(TransitionFade::create(0.5f, GarageLayer::scene()));
    });    
    
    auto creatorBtn = MenuItemSpriteExtra::create("GJ_creatorBtn_001.png", [&](Node* btn) {
        log << "creator!";
    });

    playBtn->setPosition({0, 20});
    garageBtn->setPosition({-220, 20});
    creatorBtn->setPosition({220, 20});

    menu->addChild(playBtn);
    menu->addChild(garageBtn);
    menu->addChild(creatorBtn);
    menu->addChild(GitHubLayer::create());
    // auto selectCharacter = Sprite::createWithSpriteFrameName("GJ_chrSel_001.png");
    // menu->addChild(selectCharacter);
    // selectCharacter->setPosition(garageBtn->getPosition() - ccp(100, 100));

    // auto levelEditor = Sprite::createWithSpriteFrameName("GJ_lvlEdit_001.png");
    // menu->addChild(levelEditor);
    // levelEditor->setPosition(creatorBtn->getPosition() + ccp(100, -100));
    
    auto achievementsBtn = MenuItemSpriteExtra::create("GJ_achBtn_001.png", [&](Node* btn) {
        log << "ach!";
    });
    
    auto optionsBtn = MenuItemSpriteExtra::create("GJ_optionsBtn_001.png", [&](Node* btn) {
        log << "options!";
    });
    
    auto statsBtn = MenuItemSpriteExtra::create("GJ_statsBtn_001.png", [&](Node* btn) {
        log << "stats!";
    });

    auto bottomMenu = Menu::create(achievementsBtn, optionsBtn, statsBtn, nullptr);    
    bottomMenu->setPositionY(90);
    bottomMenu->alignItemsHorizontallyWithPadding(10);
    this->addChild(bottomMenu);
    
    auto robBtn = MenuItemSpriteExtra::create("robtoplogo_small.png", [&](Node* btn) {
        Application::getInstance()->openURL("http://www.robtopgames.com");
    });

    menu->addChild(robBtn);
    robBtn->setPosition(menu->convertToNodeSpace({120, 60}));
    
    auto moreGamesBtn = MenuItemSpriteExtra::create("GJ_moreGamesBtn_001.png", [&](Node* btn) {
        log << "more games!";
        auto a = DropDownLayer::create("test");
        this->addChild(a);
        a->showLayer(false);
    });

    menu->addChild(moreGamesBtn);
    moreGamesBtn->setPosition(menu->convertToNodeSpace({winSize.width - 86, 90}));

    return true;
}