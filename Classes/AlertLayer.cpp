#include "AlertLayer.h"
#include "ui/CocosGUI.h"

void AlertLayer::showLayer(bool instant) {
    this->stopAllActions();
    auto winSize = Director::getInstance()->getWinSize();

    if (instant) {
        this->m_pMainLayer->setPosition(this->m_eEndPos);
        this->m_pBGLayer->setOpacity(175);
    }
    else {
        this->m_pBGLayer->setOpacity(0);
        this->m_pBGLayer->runAction(FadeTo::create(0.05f, 175));
    }
} 

void AlertLayer::hideLayer(bool instant, bool removeFromParent) {
    this->stopAllActions();

    if (instant) {
        this->m_pMainLayer->setPosition(this->m_eEndPos);
        this->m_pBGLayer->setOpacity(0);
        if (this->getParent())
            this->removeFromParent();
    } else {
        this->m_pMainLayer->runAction(EaseInOut::create(MoveTo::create(0.5f, this->m_eEndPos), 2.0));
        this->m_pBGLayer->runAction(FadeTo::create(0.5f, 0));
        this->runAction(Sequence::create(DelayTime::create(0.5f), CallFunc::create([&]() {
            if (this->getParent())
                this->removeFromParent();
        }), nullptr));
    }
} 


void AlertLayer::close(Ref* sender, cocos2d::ui::Widget::TouchEventType type) {

    //this->garageLayer->updatePlayerColors();
    int t = static_cast<int>(type);
    log_ << "TouchEventType: " << t;

    switch (type) {
    case cocos2d::ui::Widget::TouchEventType::ENDED:
    {
        AlertLayer::popupOpen = false;
        this->removeFromParentAndCleanup(true);
    }
    }
}

bool AlertLayer::init(const char* title, float height) {
    if (!Layer::init()) return false;
    
    auto winSize = Director::getInstance()->getWinSize();

    this->m_eStartPos = {0, 0};
    this->m_eEndPos = {-650, 200};
    
    this->m_pBGLayer = LayerColor::create({ 0, 0, 0, 125 });
    m_pBGLayer->setContentSize(winSize);
    this->addChild(m_pBGLayer);

    this->m_pMainLayer = Layer::create();
    this->addChild(m_pMainLayer);

    this->m_pButtonsMenu = Menu::create();
    this->m_pMainLayer->addChild(m_pButtonsMenu);

    /*auto exitBtn = MenuItemSpriteExtra::create("GJ_arrow_03_001.png", [&](Node*) {
        this->hideLayer(false, true);
        // do some layer removing here
        // if (this->getParent())
        //     this->removeFromParent();
    });
    exitBtn->setScale(0.0f);
    this->m_pButtonsMenu->addChild(exitBtn);
    exitBtn->setPosition(100, 100);
    
    exitBtn->runAction(EaseBackOut::create((ScaleTo::create(0.5, 1.0))));
    */

    /*auto tableBottom = Sprite::createWithSpriteFrameName("GJ_table_bottom_001.png");
	this->m_pMainLayer->addChild(tableBottom);
    tableBottom->setAnchorPoint({ 0.5, 0.0 });
    tableBottom->setScale(1.18f);
    tableBottom->setPosition({ winSize.width / 2 , height -210});
    */

    auto btntest = ui::Button::create("GJ_button_01.png");
    btntest->setScale9Enabled(true);
    btntest->setContentSize({ 100, 60 });
    btntest->setPosition({ 650, -290 });
    btntest->setScale(0.5, 0.5);
    btntest->setTitleAlignment(TextHAlignment::CENTER, TextVAlignment::CENTER);
    btntest->setTitleFontName("goldFont.fnt");
    btntest->setTitleText("OK");
    btntest->setLocalZOrder(1000);
    this->m_pButtonsMenu->addChild(btntest);
    btntest->addTouchEventListener(CC_CALLBACK_2(AlertLayer::close, this));
    btntest->runAction(EaseBackOut::create((ScaleTo::create(0.25f, 1.0, 1.0))));

    auto square = ui::Scale9Sprite::create("square01_001.png");
    square->setAnchorPoint({ 0.5, 1 });
    square->setPosition({650, -50});
    square->setContentSize({760, 300});
    square->setScaleX(0.5);
    square->setScaleY(0.5);
    square->setOpacity(255);
    this->m_pButtonsMenu->addChild(square);
    square->runAction(EaseBackOut::create((ScaleTo::create(0.25f, 1.0, 1.0))));

    auto lockedtxt = ui::TextField::create("Locked", "goldFont.fnt", 48);
    lockedtxt->setMaxLength(20);
    lockedtxt->setPlaceHolderColor({ 120, 170, 240 });
    lockedtxt->setScale(0.6, 0.6);
    lockedtxt->setOpacity(255);
    //usernamefield->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
    //    std::cout << usernamefield->getString() << std::endl;
    //});
    lockedtxt->setPosition({ winSize.width / 2, winSize.height - (float)(winSize.height / 8 + 180) });
    this->addChild(lockedtxt);

    lockedtxt->runAction(EaseBackOut::create((ScaleTo::create(0.25f, 1.0, 1.0))));

    auto customtxt = ui::TextField::create("   Complete Stereo Madness in\nNormal mode to unlock this icon!", "chatFont.fnt", 48);
    customtxt->setMaxLength(20);
    customtxt->setPlaceHolderColor({ 255, 255, 255 });
    customtxt->setScale(0.4, 0.4);
    customtxt->setOpacity(255);
    //usernamefield->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
    //    std::cout << usernamefield->getString() << std::endl;
    //});
    customtxt->setPosition({ winSize.width / 2, winSize.height - (float)(winSize.height / 8 + 270) });
    this->addChild(customtxt);

    customtxt->runAction(EaseBackOut::create((ScaleTo::create(0.25f, 1.0, 1.0))));

    this->setup();

    this->hideLayer(true, false);

    return true;
}


AlertLayer* AlertLayer::create(const char* title, float height) {
    AlertLayer* pRet = new(std::nothrow) AlertLayer();

    if (pRet && pRet->init(title, height)) {
        pRet->autorelease();
        return pRet;
    } else {
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
}