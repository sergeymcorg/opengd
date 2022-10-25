#include "PlayLayer.h"
#include "MenuLayer.h"
#include "GJGroundLayer.h"

Scene* PlayLayer::scene() {
    auto scene = Scene::create();
    scene->addChild(PlayLayer::create());
    return scene;
}

bool PlayLayer::init(){
    if (!Layer::init()) return false;


    startPos = Point(0, 105);

    timer = 0;
    attempts = 0;
    jumps = 0;

    auto dir = Director::getInstance();
    auto winSize = dir->getWinSize();
    
    auto grl = GJGroundLayer::create(0, false);
    this->addChild(grl, 9999);
    this->groundLayer = grl;
    
    //temp back button
    auto backbtn = MenuItemSpriteExtra::create("GJ_arrow_01_001.png", [&](Node* btn) {
        Director::getInstance()->replaceScene(TransitionFade::create(0.5f, MenuLayer::scene()));
    });
    auto menu = Menu::create();
    menu->addChild(backbtn);
    menu->setPosition({50, winSize.height - 50});
    addChild(menu, 99999);
    
    
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


    
   // scheduleUpdate();
    
    return true;
}
/*
void PlayLayer::update(float delta) {
    
  //  this->updateGround(delta);
}
*/
