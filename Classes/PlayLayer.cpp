#include "PlayLayer.h"
#include "MenuLayer.h"

Scene* PlayLayer::scene() {
    auto scene = Scene::create();
    scene->addChild(PlayLayer::create());
    return scene;
}

void PlayLayer::addExitButton() {
    auto winSize = Director::getInstance()->getWinSize();
    auto backbtn = MenuItemSpriteExtra::create("GJ_arrow_01_001.png", [&](Node* btn) {
        Director::getInstance()->replaceScene(TransitionFade::create(0.5f, MenuLayer::scene()));
    });
    auto menu = Menu::create();
    menu->addChild(backbtn);
    menu->setPosition({50, winSize.height - 50});
    addChild(menu, 99999);
}

bool PlayLayer::init(bool demo){
    if (!Layer::init()) return false;

    m_demo = demo;

    startPos = Point(0, 105);

    timer = 0;
    attempts = 0;
    jumps = 0;

    auto dir = Director::getInstance();
    auto winSize = dir->getWinSize();
    
    auto bg = Sprite::create("game_bg_01_001.png");
    const Texture2D::TexParams texParams = {
        backend::SamplerFilter::LINEAR, 
        backend::SamplerFilter::LINEAR, 
        backend::SamplerAddressMode::REPEAT, 
        backend::SamplerAddressMode::REPEAT
    };

    this->bgSpr = bg;
    this->bgSpr->getTexture()->setTexParameters(texParams);
    this->bgSpr->setTextureRect(Rect(0, 0, 2048, 1024));
    this->bgSpr->setPosition(winSize / 2);

    this->addChild(this->bgSpr, 1);

    // bg scale
    this->bgSpr->setScale(1.185f); // epic hardcore (please fix lmao)
    
    /*bg->runAction(
        RepeatForever::create(
            Sequence::create(
                TintTo::create(4.0f, {255, 0, 0}),
                TintTo::create(4.0f, {255, 255, 0}),
                TintTo::create(4.0f, {0, 255, 0}),
                TintTo::create(4.0f, {0, 255, 255}),
                TintTo::create(4.0f, {0, 0, 255}),
                TintTo::create(4.0f, {255, 0, 255}),
                TintTo::create(4.0f, {255, 0, 0}),
                nullptr
            )
        )
    );*/


    this->groundMenu = Menu::create();
    
    for(int i = 0; i < 7; i++) {
    
        auto gr = Sprite::create("groundSquare_001.png");

        /*gr->runAction(
            RepeatForever::create(
                Sequence::create(
                    TintTo::create(4.0f, {255, 0, 0}),
                    TintTo::create(4.0f, {255, 255, 0}),
                    TintTo::create(4.0f, {0, 255, 0}),
                    TintTo::create(4.0f, {0, 255, 255}),
                    TintTo::create(4.0f, {0, 0, 255}),
                    TintTo::create(4.0f, {255, 0, 255}),
                    TintTo::create(4.0f, {255, 0, 0}),
                    nullptr
                )
            )
        );*/
        
        this->groundMenu->addChild(gr);
        this->gsizeX = gr->getContentSize().width;
    }
    
    this->groundMenu->setPositionY(winSize.height / 2 - 287);
    this->groundMenu->alignItemsHorizontallyWithPadding(0);
    this->groundStartPosition = groundMenu->getPositionX();
    this->addChild(this->groundMenu, 2);

    if(!demo) addExitButton();
    else {
        auto col = this->groundMenu->getColor();
        col.r = 52;
        col.g = 128;
        col.b = 235;
        bgSpr->setColor(col);
        groundMenu->setColor(col);
    }
    
    scheduleUpdate();
    
    return true;
}
bool PlayLayer::init() {
    return init(false);
}

void PlayLayer::update(float delta) {
    
    this->updateGround(delta);
}

void PlayLayer::updateGround(float delta) {
    
    if(this->groundStartPosition - groundMenu->getPositionX() < this->gsizeX)
        groundMenu->setPositionX(groundMenu->getPositionX() - 5.f);
    else
        groundMenu->setPositionX(groundMenu->getPositionX() + this->gsizeX);
}