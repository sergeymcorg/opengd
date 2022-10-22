#include "MenuItemSpriteExtra.h"

MenuItemSpriteExtra::MenuItemSpriteExtra(const char* sprite, std::function<void(Node*)> callback) {
    this->m_pSprite = Sprite::createWithSpriteFrameName(sprite);
    this->m_fNewScale = 1.26f;
    this->m_fAnimDuration = 0.3f;
    this->m_fCallback = callback;
}

void MenuItemSpriteExtra::selected() {
    this->m_pSprite->runAction(EaseBounceOut::create(ScaleTo::create(m_fAnimDuration, m_fNewScale)));
}

void MenuItemSpriteExtra::unselected() {
    this->m_pSprite->stopAllActions();
    this->m_pSprite->runAction(EaseBounceOut::create(ScaleTo::create(m_fAnimDuration, 1.0f)));
}

void MenuItemSpriteExtra::activate() {
    this->m_pSprite->stopAllActions();
    this->m_pSprite->setScale(1.0f);
    this->m_fCallback(this);
}

bool MenuItemSpriteExtra::init() {
    if (!this->initWithNormalSprite(this->m_pSprite, this->m_pSprite, this->m_pSprite, nullptr)) return false;

    this->m_pSprite->setAnchorPoint({0.5, 0.5});
    this->m_pSprite->setPosition(this->m_pSprite->getContentSize() * 0.5f);

    return true;
}

MenuItemSpriteExtra* MenuItemSpriteExtra::create(const char* sprite, std::function<void(Node*)> callback) {
    MenuItemSpriteExtra* pRet = new(std::nothrow) MenuItemSpriteExtra(sprite, callback);

    if (pRet && pRet->init()) {
        pRet->autorelease();
        return pRet;
    } else {
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
}