#include "MenuLayer.h"
#include "GarageLayer.h"
#include "GroundLayer.h"
#include "PlayLayer.h"
#include "MenuGameLayer.h"
#include "CreatorLayer.h"
#include "AlertLayer.h"
#include "ColoursPalette.h"
#include "AudioEngine.h"
#include "ListLayer.h"
#include "GJMoreGamesLayer.h"

bool music = true;

Scene* MenuLayer::scene() {
    auto scene = Scene::create();
    scene->addChild(MenuLayer::create());
    return scene;
}

bool MenuLayer::init(){
    if (!Layer::init()) return false;

    float offsetScale = 1.13F;
    
    if(music){
        AudioEngine::play2d("audiotracks/menuLoop.mp3", true, 0.5f);
        music = false;
    }

    auto winSize = Director::getInstance()->getWinSize();
    
    addChild(MenuGameLayer::create(), -1);
    
    auto log_oSpr = Sprite::createWithSpriteFrameName("GJ_logo_001.png");
    //log_oSpr->setPosition({ winSize.width / 2, winSize.height - 100 });
    log_oSpr->setPosition({ winSize.width / 2, winSize.height - 110 });
    log_oSpr->setScale(1.f);
    this->addChild(log_oSpr);
    
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
        Director::getInstance()->replaceScene(TransitionFade::create(0.5f, CreatorLayer::scene()));
    });

    // playBtn->setPosition({0, 20});
    // garageBtn->setPosition({-220, 20});
    // creatorBtn->setPosition({220, 20});

    auto mainButtonMenu = Menu::create(garageBtn, playBtn, creatorBtn, nullptr);    
    mainButtonMenu->setPositionY(0);
    mainButtonMenu->setPositionX(-70);
    mainButtonMenu->alignItemsHorizontallyWithPadding(50);
    mainButtonMenu->setScale(0.9f);
    //mainButtonMenu->setPosition({(winSize.width / 2), (winSize.height / 2)});

    menu->addChild(mainButtonMenu);
    auto selectCharacter = Sprite::createWithSpriteFrameName("GJ_chrSel_001.png");
    menu->addChild(selectCharacter);
    selectCharacter->setPosition(garageBtn->getPosition() - ccp(70, 70));

    auto levelEditor = Sprite::createWithSpriteFrameName("GJ_lvlEdit_001.png");
    menu->addChild(levelEditor);
    levelEditor->setPosition(creatorBtn->getPosition() + ccp(50, -50));
    
    auto achievementsBtn = MenuItemSpriteExtra::create("GJ_achBtn_001.png", [&](Node* btn) {
	    // AlertLayer::create("coming soon", "this feature has not been added yet!", "OK", "", 600, 250)->show();
        AchievementNotifier::getInstance()->showAchievements(); //just for test
		//ColoursPalette::create(nullptr)->show();
    });
    
    auto optionsBtn = MenuItemSpriteExtra::create("GJ_optionsBtn_001.png", [&](Node* btn) {
        log_ << "options!";
    });
    
    auto statsBtn = MenuItemSpriteExtra::create("GJ_statsBtn_001.png", [&](Node* btn) {
        auto alert = AlertLayer::create("WIP!", "This feature is not yet supported!", "Close", "Click me!", NULL, NULL);
        alert->setBtn2Callback([=](TextButton*){
            alert->close();
            AlertLayer::create("Woah hello ;)", "apparently you can do this now. its pretty cool!", "Close", "My mood rn", NULL, [=](TextButton*) {
                Application::getInstance()->openURL("https://www.youtube.com/watch?v=XSsRrlM3tNg");
            })->show();
        });
        alert->show();
    });

    auto bottomMenu = Menu::create(achievementsBtn, optionsBtn, statsBtn, nullptr);    
    //bottomMenu->setPositionY(90);
    bottomMenu->alignItemsHorizontallyWithPadding(10);
    bottomMenu->setScale(offsetScale - 0.13f);
    bottomMenu->setPosition({(winSize.width / 2) - 30, 100});

    this->addChild(bottomMenu);
    
    auto robBtn = MenuItemSpriteExtra::create("robtoplogo_small.png", [&](Node* btn) {
        Application::getInstance()->openURL("http://www.robtopgames.com");
    });

    menu->addChild(robBtn);
    //robBtn->setPosition(menu->convertToNodeSpace({120, 60}));
    robBtn->setPosition(menu->convertToNodeSpace({170, 90}));
    robBtn->setScale(0.8f);
    
    auto moreGamesBtn = MenuItemSpriteExtra::create("GJ_moreGamesBtn_001.png", [&](Node* btn) {
        log_ << "more games!";
        auto a = GJMoreGamesLayer::create();
        addChild(a);
    });

    menu->addChild(moreGamesBtn);
    //moreGamesBtn->setPosition(menu->convertToNodeSpace({winSize.width - 86, 90}));
    moreGamesBtn->setPosition(menu->convertToNodeSpace({winSize.width - 156, 130}));
    moreGamesBtn->setScale(0.9f);

    // To make it close to GD
    menu->setScale(offsetScale);
    log_ << menu->getPositionX();
    log_ << menu->getPositionY();
    
    menu->setPosition({(winSize.width / 2) + 82, (winSize.height / 2) + 47});

    return true;
}
