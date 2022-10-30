#include "PopupLayer.h"

void PopupLayer::show() {
	
    m_pLayer->runAction(EaseElasticOut::create(ScaleTo::create(0.5f, 1.0f), 0.6f));
	this->runAction(FadeTo::create(0.14,100));

	auto scene = Director::getInstance()->getRunningScene();
	scene->addChild(this);
}

//not working
bool PopupLayer::onTouchBegan(Touch *touch, Event *unused_event) {
	log_ << "touch began!";
	return true;
}


//TODO: block touch other layers

bool PopupLayer::init() {

	if(!this->initWithColor(Color4B(0, 0, 0, 0)))
		return false;
	

	auto dir = Director::getInstance();
	/*
	dir->getTouchDispatcher()->incrementForcePrio(2);
	this->setTouchEnabled(true);
	this->setKeypadEnabled(true);
	this->setKeyboardEnabled(true);
	*/
		
	m_pLayer = Layer::create();
	m_pLayer->setScale(0);
	m_pLayer->setContentSize(dir->getWinSize());
	this->addChild(m_pLayer);
	
	
	return true;
}


void PopupLayer::keyBackClicked() {
	
	this->close();
}

void PopupLayer::close() {
	this->removeFromParentAndCleanup(true);

}


PopupLayer* PopupLayer::create() {
	
	PopupLayer* pRet = new (std::nothrow) PopupLayer();
    if (pRet && pRet->init()) {
        pRet->autorelease();
        return pRet;
    } else {
        CC_SAFE_DELETE(pRet);
        return nullptr;
    }


}
