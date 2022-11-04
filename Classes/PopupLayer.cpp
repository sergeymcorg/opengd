#include "PopupLayer.h"

void PopupLayer::show() {
	
    m_pLayer->runAction(EaseElasticOut::create(ScaleTo::create(0.5f, 1.0f), 0.6f));
	this->runAction(FadeTo::create(0.14,100));

	auto scene = Director::getInstance()->getRunningScene();
	scene->addChild(this);
}

//touch
bool PopupLayer::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	log_ << "touch began";
	return true;
}


//TODO: block touch other layers
// I did it!
bool PopupLayer::init() {
	if(!this->initWithColor(Color4B(0, 0, 0, 0)))
		return false;
	
	
	m_pLayer = Layer::create();
	m_pLayer->setScale(0);
	this->addChild(m_pLayer);


	// set up listener 

	auto dir = Director::getInstance();
    

	auto listener = EventListenerTouchOneByOne::create();

	listener->setEnabled(true);
	listener->setSwallowTouches(true);


	// trigger when you start touch
	listener->onTouchBegan = CC_CALLBACK_2(PopupLayer::onTouchBegan, this);


	dir->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	

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
