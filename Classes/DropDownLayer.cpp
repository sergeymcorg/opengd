#include "DropDownLayer.h"

void DropDownLayer::showLayer(bool instant) {
    this->stopAllActions();

    if (instant) {
        this->setPosition(this->m_eStartPos);
        this->m_pBGLayer->setOpacity(125);
    } else {
        this->runAction(EaseInOut::create(MoveTo::create(0.5f, this->m_eStartPos), 2.0));
        this->m_pBGLayer->setOpacity(0);
        this->m_pBGLayer->runAction(FadeTo::create(0.5f, 125));
    }
} 

void DropDownLayer::hideLayer(bool instant) {
    this->stopAllActions();

    if (instant) {
        this->setPosition(this->m_eEndPos);
        this->m_pBGLayer->setOpacity(0);
    } else {
        this->runAction(EaseInOut::create(MoveTo::create(0.5f, this->m_eEndPos), 2.0));
        this->m_pBGLayer->runAction(FadeTo::create(0.5f, 0));
    }
} 

bool DropDownLayer::init(const char* title, float height) {
    if (!Layer::init()) return false;
    
    auto winSize = Director::getInstance()->getWinSize();

    this->m_eStartPos = winSize / 2;
    this->m_eEndPos = {winSize.width / 2, winSize.height * 1.5f};
    
    this->m_pBGLayer = LayerColor::create({ 0, 0, 0, 125 });
    m_pBGLayer->setContentSize(winSize);
    this->addChild(m_pBGLayer);
    // this->m_pBGLayer->setPosition(this->convertToNodeSpace({0,0}));
    this->setPosition(winSize / 2);
    // this->m_pBGLayer->setPosition(winSize / 2);
    // this->setAnchorPoint({0,0});

    this->m_pButtonsMenu = Menu::create();

    auto exitBtn = MenuItemSpriteExtra::create("GJ_arrow_03_001.png", [&](Node*) {
        this->hideLayer(false);
    });
    exitBtn->setNewScale(1.6f);

    this->m_pButtonsMenu->addChild(exitBtn);
    exitBtn->setPosition(m_pButtonsMenu->convertToNodeSpace({48, winSize.height - 48}));

    auto chain1 = Sprite::createWithSpriteFrameName("chain_01_001.png");
	this->addChild(chain1);
	chain1->setAnchorPoint({ 0.5, 0.0 });
	chain1->setPosition({ winSize.width / 2 - 100, height });

	auto chain2 = Sprite::createWithSpriteFrameName("chain_01_001.png");
	this->addChild(chain2);
	chain2->setAnchorPoint({ 0.5, 0.0 });
	chain2->setPosition({ winSize.width / 2 + 100, height });

    this->setup();

    this->hideLayer(true);

    return true;
}

DropDownLayer* DropDownLayer::create(const char* title, float height) {
    DropDownLayer* pRet = new(std::nothrow) DropDownLayer();

    if (pRet && pRet->init(title, height)) {
        pRet->autorelease();
        return pRet;
    } else {
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
}