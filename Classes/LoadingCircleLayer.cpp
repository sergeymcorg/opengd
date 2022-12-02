#include "LoadingCircleLayer.h"

bool LoadingCircleLayer::init() {
    m_pCircle = Sprite::create("loadingCircle.png");
    this->addChild(m_pCircle);

    scheduleUpdate();

    return true;
}

void LoadingCircleLayer::update(float delta) {
    if(m_pCircle) {
        float rot = m_pCircle->getRotation();
        rot += 3;
        m_pCircle->setRotation(rot);
    }
}