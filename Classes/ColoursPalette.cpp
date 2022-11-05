#include "ColoursPalette.h"
#include "ui/CocosGUI.h"

//TODO: SimplePlayer, port this to cocos 4 

void ColoursPalette::onColorClick(Ref *sender)
{
	/*
    CCMenuItemSpriteExtra *obj = (CCMenuItemSpriteExtra *)sender;
    if (colorType == 1)
    {
        GameManager::sharedState()->setPlayerColor2(obj->getTag());
        this->cubeIcon->setSecondColor(GameManager::sharedState()->colorForIdx(obj->getTag()));
        this->shipIcon->setSecondColor(GameManager::sharedState()->colorForIdx(obj->getTag()));
        this->ballIcon->setSecondColor(GameManager::sharedState()->colorForIdx(obj->getTag()));
        this->birdIcon->setSecondColor(GameManager::sharedState()->colorForIdx(obj->getTag()));
        this->dartIcon->setSecondColor(GameManager::sharedState()->colorForIdx(obj->getTag()));
        this->robotIcon->setSecondColor(GameManager::sharedState()->colorForIdx(obj->getTag()));
        this->spiderIcon->setSecondColor(GameManager::sharedState()->colorForIdx(obj->getTag()));
        this->swingIcon->setSecondColor(GameManager::sharedState()->colorForIdx(obj->getTag()));
        this->color2Selector->setPosition(ccp(obj->getPositionX(), obj->getPositionY()));
    }
    else
    {
        GameManager::sharedState()->setPlayerColor(obj->getTag());
        this->cubeIcon->setColor(GameManager::sharedState()->colorForIdx(obj->getTag()));
        this->shipIcon->setColor(GameManager::sharedState()->colorForIdx(obj->getTag()));
        this->ballIcon->setColor(GameManager::sharedState()->colorForIdx(obj->getTag()));
        this->birdIcon->setColor(GameManager::sharedState()->colorForIdx(obj->getTag()));
        this->dartIcon->setColor(GameManager::sharedState()->colorForIdx(obj->getTag()));
        this->robotIcon->setColor(GameManager::sharedState()->colorForIdx(obj->getTag()));
        this->spiderIcon->setColor(GameManager::sharedState()->colorForIdx(obj->getTag()));
        this->swingIcon->setColor(GameManager::sharedState()->colorForIdx(obj->getTag()));
        this->color1Selector->setPosition(ccp(obj->getPositionX(), obj->getPositionY()));
    }
	*/
}

void ColoursPalette::onColor1Click(Ref *sender)
{
	/*
    CCMenuItemSpriteExtra *obj = (CCMenuItemSpriteExtra *)sender;

    this->colorType = 0;

    this->clr1Btn->setNormalImage(
        ButtonSprite::create("Col1", 30, 10, 10, 1, "bigFont.fnt", "GJ_button_01.png", 20));
    this->clr1Btn->setSelectedImage(
        ButtonSprite::create("Col1", 30, 10, 10, 1, "bigFont.fnt", "GJ_button_01.png", 20));
    this->clr2Btn->setNormalImage(
        ButtonSprite::create("Col2", 30, 10, 10, 1, "bigFont.fnt", "GJ_button_04.png", 20));
    this->clr2Btn->setSelectedImage(
        ButtonSprite::create("Col2", 30, 10, 10, 1, "bigFont.fnt", "GJ_button_04.png", 20));

    if (this->color2Selector != nullptr)
    {
        this->color2Selector->setColor(ccc3(51, 56, 52));
    }
    if (this->color1Selector != nullptr)
    {
        this->color1Selector->setColor(ccc3(255, 255, 255));
    }
	*/
}
void ColoursPalette::onColor2Click(Ref *sender)
{
	/*
    CCMenuItemSpriteExtra *obj = (CCMenuItemSpriteExtra *)sender;

    this->colorType = 1;

    this->clr1Btn->setNormalImage(
        ButtonSprite::create("Col1", 30, 10, 10, 1, "bigFont.fnt", "GJ_button_04.png", 20));
    this->clr1Btn->setSelectedImage(
        ButtonSprite::create("Col1", 30, 10, 10, 1, "bigFont.fnt", "GJ_button_04.png", 20));
    this->clr2Btn->setNormalImage(
        ButtonSprite::create("Col2", 30, 10, 10, 1, "bigFont.fnt", "GJ_button_01.png", 20));
    this->clr2Btn->setSelectedImage(
        ButtonSprite::create("Col2", 30, 10, 10, 1, "bigFont.fnt", "GJ_button_01.png", 20));
    if (this->color1Selector != nullptr)
    {
        this->color1Selector->setColor(ccc3(51, 56, 52));
    }
    if (this->color2Selector != nullptr)
    {
        this->color2Selector->setColor(ccc3(255, 255, 255));
    }
	*/
}
void ColoursPalette::onGlow(Ref *sender)
{
	/*
    CCMenuItemSpriteExtra *obj = (CCMenuItemSpriteExtra *)sender;
    this->glow = !this->glow;
    auto gm = GameManager::sharedState();
    gm->m_bPlayerGlow = this->glow;

    extern bool userDataChanged;
    userDataChanged = true;

    if (this->glow)
    {
        obj->setNormalImage(
            ButtonSprite::create("Glow", 30, 10, 10, 1, "bigFont.fnt", "GJ_button_01.png", 20));
        obj->setSelectedImage(
            ButtonSprite::create("Glow", 30, 10, 10, 1, "bigFont.fnt", "GJ_button_01.png", 20));
    }
    else
    {
        obj->setNormalImage(
            ButtonSprite::create("Glow", 30, 10, 10, 1, "bigFont.fnt", "GJ_button_04.png", 20));
        obj->setSelectedImage(
            ButtonSprite::create("Glow", 30, 10, 10, 1, "bigFont.fnt", "GJ_button_04.png", 20));
    }

    {
        this->cubeIcon->setPlayerGlow(this->glow);
        this->cubeIcon->updateColors();

        this->shipIcon->setPlayerGlow(this->glow);
        this->shipIcon->updateColors();

        this->ballIcon->setPlayerGlow(this->glow);
        this->ballIcon->updateColors();

        this->birdIcon->setPlayerGlow(this->glow);
        this->birdIcon->updateColors();

        this->dartIcon->setPlayerGlow(this->glow);
        this->dartIcon->updateColors();

        this->robotIcon->setPlayerGlow(this->glow);
        this->robotIcon->updateColors();

        this->spiderIcon->setPlayerGlow(this->glow);
        this->spiderIcon->updateColors();

        this->swingIcon->setPlayerGlow(this->glow);
        this->swingIcon->updateColors();
    }
	*/
}

void ColoursPalette::addColorButton(Menu *father, float posX, float posY, int id)
{
	/*
    auto sprite = Sprite::createWithSpriteFrameName("GJ_colorBtn_001.png");
    sprite->setColor(GameManager::sharedState()->colorForIdx(id));
    sprite->setScale(0.62);
    auto btn = CCMenuItemSpriteExtra::create(
        sprite,
        sprite,
        this,
        static_cast<cocos2d::SEL_MenuHandler>(&ColoursPalette::onColorClick));
    btn->setPosition(posX, posY);
    btn->setTag(id);
    father->addChild(btn);

    auto gm = GameManager::sharedState();
    int color2 = gm->m_nPlayerColor2;
    int color1 = gm->m_nPlayerColor;

    if (color2 == id)
    {
        this->color2Selector = cocos2d::CCSprite::createWithSpriteFrameName("GJ_select_001.png");
        father->addChild(this->color2Selector);
        this->color2Selector->setPosition(ccp(posX, posY));
        this->color2Selector->setColor(ccc3(51, 56, 52));
        this->color2Selector->setScale(0.7);
    }

    if (color1 == id)
    {
        this->color1Selector = cocos2d::CCSprite::createWithSpriteFrameName("GJ_select_001.png");
        father->addChild(this->color1Selector);
        this->color1Selector->setPosition(ccp(posX, posY));
        this->color1Selector->setScale(0.7);
    }
	*/
}

//random game i found with new cocos examples
//https://github.com/ff78/buyu_simple/blob/ee1e98afe88624ef155b066225b121891eaeeda1/frameworks/runtime-src/Classes/view/gameLayers/GameUILayer.cpp

void ColoursPalette::close(Ref* sender, cocos2d::ui::Widget::TouchEventType type) {
	
	switch (type) {
		case cocos2d::ui::Widget::TouchEventType::ENDED:
        {
			ColoursPalette::popupOpen = false;
			this->removeFromParentAndCleanup(true);       
        }
	}

}
	
bool ColoursPalette::init(GarageLayer *t_garagelayer)
{

	if(!PopupLayer::init())
		return false;
	
    this->garageLayer = t_garagelayer;
    auto dir = Director::getInstance();

    auto win_size = dir->getWinSize();
	auto winSize = win_size;
	
    auto background = ui::Scale9Sprite::create("GJ_square01.png");
		
	constexpr float multiplier = 2.1f;
    background->setContentSize(Size(450.0f * multiplier, 300.0f * multiplier));
		
    background->setPosition(win_size.width / 2, win_size.height / 2);
    this->m_pMainLayer->addChild(background);
		
	auto btntest = ui::Button::create("GJ_button_01.png");
	btntest->setScale9Enabled(true);
	btntest->setContentSize({100, 60});
	btntest->setTitleAlignment(TextHAlignment::CENTER, TextVAlignment::CENTER);
	btntest->setTitleFontName("goldFont.fnt");
	btntest->setTitleText("OK");

    btntest->addTouchEventListener(CC_CALLBACK_2(ColoursPalette::close, this));

	btntest->setPosition({winSize.width / 2, winSize.height / 2});
	m_pMainLayer->addChild(btntest);
		
		/*
        auto col2 = ButtonSprite::create("Col2", 30, 10, 10, 1, "bigFont.fnt", "GJ_button_04.png", 20);
        auto color_menu = CCMenu::create();
        {
            auto col1 = ButtonSprite::create("Col1", 30, 10, 10, 1, "bigFont.fnt", "GJ_button_01.png", 20);
            this->clr1Btn = CCMenuItemSpriteExtra::create(
                col1,
                nullptr,
                this,
                static_cast<cocos2d::SEL_MenuHandler>(&ColoursPalette::onColor1Click));

            color_menu->addChild(this->clr1Btn);
            this->clr1Btn->setPosition(80.0f, 130.0f);
        }
        {
            auto col1 = ButtonSprite::create("Col2", 30, 10, 10, 1, "bigFont.fnt", "GJ_button_04.png", 20);
            this->clr2Btn = CCMenuItemSpriteExtra::create(
                col1,
                nullptr,
                this,
                static_cast<cocos2d::SEL_MenuHandler>(&ColoursPalette::onColor2Click));

            color_menu->addChild(this->clr2Btn);
            this->clr2Btn->setPosition(130.0f, 130.0f);
        }
        auto gm = GameManager::sharedState();
        int color2 = gm->m_nPlayerColor2;
        int color1 = gm->m_nPlayerColor;
        int cubeId = gm->m_nPlayerFrame;
        int shipId = gm->m_nPlayerShip;
        int ballId = gm->m_nPlayerBall;
        int birdId = gm->m_nPlayerBird;
        int dartId = gm->m_nPlayerDart;
        int robotId = gm->m_nPlayerRobot;
        int spiderId = gm->m_nPlayerSpider;
        int swingId = gm->m_nPlayerSwing;

        int hasGlow = gm->m_bPlayerGlow;

        {
            auto col1 = (hasGlow) ? ButtonSprite::create("Glow", 30, 10, 10, 1, "bigFont.fnt", "GJ_button_01.png", 20) : ButtonSprite::create("Glow", 30, 10, 10, 1, "bigFont.fnt", "GJ_button_04.png", 20);
            this->glow = hasGlow;

            auto btn = CCMenuItemSpriteExtra::create(
                col1,
                nullptr,
                this,
                static_cast<cocos2d::SEL_MenuHandler>(&ColoursPalette::onGlow));

            color_menu->addChild(btn);
            btn->setPosition(180.0f, 130.0f);
        }
        this->m_pLayer->addChild(color_menu);
		
        auto close_btn_menu = Menu::create();
        this->m_pLayer->addChild(close_btn_menu);
        auto close_btn_sprite = Sprite::createWithSpriteFrameName("GJ_closeBtn_001.png");
        close_btn_sprite->setScale(0.7);
        auto close_btn = CCMenuItemSpriteExtra::create(
            close_btn_sprite,
            nullptr,
            this,
            static_cast<cocos2d::SEL_MenuHandler>(&ColoursPalette::onClose));

        close_btn_menu->addChild(close_btn);
        close_btn->setPosition(-210.0f, 140.0f);

        this->m_pLayer->addChild(close_btn_menu);
		*/
        auto icons_bg = ui::Scale9Sprite::create("square02_001.png");
        icons_bg->setContentSize(Size(415.0f * multiplier, 55.0f * multiplier));
        icons_bg->setOpacity(50);
        icons_bg->setPosition(win_size.width / 2, win_size.height / 2 + (90 * multiplier));
        this->m_pMainLayer->addChild(icons_bg);
		
		/*

        float current_icon_position = 0;
        float position_addition = 52;
        auto player_node = CCNode::create();
        player_node->setPosition(win_size.width / 2 - 183, win_size.height / 2 + 90);
        this->m_pLayer->addChild(player_node);

        {
            this->cubeIcon = SimplePlayer::create(cubeId);
            this->cubeIcon->updatePlayerFrame(cubeId, IconType::Player);
            this->cubeIcon->setPositionX(current_icon_position);
            this->cubeIcon->setPositionY(0.0f);
            this->cubeIcon->setSecondColor(GameManager::sharedState()->colorForIdx(color2));
            this->cubeIcon->setColor(GameManager::sharedState()->colorForIdx(color1));
            this->cubeIcon->setPlayerGlow(hasGlow);
            this->cubeIcon->updateColors();
            current_icon_position += position_addition;
            player_node->addChild(this->cubeIcon);
        }
        {
            this->shipIcon = SimplePlayer::create(shipId);
            this->shipIcon->updatePlayerFrame(shipId, IconType::Ship);
            this->shipIcon->setPositionX(current_icon_position);
            this->shipIcon->setPositionY(0.0f);
            this->shipIcon->setSecondColor(GameManager::sharedState()->colorForIdx(color2));
            this->shipIcon->setColor(GameManager::sharedState()->colorForIdx(color1));
            this->shipIcon->setPlayerGlow(hasGlow);
            this->shipIcon->updateColors();
            current_icon_position += position_addition;
            player_node->addChild(this->shipIcon);
        }
        {
            this->ballIcon = SimplePlayer::create(ballId);
            this->ballIcon->updatePlayerFrame(ballId, IconType::Ball);
            this->ballIcon->setPositionX(current_icon_position);
            this->ballIcon->setPositionY(0.0f);
            this->ballIcon->setSecondColor(GameManager::sharedState()->colorForIdx(color2));
            this->ballIcon->setColor(GameManager::sharedState()->colorForIdx(color1));
            this->ballIcon->setPlayerGlow(hasGlow);
            this->ballIcon->updateColors();
            current_icon_position += position_addition;
            player_node->addChild(this->ballIcon);
        }
        {
            this->birdIcon = SimplePlayer::create(birdId);
            this->birdIcon->updatePlayerFrame(birdId, IconType::Bird);
            this->birdIcon->setPositionX(current_icon_position);
            this->birdIcon->setPositionY(0.0f);
            this->birdIcon->setSecondColor(GameManager::sharedState()->colorForIdx(color2));
            this->birdIcon->setColor(GameManager::sharedState()->colorForIdx(color1));
            this->birdIcon->setPlayerGlow(hasGlow);
            this->birdIcon->updateColors();
            current_icon_position += position_addition;
            player_node->addChild(this->birdIcon);
        }
        {
            this->dartIcon = SimplePlayer::create(dartId);
            this->dartIcon->updatePlayerFrame(dartId, IconType::Dart);
            this->dartIcon->setPositionX(current_icon_position);
            this->dartIcon->setPositionY(0.0f);
            this->dartIcon->setSecondColor(GameManager::sharedState()->colorForIdx(color2));
            this->dartIcon->setColor(GameManager::sharedState()->colorForIdx(color1));
            this->dartIcon->setPlayerGlow(hasGlow);
            this->dartIcon->updateColors();
            current_icon_position += position_addition;
            player_node->addChild(this->dartIcon);
        }
        {
            this->robotIcon = SimplePlayer::create(robotId);
            this->robotIcon->updatePlayerFrame(robotId, IconType::Robot);
            this->robotIcon->setPositionX(current_icon_position);
            this->robotIcon->setPositionY(0.0f);
            this->robotIcon->setSecondColor(GameManager::sharedState()->colorForIdx(color2));
            this->robotIcon->setColor(GameManager::sharedState()->colorForIdx(color1));
            this->robotIcon->setPlayerGlow(hasGlow);
            this->robotIcon->updateColors();
            current_icon_position += position_addition;
            player_node->addChild(this->robotIcon);
        }
        {
            this->spiderIcon = SimplePlayer::create(spiderId);
            this->spiderIcon->updatePlayerFrame(spiderId, IconType::Spider);
            this->spiderIcon->setPositionX(current_icon_position);
            this->spiderIcon->setPositionY(0.0f);
            this->spiderIcon->setSecondColor(GameManager::sharedState()->colorForIdx(color2));
            this->spiderIcon->setColor(GameManager::sharedState()->colorForIdx(color1));
            this->spiderIcon->setPlayerGlow(hasGlow);
            this->spiderIcon->updateColors();
            current_icon_position += position_addition;
            player_node->addChild(this->spiderIcon);
        }
        {
            this->swingIcon = SimplePlayer::create(swingId);
            this->swingIcon->updatePlayerFrame(swingId, IconType::Swing);
            this->swingIcon->setPositionX(current_icon_position);
            this->swingIcon->setPositionY(0.0f);
            this->swingIcon->setSecondColor(GameManager::sharedState()->colorForIdx(color2));
            this->swingIcon->setColor(GameManager::sharedState()->colorForIdx(color1));
            this->swingIcon->setPlayerGlow(hasGlow);
            this->swingIcon->updateColors();
            current_icon_position += position_addition;
            player_node->addChild(this->swingIcon);
        }

        {

            auto close_btn_menu = cocos2d::CCMenu::create();
            this->m_pLayer->addChild(close_btn_menu);

            // first column
            {
                float startX = -195;
                float startY = 45;

                this->addColorButton(close_btn_menu, startX, startY, 42);
                this->addColorButton(close_btn_menu, startX + 25, startY, 19);
                this->addColorButton(close_btn_menu, startX + 50, startY, 43);
                this->addColorButton(close_btn_menu, startX + 75, startY, 9);

                this->addColorButton(close_btn_menu, startX, startY - 26, 37);
                this->addColorButton(close_btn_menu, startX + 25, startY - 26, 43);
                this->addColorButton(close_btn_menu, startX + 50, startY - 26, 44);
                this->addColorButton(close_btn_menu, startX + 75, startY - 26, 45);

                this->addColorButton(close_btn_menu, startX, startY - 52, 25);
                this->addColorButton(close_btn_menu, startX + 25, startY - 52, 46);
                this->addColorButton(close_btn_menu, startX + 50, startY - 52, 47);
                this->addColorButton(close_btn_menu, startX + 75, startY - 52, 48);
            }

            {
                float startX = -195;
                float startY = -40;

                this->addColorButton(close_btn_menu, startX, startY, 49);
                this->addColorButton(close_btn_menu, startX + 25, startY, 50);
                this->addColorButton(close_btn_menu, startX + 50, startY, 51);
                this->addColorButton(close_btn_menu, startX + 75, startY, 3); // ok

                this->addColorButton(close_btn_menu, startX, startY - 26, 40); // ok
                this->addColorButton(close_btn_menu, startX + 25, startY - 26, 52);
                this->addColorButton(close_btn_menu, startX + 50, startY - 26, 53);
                this->addColorButton(close_btn_menu, startX + 75, startY - 26, 54);

                this->addColorButton(close_btn_menu, startX, startY - 52, 33);      // ok
                this->addColorButton(close_btn_menu, startX + 25, startY - 52, 21); // ok
                this->addColorButton(close_btn_menu, startX + 50, startY - 52, 55);
                this->addColorButton(close_btn_menu, startX + 75, startY - 52, 56);
            }

            // second column
            {
                float startX = -91;
                float startY = 45;

                this->addColorButton(close_btn_menu, startX, startY, 57);
                this->addColorButton(close_btn_menu, startX + 25, startY, 58);
                this->addColorButton(close_btn_menu, startX + 50, startY, 10); // ok
                this->addColorButton(close_btn_menu, startX + 75, startY, 29); // ok

                this->addColorButton(close_btn_menu, startX, startY - 26, 26); // ok
                this->addColorButton(close_btn_menu, startX + 25, startY - 26, 59);
                this->addColorButton(close_btn_menu, startX + 50, startY - 26, 60);
                this->addColorButton(close_btn_menu, startX + 75, startY - 26, 61);

                this->addColorButton(close_btn_menu, startX, startY - 52, 30); // ok
                this->addColorButton(close_btn_menu, startX + 25, startY - 52, 62);
                this->addColorButton(close_btn_menu, startX + 50, startY - 52, 63);
                this->addColorButton(close_btn_menu, startX + 75, startY - 52, 64);
            }

            {
                float startX = -91;
                float startY = -40;

                this->addColorButton(close_btn_menu, startX, startY, 65);
                this->addColorButton(close_btn_menu, startX + 25, startY, 16); // ok
                this->addColorButton(close_btn_menu, startX + 50, startY, 4);  // ok
                this->addColorButton(close_btn_menu, startX + 75, startY, 5);  // ok

                this->addColorButton(close_btn_menu, startX, startY - 26, 22);      // ok
                this->addColorButton(close_btn_menu, startX + 25, startY - 26, 39); // ok
                this->addColorButton(close_btn_menu, startX + 50, startY - 26, 103);
                this->addColorButton(close_btn_menu, startX + 75, startY - 26, 104);

                this->addColorButton(close_btn_menu, startX, startY - 52, 34); // ok
                this->addColorButton(close_btn_menu, startX + 25, startY - 52, 66);
                this->addColorButton(close_btn_menu, startX + 50, startY - 52, 67);
                this->addColorButton(close_btn_menu, startX + 75, startY - 52, 68);

                this->addColorButton(close_btn_menu, startX, startY - 78, 69);
                this->addColorButton(close_btn_menu, startX + 25, startY - 78, 70);
                this->addColorButton(close_btn_menu, startX + 50, startY - 78, 71);
                this->addColorButton(close_btn_menu, startX + 75, startY - 78, 72);
            }

            // third column
            {
                float startX = 15;
                float startY = 45;

                this->addColorButton(close_btn_menu, startX, startY, 73);
                this->addColorButton(close_btn_menu, startX + 25, startY, 74);
                this->addColorButton(close_btn_menu, startX + 50, startY, 11); // ok
                this->addColorButton(close_btn_menu, startX + 75, startY, 27); // ok

                this->addColorButton(close_btn_menu, startX, startY - 26, 75);
                this->addColorButton(close_btn_menu, startX + 25, startY - 26, 14); // ok
                this->addColorButton(close_btn_menu, startX + 50, startY - 26, 31); // ok
                this->addColorButton(close_btn_menu, startX + 75, startY - 26, 76);

                this->addColorButton(close_btn_menu, startX, startY - 52, 77);
                this->addColorButton(close_btn_menu, startX + 25, startY - 52, 78);
                this->addColorButton(close_btn_menu, startX + 50, startY - 52, 79);
                this->addColorButton(close_btn_menu, startX + 75, startY - 52, 80);
            }

            {
                float startX = 15;
                float startY = -40;

                this->addColorButton(close_btn_menu, startX, startY, 81);
                this->addColorButton(close_btn_menu, startX + 25, startY, 41); // ok
                this->addColorButton(close_btn_menu, startX + 50, startY, 6);  // ok
                this->addColorButton(close_btn_menu, startX + 75, startY, 35); // ok

                this->addColorButton(close_btn_menu, startX, startY - 26, 82);
                this->addColorButton(close_btn_menu, startX + 25, startY - 26, 23); // ok
                this->addColorButton(close_btn_menu, startX + 50, startY - 26, 83);
                this->addColorButton(close_btn_menu, startX + 75, startY - 26, 84);

                this->addColorButton(close_btn_menu, startX, startY - 52, 85);
                this->addColorButton(close_btn_menu, startX + 25, startY - 52, 86);
                this->addColorButton(close_btn_menu, startX + 50, startY - 52, 87);
                this->addColorButton(close_btn_menu, startX + 75, startY - 52, 88);
            }

            // fourth column
            {
                float startX = 120;
                float startY = 45;

                this->addColorButton(close_btn_menu, startX, startY, 89);
                this->addColorButton(close_btn_menu, startX + 25, startY, 90);
                this->addColorButton(close_btn_menu, startX + 50, startY, 0); // ok
                this->addColorButton(close_btn_menu, startX + 75, startY, 1); // ok

                this->addColorButton(close_btn_menu, startX, startY - 26, 91);
                this->addColorButton(close_btn_menu, startX + 25, startY - 26, 28); // ok
                this->addColorButton(close_btn_menu, startX + 50, startY - 26, 32); // ok
                this->addColorButton(close_btn_menu, startX + 75, startY - 26, 20); // ok

                this->addColorButton(close_btn_menu, startX, startY - 52, 2);       // ok
                this->addColorButton(close_btn_menu, startX + 25, startY - 52, 38); // ok
                this->addColorButton(close_btn_menu, startX + 50, startY - 52, 92);
                this->addColorButton(close_btn_menu, startX + 75, startY - 52, 93);
            }

            {
                float startX = 120;
                float startY = -40;

                this->addColorButton(close_btn_menu, startX, startY, 94);
                this->addColorButton(close_btn_menu, startX + 25, startY, 8);  // ok
                this->addColorButton(close_btn_menu, startX + 50, startY, 36); // ok
                this->addColorButton(close_btn_menu, startX + 75, startY, 105);

                this->addColorButton(close_btn_menu, startX, startY - 26, 7);       // ok
                this->addColorButton(close_btn_menu, startX + 25, startY - 26, 13); // ok
                this->addColorButton(close_btn_menu, startX + 50, startY - 26, 24); // ok
                this->addColorButton(close_btn_menu, startX + 75, startY - 26, 95);

                this->addColorButton(close_btn_menu, startX, startY - 52, 96);
                this->addColorButton(close_btn_menu, startX + 25, startY - 52, 97);
                this->addColorButton(close_btn_menu, startX + 50, startY - 52, 98);
                this->addColorButton(close_btn_menu, startX + 75, startY - 52, 99);
            }
            // last line
            {
                float startX = 45;
                float startY = -125;

                this->addColorButton(close_btn_menu, startX, startY, 12); // ok
                this->addColorButton(close_btn_menu, startX + 25, startY, 100);
                this->addColorButton(close_btn_menu, startX + 50, startY, 17); // ok
                this->addColorButton(close_btn_menu, startX + 75, startY, 101);
                this->addColorButton(close_btn_menu, startX + 100, startY, 18); // ok
                this->addColorButton(close_btn_menu, startX + 125, startY, 102);
                this->addColorButton(close_btn_menu, startX + 150, startY, 15); // ok
            }
            this->m_pLayer->addChild(close_btn_menu);
        }
		*/

    return true;
}