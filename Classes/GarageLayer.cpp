#include "GarageLayer.h"
#include "ui/CocosGUI.h"
#include "PlayerObject.h"
#include "ColoursPalette.h"
#include "PopupLayer.h"

Scene* GarageLayer::scene() {
    auto scene = Scene::create();
    scene->addChild(GarageLayer::create());
    return scene;
}

bool GarageLayer::init() {
    if (!Layer::init()) return false;

    auto winSize = Director::getInstance()->getWinSize();
    
    auto background = Sprite::create("GJ_gradientBG.png");
    background->setScale(winSize.width / background->getContentSize().width, winSize.height / background->getContentSize().height);
    background->setAnchorPoint({0, 0});
    background->setColor({175, 175, 175});
    this->addChild(background);

    auto leftcorner = Sprite::createWithSpriteFrameName("GJ_sideArt_001.png");
    leftcorner->setPosition({0, winSize.height});
    leftcorner->setAnchorPoint({0, 1});
    leftcorner->setFlippedY(true);
    this->addChild(leftcorner);

    auto rightcorner = Sprite::createWithSpriteFrameName("GJ_sideArt_001.png");
    rightcorner->setPosition(winSize);
    rightcorner->setAnchorPoint({1, 1});
    rightcorner->setFlippedY(true);
    rightcorner->setFlippedX(true);
    this->addChild(rightcorner); 

    if (!GM->getVariable<std::string>("player-username").compare("")) {
        GM->setVariable("player-username", "Player");
       GM->save();
    }
    m_pUsernamefield = ui::TextField::create("Player", "bigFont.fnt", 48);
    m_pUsernamefield->setString(GM->getVariable<std::string>("player-username"));
    m_pUsernamefield->setPlaceHolderColor({ 120, 170, 240 });
    m_pUsernamefield->setMaxLength(20);
    m_pUsernamefield->setPosition({winSize.width / 2, winSize.height - 80});
    this->addChild(m_pUsernamefield);

    auto nameTxt = Sprite::createWithSpriteFrameName("GJ_nameTxt_001.png");
    nameTxt->setPosition(m_pUsernamefield->getPosition() + ccp(-250, 20));
    this->addChild(nameTxt);

    auto floor = Sprite::create("floor.png");
    floor->setPosition({winSize.width / 2, (winSize.height / 2) + 20});
    this->addChild(floor);

    auto bottomBG = Sprite::create("edit_barBG_001.png");
    bottomBG->setScaleX(winSize.width / bottomBG->getContentSize().width);
    bottomBG->setAnchorPoint({0, 0});
    this->addChild(bottomBG);

    this->m_pPreviewPlayer = SimplePlayer::create(GM->getVariable<int>("player-cube"));
    m_pPreviewPlayer->setPosition({winSize.width / 2, floor->getPositionY() + floor->getContentSize().height / 2});
    m_pPreviewPlayer->setAnchorPoint({0.5, 0});
    m_pPreviewPlayer->setScale(1.6f);
    m_pPreviewPlayer->setMainColor(GameToolbox::iconColors[GM->getVariable<int>("player-main-color")]);
    m_pPreviewPlayer->setSecondaryColor(GameToolbox::iconColors[GM->getVariable<int>("player-secondary-color")]);
    this->addChild(m_pPreviewPlayer);
	
    auto square = ui::Scale9Sprite::create("square02_001.png");
    square->setAnchorPoint({0.5, 1});
    square->setPosition({winSize.width / 2, (winSize.height / 2) - 40});
    square->setContentSize({960, 110});
    square->setOpacity(75);
    this->addChild(square);

    auto hint = Sprite::createWithSpriteFrameName("GJ_unlockTxt_001.png");
    hint->setAnchorPoint({1, 0.5});
    hint->setPosition({winSize.width / 2 + square->getContentSize().width / 2 - 40, square->getPositionY() + 2});
    this->addChild(hint);
    
    auto iconsMenu = Menu::create();
    
    for (int i = 1; i <= MAX_CUBES_COUNT; i++) {
        auto player = SimplePlayer::create(i);
        player->setMainColor({158, 158, 158});
        player->setSecondaryColor({255, 255, 255});
        
        auto btn = MenuItemSpriteExtra::createWithNode(player, [=](Node* btn) {
            this->m_nSelectedCube = btn->getTag() - 1;
            GM->setVariable("player-cube", btn->getTag());
            this->m_pSelectionFrame->setPosition(iconsMenu->convertToWorldSpace(btn->getPosition()));

            this->m_pPreviewPlayer->removeFromParentAndCleanup(true);
            //this->m_pPreviewPlayer->release(); // this shit crashes dont do this
            this->m_pPreviewPlayer = SimplePlayer::create(btn->getTag());
            m_pPreviewPlayer->setPosition({winSize.width / 2, floor->getPositionY() + floor->getContentSize().height / 2});
            m_pPreviewPlayer->setAnchorPoint({0.5, 0});
            m_pPreviewPlayer->setScale(1.6f);
            m_pPreviewPlayer->setMainColor(GameToolbox::iconColors[GM->getVariable<int>("player-main-color")]);
            m_pPreviewPlayer->setSecondaryColor(GameToolbox::iconColors[GM->getVariable<int>("player-secondary-color")]);
            this->addChild(m_pPreviewPlayer);
        });
        
        btn->setTag(i);

        iconsMenu->addChild(btn);
    }

    iconsMenu->setPosition({winSize.width / 2, square->getPositionY() - square->getContentSize().height / 2});
    iconsMenu->alignItemsHorizontallyWithPadding(12);
    this->addChild(iconsMenu);


    auto colorsMenu = Menu::create();

    for (int i = 0; i < GameToolbox::iconColors.size(); i++) {
        log_ << "srptei";
        auto colorSprite = Sprite::create("square.png");
        log_ << "button?";
        colorSprite->setColor(GameToolbox::iconColors[i]);
        auto btn = MenuItemSpriteExtra::createWithNode(colorSprite, [=](Node* button) {
            

            log_ << "huh.";
            this->m_pSelectionFrame2->setPosition({colorsMenu->getPositionX()+button->getPositionX(),colorsMenu->getPositionY()});
            log_ << m_pSelectionFrame2->getPositionX();
            
            m_pPreviewPlayer->setMainColor(GameToolbox::iconColors[i]);
            
            GM->setVariable("player-main-color", button->getTag());
           });
        btn->setScale(1.7f);
        btn->setNewScale(1.25f);
        log_ << "button? 2";
        btn->setTag(i);
        colorsMenu->addChild(btn);
    }

    colorsMenu->setPosition({ winSize.width / 2, square->getPositionY() - square->getContentSize().height / 2 - 125 });
    colorsMenu->alignItemsHorizontallyWithPadding(15);
    this->addChild(colorsMenu);


    auto secondaryColorsMenu = Menu::create();

    for (int i = 0; i < GameToolbox::iconColors.size(); i++) {
        log_ << "srptei";
        auto colorSprite = Sprite::create("square.png");
        log_ << "button?";
        colorSprite->setColor(GameToolbox::iconColors[i]);
        auto btn = MenuItemSpriteExtra::createWithNode(colorSprite, [=](Node* button) {


            log_ << "huh.";
            this->m_pSelectionFrame3->setPosition({ secondaryColorsMenu->getPositionX() + button->getPositionX(),secondaryColorsMenu->getPositionY() });
            log_ << m_pSelectionFrame3->getPositionX();

            m_pPreviewPlayer->setSecondaryColor(GameToolbox::iconColors[i]);
            GM->setVariable("player-secondary-color", button->getTag());

            });
        btn->setScale(1.7f);
        btn->setNewScale(1.25f);
        log_ << "button? 2";
        btn->setTag(i);
        secondaryColorsMenu->addChild(btn);
    }

    secondaryColorsMenu->setPosition({ winSize.width / 2, square->getPositionY() - square->getContentSize().height / 2 - 190 });
    secondaryColorsMenu->alignItemsHorizontallyWithPadding(15);
    this->addChild(secondaryColorsMenu);


    this->m_nSelectedCube = GM->getVariable<int>("player-cube") - 1;
    this->m_nSelectedMC = GM->getVariable<int>("player-main-color");
    this->m_nSelectedSC = GM->getVariable<int>("player-secondary-color");
    this->m_pSelectionFrame = Sprite::createWithSpriteFrameName("GJ_select_001.png");
    this->m_pSelectionFrame2 = Sprite::createWithSpriteFrameName("GJ_select_001.png");
    this->m_pSelectionFrame3 = Sprite::createWithSpriteFrameName("GJ_select_001.png");

    if (this->m_nSelectedMC < 0) {
        this->m_nSelectedMC++;
    }
    if (this->m_nSelectedCube < 0) {
        this->m_nSelectedCube++;
    }
    if (this->m_nSelectedSC < 0) {
        this->m_nSelectedSC++;
    }

    this->addChild(this->m_pSelectionFrame);
    this->addChild(this->m_pSelectionFrame2);
    this->addChild(this->m_pSelectionFrame3);

    this->m_pSelectionFrame->setPosition(iconsMenu->convertToWorldSpace(iconsMenu->getChildren().at(m_nSelectedCube)->getPosition()));

    this->m_pSelectionFrame2->setPositionX(colorsMenu->getPositionX() + colorsMenu->getChildren().at(m_nSelectedMC)->getPositionX());
    this->m_pSelectionFrame3->setPositionX(secondaryColorsMenu->getPositionX() + secondaryColorsMenu->getChildren().at(m_nSelectedSC)->getPositionX());

    this->m_pSelectionFrame2->setScale(0.95f);
    this->m_pSelectionFrame3->setScale(0.95f);

    this->m_pSelectionFrame2->setPositionY(square->getPositionY() - square->getContentSize().height / 2 - 125);
    this->m_pSelectionFrame3->setPositionY(square->getPositionY() - square->getContentSize().height / 2 - 190);

    auto backBtn = MenuItemSpriteExtra::create("GJ_arrow_03_001.png", [&](Node* btn) {
        GM->setVariable("player-username", this->m_pUsernamefield->getString());
        Director::getInstance()->replaceScene(TransitionFade::create(0.5f, MenuLayer::scene()));
    });
	
	auto paletteBtn = MenuItemSpriteExtra::create("GJ_arrow_03_001.png", [&](Node* btn) {
       ColoursPalette::create(this)->show();
    });
    
    auto menu = Menu::create(backBtn, nullptr);
    this->addChild(menu);
    backBtn->setPosition(menu->convertToNodeSpace({48, winSize.height - 46}));
    //paletteBtn->setPosition(menu->convertToNodeSpace({48, winSize.height - 146}));

    return true;
}