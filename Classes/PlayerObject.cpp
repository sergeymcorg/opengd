#include "PlayerObject.h"

bool PlayerObject::init(int playerFrame, Layer* gameLayer_) {
    // cap the icon limit
    int frame = inRange(playerFrame, 1, 13);

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

    setTextureRect(Rect(0, 0, 60, 60)); // player hitbox lol

    m_pMainSprite = Sprite::createWithSpriteFrameName(sprStr1);
    addChild(m_pMainSprite, 1);

    m_pSecondarySprite = Sprite::createWithSpriteFrameName(sprStr2);

    m_pMainSprite->addChild(m_pSecondarySprite, -1);
    //secondarySprite->setPosition(mainSprite->convertToNodeSpace(Vec2(0, 0))); // this shit DONT WORK!! cuz rob made it a global var
    //secondarySprite->setPosition(mainSprite->convertToNodeSpace(Vec2(15, 15)));
    m_pSecondarySprite->setPosition(Vec2(30, 30));
    
    m_pShipSprite = Sprite::createWithSpriteFrameName("ship_01_001.png");
    m_pShipSprite->setVisible(false);
    addChild(m_pShipSprite, 2);

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

    scheduleUpdate();

    return true;
}

void PlayerObject::setMainColor(Color3B col) {
    this->m_pMainSprite->setColor(col);
}

void PlayerObject::setSecondaryColor(Color3B col) {
    this->m_pSecondarySprite->setColor(col);
}

void PlayerObject::update(float dt) {
    dt *= 60; // rob :skull:

    if (this->m_bIsDead)
        return;

    log_ << dt * this->m_fSpeed * this->m_dXVel;
    
    if (!this->m_bIsLocked) {
        this->setPosition(this->getPosition() + ccp(dt * this->m_fSpeed * this->m_dXVel, dt * this->m_fSpeed * this->m_dYVel));
    }
}

void PlayerObject::logValues() {
    log_ << "xVel: " << this->m_dXVel << "; yVel: " << m_dYVel << "; gravity: " << m_dGravity << "; Jump: " << m_dJump;
}

// void PlayerObject::jump() {
    // this->runAction(
    //     Sequence::create(
    //         Spawn::create(
    //             Sequence::create(
    //                 RotateBy::create(0.15, 80.f),
    //                 RotateBy::create(0.025, 0.f),
    //                 RotateBy::create(0.225, 80.f),
    //                 RotateBy::create(0, -160),
    //                 nullptr
    //             ),
    //             Sequence::create(
    //                 //MoveBy::create(0.025, { 0, 80.f }),
    //                 //MoveBy::create(0.15, { 0, 50.f }),
    //                 //MoveBy::create(0.05, { 0.f, 0.f }),
    //                 //MoveBy::create(0.15, { 0, -80.f }),
    //                 //MoveBy::create(0.025, { 0, -50.f }),
    //                 MoveBy::create(0.2, {0, 130.f}),
    //                 MoveBy::create(0.2, { 0, -130.f }),
    //                 nullptr
    //             ),
    //             nullptr
    //         ),
    //         nullptr
    //     )
    // );
// }

PlayerObject* PlayerObject::create(int playerFrame, Layer* gameLayer) {
    auto pRet = new (std::nothrow) PlayerObject();

    if(pRet && pRet->init(playerFrame, gameLayer)) {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return pRet;
}