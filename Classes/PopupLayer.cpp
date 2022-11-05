#include "PopupLayer.h"

void PopupLayer::show() {
	this->m_pMainLayer->setScale(0.1f);
    this->m_pMainLayer->runAction(EaseElasticOut::create(ScaleTo::create(0.5f, 1.0f), 0.6f));
	this->runAction(FadeTo::create(0.14, 100));

	auto scene = Director::getInstance()->getRunningScene();
	scene->addChild(this);
}

bool PopupLayer::init() {
	if(!this->initWithColor(Color4B(0, 0, 0, 106)))
		return false;
	
	this->m_pMainLayer = Layer::create();
	this->addChild(m_pMainLayer);

	// set up listener 
	SETUP_SWALLOW_LISTENER(this)

    this->setup();
	
	return true;
}


void PopupLayer::keyBackClicked() {
	this->close();
}

void PopupLayer::close() {
    REMOVE_SWALLOW_LISTENER(this)
	this->removeFromParent();
}
