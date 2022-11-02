#include "TextButton.h"

void TextButton::selected() {
    MenuItemSprite::selected();
    this->runAction(EaseBounceOut::create(ScaleTo::create(.3f, m_fNewScale)));
}

void TextButton::unselected() {
    MenuItemSprite::unselected();
    this->stopAllActions();
    this->runAction(EaseBounceOut::create(ScaleTo::create(0.3f, 1.0f)));
}

void TextButton::activate() {
    MenuItemSprite::activate();
    this->stopAllActions();
    this->setScale(1.0f);
    this->m_fCallback(this);
}

bool TextButton::init(string text, string font, float width, float height, string bgTexture, std::function<void(TextButton*)> callback) {
    if (!MenuItemSprite::initWithNormalSprite(nullptr, nullptr, nullptr, nullptr)) return false;

    this->m_pText = Label::createWithBMFont(font, text);

    this->m_pBG = ui::Scale9Sprite::create(bgTexture);
    this->m_pBG->setContentSize({
        (width == 0) ? this->m_pText->getContentSize().width + 32 : width,
        (height == 0) ? this->m_pText->getContentSize().height + 32 : height
    });
    this->addChild(this->m_pBG);
    this->m_pBG->setPosition(this->m_pBG->getContentSize() / 2);
    this->m_pBG->addChild(this->m_pText);

    this->m_pText->setPosition(this->m_pBG->getContentSize() / 2);

    this->setContentSize(this->m_pBG->getContentSize());

    this->setNewScale(1.25f);

    this->m_fCallback = callback;

    this->m_fWidth = width;
    this->m_fHeight = height;

    return true;
}


// Getters and Setters
void TextButton::setText(string text) {
    this->m_pText->setString(text);

    this->m_pBG->setContentSize({
        (this->m_fWidth == 0) ? this->m_pText->getContentSize().width + 32 : this->m_fWidth,
        (this->m_fHeight == 0) ? this->m_pText->getContentSize().height + 32 : this->m_fHeight
    });

    this->m_pText->setPosition(this->m_pBG->getContentSize() / 2);
}

Label* TextButton::getLabel()
{
    return this->m_pText;
}

ui::Scale9Sprite* TextButton::getBG()
{
    return this->m_pBG;
}

// Create funcs
#pragma region
TextButton* TextButton::create(string text, string font, float width, float height, string bgTexture, std::function<void(TextButton*)> callback) {
    auto pRet = new(std::nothrow) TextButton();

    if (pRet && pRet->init(text, font, width, height, bgTexture, callback)) {
        pRet->autorelease();
        return pRet;
    } else {
        CC_SAFE_DELETE(pRet);
        return nullptr;
    }
}

TextButton* TextButton::create(string text, std::function<void(TextButton*)> callback) {
    return TextButton::create(text, "goldFont.fnt", 0, 0, "GJ_button_01.png", callback);
}

TextButton* TextButton::create(string text, string font, std::function<void(TextButton*)> callback) {
    return TextButton::create(text, font, 0, 0, "GJ_button_01.png", callback);
}

TextButton* TextButton::create(string text, string font, float width, float height, std::function<void(TextButton*)> callback) {
    return TextButton::create(text, font, width, height, "GJ_button_01.png", callback);
}


#pragma endregion