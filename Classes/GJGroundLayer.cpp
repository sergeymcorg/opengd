#include "GJGroundLayer.h"

bool GJGroundLayer::init(int t_groundID, bool t_menugamelayer){
    if (!Layer::init()) return false;

    this->menuGameLayer = t_menugamelayer;
    
    auto winSize = Director::getInstance()->getWinSize();
    this->groundMenu = Menu::create();
    log << "calling" << '\n;';
    
    //string format later
    const std::string groundTextureStr = "groundSquare_001.png";
    
    for(int i = 0; i < 7; i++) {
        log << "loop " + i << '\n;';
        
        auto gr = Sprite::create(groundTextureStr);
        this->groundMenu->addChild(gr);
        this->gsizeX = gr->getContentSize().width;
        
        if(this->menuGameLayer) {
            gr->runAction(
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
        }
    }
    
    this->groundMenu->setPositionY(winSize.height / 2 - 287);
    this->groundMenu->alignItemsHorizontallyWithPadding(0);
    this->groundStartPosition = groundMenu->getPositionX();
    this->addChild(this->groundMenu, 2);
    
    this->sep = this->menuGameLayer ? 10.f : 5.f;

    scheduleUpdate();
    
    return true;
}


void GJGroundLayer::update(float delta) {
    
    if(this->groundStartPosition - groundMenu->getPositionX() < this->gsizeX) 
    {
        groundMenu->setPositionX(groundMenu->getPositionX() - this->sep);
    }
    else 
    {
        groundMenu->setPositionX(groundMenu->getPositionX() + this->gsizeX);
    }
}

GJGroundLayer* GJGroundLayer::create(int groundID, bool menugamelayer) {
    GJGroundLayer* pRet = new(std::nothrow) GJGroundLayer();

    if (pRet && pRet->init(groundID, menugamelayer)) {
        pRet->autorelease();
        return pRet;
    } else {
        CC_SAFE_DELETE(pRet);
        return nullptr;
    }
}