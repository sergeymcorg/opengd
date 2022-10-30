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
    auto background = Sprite::create("GJ_gradientBG.png");
    auto winSize = Director::getInstance()->getWinSize();
    auto size = background->getContentSize();

    background->setScaleX(winSize.width / size.width);
    background->setScaleY(winSize.height / size.height);
    background->setAnchorPoint({0, 0});
    background->setColor({175, 175, 175});
    this->addChild(background);

    auto leftcorner = Sprite::createWithSpriteFrameName("GJ_sideArt_001.png");
    leftcorner->setPosition({leftcorner->getContentSize().width, winSize.height});
    leftcorner->setAnchorPoint({1, 1});
    leftcorner->setFlippedY(true);
    this->addChild(leftcorner);

    auto rightcorner = Sprite::createWithSpriteFrameName("GJ_sideArt_001.png");
    rightcorner->setPosition({winSize.width - rightcorner->getContentSize().width, winSize.height});
    rightcorner->setAnchorPoint({0, 1});
    rightcorner->setFlippedY(true);
    rightcorner->setFlippedX(true);
    this->addChild(rightcorner); 

    auto usernamefield = ui::TextField::create("Player", "bigFont.fnt", 48);
    usernamefield->setMaxLength(20);
    usernamefield->setPlaceHolderColor({120, 170, 240});
    //usernamefield->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
    //    //std::cout << usernamefield->getString() << std::endl;
    //});
    usernamefield->setPosition({winSize.width / 2, winSize.height - (float)(winSize.height / 8)});
    this->addChild(usernamefield);

    auto floor = Sprite::create("floor.png");
    floor->setPosition({winSize.width / 2, (winSize.height / 2) + 10});
    this->addChild(floor);

    // auto playerobj = PlayerObject::create(currentcube, this);
    auto playerobj = SimplePlayer::create(currentcube);
    playerobj->setPosition({winSize.width / 2, floor->getPosition().y + floor->getContentSize().height});
    playerobj->setAnchorPoint({0.5, -1});
    playerobj->m_pMainSprite->setColor(colors[this->currentFirstColor]);
    playerobj->m_pSecondarySprite->setColor(colors[this->currentSecondColor]);
    this->addChild(playerobj);
	
    auto square = ui::Scale9Sprite::create("square02_001.png");
    square->setAnchorPoint({0.5, 1});
    square->setPosition({winSize.width / 2, (winSize.height / 2) - 10});
    square->setContentSize({winSize.width - (float)(winSize.width / 3.7), 100});
    square->setOpacity(75);
    this->addChild(square);

    auto hint = Sprite::createWithSpriteFrameName("GJ_unlockTxt_001.png");
    hint->setPosition({square->getPosition().x + (float)(square->getContentSize().width / 3), square->getPosition().y});
    this->addChild(hint);
    
    auto iconsmenu = Menu::create();
    
    for(int i = 0; i < this->cubescount; i++){
        log_ << i;
		
		auto sprStr1 = StringUtils::format("player_%02d_001.png", i);
		auto sprStr2 = StringUtils::format("player_%02d_2_001.png", i);
		
		auto sprite1 = Sprite::createWithSpriteFrameName(sprStr1);
		auto sprite2 = Sprite::createWithSpriteFrameName(sprStr2);
	
        auto node = Node::create();
        if(sprite1 && sprite2) {
            node->addChild(sprite1);
            sprite2->setColor({255, 255, 255});
            sprite1->setColor({158, 158, 158});
            node->addChild(sprite2);
        }
        auto menuitem = MenuItemSpriteExtra::createWithNode(node,  [&](Node* btn) {
            log_ << "cube clicked";
        });
        iconsmenu->addChild(menuitem);
    }
    iconsmenu->setAnchorPoint({0.5, 1});
    iconsmenu->setPosition({winSize.width / 2 - 40, (winSize.height / 2) - 60});
    iconsmenu->alignItemsHorizontallyWithPadding(75);
    this->addChild(iconsmenu);
    
  

    auto backbtn = MenuItemSpriteExtra::create("GJ_arrow_03_001.png", [&](Node* btn) {
        Director::getInstance()->replaceScene(TransitionFade::create(0.5f, MenuLayer::scene()));
    });
	
	auto paletteBtn = MenuItemSpriteExtra::create("GJ_arrow_03_001.png", [&](Node* btn) {
        ColoursPalette::create(this)->show();
    });
	paletteBtn->setPositionY(paletteBtn->getPositionY() - 150);


    auto menu = Menu::create(backbtn, paletteBtn, nullptr);
    menu->setPosition({50, winSize.height - 50});
    addChild(menu);

    return true;
}