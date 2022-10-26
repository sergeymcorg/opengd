#include "MenuGameLayer.h"
#include "MenuLayer.h"
#include "GroundLayer.h"
#include "GameToolbox.h"

Scene* MenuGameLayer::scene() {
    auto scene = Scene::create();
    scene->addChild(MenuGameLayer::create());
    return scene;
}

bool MenuGameLayer::init(){
    if (!Layer::init()) return false;


    startPos = Point(0, 105);

    auto dir = Director::getInstance();
    auto winSize = dir->getWinSize();
    
    addChild(GroundLayer::create(1, true));
    
    
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

    //this is not how it works lol
    //this->bgSpr->setColor(GameToolbox::randomColor3B());

    this->addChild(this->bgSpr, -1);

    // bg scale
    this->bgSpr->setScale(1.185f); // epic hardcore (please fix lmao)
    
    bg->runAction(
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
    );


    
   // scheduleUpdate();
    
    return true;
}
/*
void PlayLayer::update(float delta) {
    
  //  this->updateGround(delta);
}
*/