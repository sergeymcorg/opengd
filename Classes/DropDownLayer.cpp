#include "DropDownLayer.h"

void DropDownLayer::showLayer(bool instant) {
    this->stopAllActions();

    if (instant) {
        this->m_pMainLayer->setPosition(this->m_eStartPos);
        this->m_pBGLayer->setOpacity(125);
    } else {
        this->m_pMainLayer->runAction(EaseInOut::create(MoveTo::create(0.5f, this->m_eStartPos), 2.0));
        this->m_pBGLayer->setOpacity(0);
        this->m_pBGLayer->runAction(FadeTo::create(0.5f, 125));
    }
}

bool DropDownLayer::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
    log_ << "touch began";
    return true;
}

Menu* DropDownLayer::getButtonsMenu()
{
    return this->m_pButtonsMenu;
}

Layer* DropDownLayer::getMainLayer()
{
    return this->m_pMainLayer;
}

void DropDownLayer::hideLayer(bool instant, bool removeFromParent) {
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

bool DropDownLayer::init() {
    if (!Layer::init()) return false;
    
    auto winSize = Director::getInstance()->getWinSize();

    this->m_eStartPos = {0, 0};
    this->m_eEndPos = {0, winSize.height};
    
    this->m_pBGLayer = LayerColor::create({ 0, 0, 0, 125 });
    m_pBGLayer->setContentSize(winSize);
    this->addChild(m_pBGLayer);

    this->m_pMainLayer = Layer::create();
    this->addChild(m_pMainLayer);

    this->m_pButtonsMenu = Menu::create();
    this->m_pMainLayer->addChild(m_pButtonsMenu);

    auto exitBtn = MenuItemSpriteExtra::create("GJ_arrow_03_001.png", [&](Node*) {
        this->hideLayer(false, true);
        // do some layer removing here
        // if (this->getParent())
        //     this->removeFromParent();
    });
    exitBtn->setNewScale(1.6f);
    this->m_pButtonsMenu->addChild(exitBtn);
    exitBtn->setPosition(m_pButtonsMenu->convertToNodeSpace({48, winSize.height - 46}));

    setup();

    this->hideLayer(true, false);

    // set up listener 

    auto dir = Director::getInstance();


    auto listener = EventListenerTouchOneByOne::create();

    listener->setEnabled(true);
    listener->setSwallowTouches(true);


    // trigger when you start touch
    listener->onTouchBegan = CC_CALLBACK_2(DropDownLayer::onTouchBegan, this);


    dir->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);


    return true;
}