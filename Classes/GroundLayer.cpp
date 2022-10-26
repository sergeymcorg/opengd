#include "GroundLayer.h"

bool GroundLayer::init(int t_groundID, bool t_menugamelayer){
    if (!Layer::init()) return false;

    this->menuGameLayer = t_menugamelayer;
    
    auto winSize = Director::getInstance()->getWinSize();
    this->groundMenu = Menu::create();
    log_ << "calling" << '\n;';
    
    //string format later
    const std::string groundTextureStr = "groundSquare_001.png";
    
    for(int i = 0; i < 7; i++) {
        log_ << "loop " << i << '\n;';
        
        auto gr = Sprite::create(groundTextureStr);
        this->groundMenu->addChild(gr);
        this->gsizeX = gr->getContentSize().width;
        
        if(this->menuGameLayer) {
        //     gr->runAction(
        //         RepeatForever::create(
        //             Sequence::create(
        //                 TintTo::create(4.0f, {255, 0, 0}),
        //                 TintTo::create(4.0f, {255, 255, 0}),
        //                 TintTo::create(4.0f, {0, 255, 0}),
        //                 TintTo::create(4.0f, {0, 255, 255}),
        //                 TintTo::create(4.0f, {0, 0, 255}),
        //                 TintTo::create(4.0f, {255, 0, 255}),
        //                 TintTo::create(4.0f, {255, 0, 0}),
        //                 nullptr
        //             )
        //         )
        //     );
            auto col = gr->getColor();
            col.r = 0;
            col.g = 102;
            col.b = 255;
            gr->setColor(col);
        }
    }
    
    this->groundMenu->setPositionY(winSize.height / 2 - 287);
    this->groundMenu->alignItemsHorizontallyWithPadding(0);
    this->groundStartPosition = groundMenu->getPositionX();
    this->addChild(this->groundMenu, 2);
    
    this->sep = 5.f;

    auto floor = Sprite::create("floor.png");
    floor->setPosition({winSize.width / 2, 200});
    this->addChild(floor, 128);

    scheduleUpdate();
    
    return true;
}


void GroundLayer::update(float delta) {
    
    if(this->groundStartPosition - groundMenu->getPositionX() < this->gsizeX) 
    {
        groundMenu->setPositionX(groundMenu->getPositionX() - this->sep);
    }
    else 
    {
        groundMenu->setPositionX(groundMenu->getPositionX() + this->gsizeX);
    }
}

GroundLayer* GroundLayer::create(int groundID, bool menugamelayer) {
    GroundLayer* pRet = new(std::nothrow) GroundLayer();

    if (pRet && pRet->init(groundID, menugamelayer)) {
        pRet->autorelease();
        return pRet;
    } else {
        CC_SAFE_DELETE(pRet);
        return nullptr;
    }
}