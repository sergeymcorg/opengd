#include "PlayerObject.h"

bool PlayerObject::init(int playerFrame, Layer* gameLayer_) {
    // cap the icon limit
    int frame = std::min(std::max(playerFrame, 1), 13);

    auto sprStr1 = StringUtils::format("player_%02d_001.png", frame);
    auto sprStr2 = StringUtils::format("player_%02d_2_001.png", frame);

    // initialize
    if(!GameObject::init(sprStr1.c_str())) return false;

    if(gameLayer_ != nullptr) {
        gameLayer = gameLayer_;
        inPlayLayer = false;
    }
    else {
        // to do after game manager
        //this->gameLayer = ;
        inPlayLayer = true;
    }

    setTextureRect(Rect(0, 0, 30, 30)); // player hitbox lol

    mainSprite = Sprite::createWithSpriteFrameName(sprStr1);
    addChild(mainSprite, 1);

    secondarySprite = Sprite::createWithSpriteFrameName(sprStr2);

    mainSprite->addChild(secondarySprite, -1);
    //secondarySprite->setPosition(mainSprite->convertToNodeSpace(Vec2(0, 0))); // this shit DONT WORK!! cuz rob made it a global var
    //secondarySprite->setPosition(mainSprite->convertToNodeSpace(Vec2(15, 15)));
    secondarySprite->setPosition(Vec2(30, 30));
    
    shipFrame = Sprite::createWithSpriteFrameName("ship_01_001.png");
    shipFrame->setVisible(false);
    addChild(shipFrame, 2);

    // particles
    dragEffect1 = ParticleSystemQuad::create("dragEffect.plist");
    dragEffect1->setPositionType(ParticleSystem::PositionType::FREE);
    dragEffect1->stopSystem();

    gameLayer->addChild(dragEffect1, 1);

    dragEffect2 = ParticleSystemQuad::create("dragEffect.plist");
    dragEffect2->setPositionType(ParticleSystem::PositionType::FREE);
    dragEffect2->stopSystem();
    dragEffect2->setPositionY(2);

    gameLayer->addChild(dragEffect2, 1);

    dragEffect3 = ParticleSystemQuad::create("dragEffect.plist");
    dragEffect3->setPositionType(ParticleSystem::PositionType::FREE);
    dragEffect3->stopSystem();
    dragEffect3->setPositionY(2);

    gameLayer->addChild(dragEffect3, 1);

    // particle properties
    dragEffect2->setSpeed(dragEffect2->getSpeed() * 0.2f);
    dragEffect2->setSpeedVar(dragEffect2->getSpeedVar() * 0.2f);

    dragEffect3->setSpeed(dragEffect3->getSpeed() * 0.2f);
    dragEffect3->setSpeedVar(dragEffect3->getSpeedVar() * 0.2f);
    dragEffect3->setAngleVar(dragEffect3->getAngleVar() * 2);
    dragEffect3->setStartSize(dragEffect3->getStartSize() * 1.5);
    dragEffect3->setStartSizeVar(dragEffect3->getStartSizeVar() * 1.5);

    dragEffect2->setStartColor({255, 255, 255, 100});
    dragEffect2->setEndColor({255, 255, 255, 0});

    dragEffect3->setStartColor({255, 255, 255, 190});
    dragEffect3->setEndColor({255, 255, 255, 0});

    // other particles
    shipDragEffect = ParticleSystemQuad::create("shipDragEffect.plist");
    shipDragEffect->setPositionType(ParticleSystem::PositionType::GROUPED);
    shipDragEffect->stopSystem();

    gameLayer->addChild(shipDragEffect, 1);

    landEffect1 = ParticleSystemQuad::create("landEffect.plist");
    landEffect1->setPositionType(ParticleSystem::PositionType::GROUPED);
    landEffect1->stopSystem();

    gameLayer->addChild(landEffect1, 1);

    landEffect2 = ParticleSystemQuad::create("landEffect.plist");
    landEffect2->setPositionType(ParticleSystem::PositionType::GROUPED);
    landEffect2->stopSystem();

    gameLayer->addChild(landEffect2, 1);

    // streak
    motionStreak = MotionStreak::create(0.3, 3, 10, {255, 255, 255}, "streak.png");
    motionStreak->setBlendFunc(BlendFunc::ADDITIVE);

    gameLayer->addChild(motionStreak);

    motionStreak->setStartingPositionInitialized(false);

    return true;
}

PlayerObject* PlayerObject::create(int playerFrame, Layer* gameLayer) {
    auto pRet = new (std::nothrow) PlayerObject();

    if(pRet && pRet->init(playerFrame, gameLayer)) {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return pRet;
}