#include "PlayLayer.h"

Scene* PlayLayer::scene() {
    auto scene = Scene::create();
    scene->addChild(PlayLayer::create());
    return scene;
}

bool PlayLayer::init(){
    if (!Layer::init()) return false;

    auto winSize = Director::getInstance()->getWinSize();
    
    this->m_pGround = GroundLayer::create(1);
    this->addChild(this->m_pGround);
    this->m_pGround->setSpeed(623);
    
    //temp back button
    auto backbtn = MenuItemSpriteExtra::create("GJ_arrow_01_001.png", [&](Node* btn) {
        Director::getInstance()->replaceScene(TransitionFade::create(0.5f, MenuLayer::scene()));
    });
    auto menu = Menu::create();
    menu->addChild(backbtn);
    menu->setPosition({50, winSize.height - 50});
    addChild(menu, 99999);
    
    this->m_pBG = Sprite::create("game_bg_01_001.png");
    const Texture2D::TexParams texParams = {
        backend::SamplerFilter::LINEAR, 
        backend::SamplerFilter::LINEAR, 
        backend::SamplerAddressMode::REPEAT, 
        backend::SamplerAddressMode::REPEAT
    };
    this->m_pBG->getTexture()->setTexParameters(texParams);
    this->m_pBG->setTextureRect(Rect(0, 0, 1024 * 5, 1024));
    this->m_pBG->setPosition(winSize / 2);
    this->m_pBG->setColor({0, 102, 255});
    this->addChild(this->m_pBG, -1);

    this->m_pPlayer = PlayerObject::create(GM->getVariable<int>("player-cube"), this);
    this->m_pPlayer->setPosition({0, 236});
    this->addChild(this->m_pPlayer);
    this->m_pPlayer->setAnchorPoint({0, 0});
    
    this->scheduleUpdate();
    
    return true;
}

void PlayLayer::update(float dt) {
    auto winSize = Director::getInstance()->getWinSize();

    this->m_pBG->setPositionX(this->m_pBG->getPositionX() - dt * 62);
    if (this->m_pBG->getPositionX() <= -1024)
        this->m_pBG->setPositionX(this->m_pBG->getPositionX() + 1024);

    
}