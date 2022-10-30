#include "SimplePlayer.h"

bool SimplePlayer::init(int cubeID) {
    if (!Sprite::init()) return false;

    cubeID = inRange(cubeID, 1, 13);

    auto mainFrame = StringUtils::format("player_%02d_001.png", cubeID);
    auto secFrame = StringUtils::format("player_%02d_2_001.png", cubeID);

    this->m_pMainSprite = Sprite::createWithSpriteFrameName(mainFrame);
    this->addChild(m_pMainSprite);
    m_pMainSprite->setAnchorPoint({0, 0});
    
    this->m_pSecondarySprite = Sprite::createWithSpriteFrameName(secFrame);
    this->addChild(m_pSecondarySprite, -1);
    m_pSecondarySprite->setPosition(this->m_pMainSprite->getContentSize() / 2);

    this->setContentSize({60, 60});

    return true;
}

void SimplePlayer::setMainColor(Color3B col) {
    this->m_pMainSprite->setColor(col);
}

void SimplePlayer::setSecondaryColor(Color3B col) {
    this->m_pSecondarySprite->setColor(col);
}

SimplePlayer* SimplePlayer::create(int cubeID) {
    auto pRet = new (std::nothrow) SimplePlayer();

    if(pRet && pRet->init(cubeID)) {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return pRet;
}