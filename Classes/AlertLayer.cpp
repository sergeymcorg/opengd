#include "AlertLayer.h"
#include "ui/CocosGUI.h"


void AlertLayer::onBtn1(Ref* sender, cocos2d::ui::Widget::TouchEventType type) {

	switch (type) {
		case cocos2d::ui::Widget::TouchEventType::ENDED:
		{
			this->close(); 
		}
	}

}

void AlertLayer::onBtn2(Ref* sender, cocos2d::ui::Widget::TouchEventType type) {

	switch (type) {
		case cocos2d::ui::Widget::TouchEventType::ENDED:
		{
			this->close(); 
		}
	}

}


bool AlertLayer::init(std::string title, std::string desc, std::string btn1str, std::string btn2str,
float t_width, float t_height) {
	

    if (!PopupLayer::init()) return false;

    auto winSize = Director::getInstance()->getWinSize();
    
	
	auto square = ui::Scale9Sprite::create("square01_001.png");
	square->setPosition({winSize.width / 2, winSize.height / 2});
	square->setContentSize({t_width, t_height});
	this->m_pLayer->addChild(square);

	auto descLabel = Label::createWithBMFont("chatFont.fnt", desc, TextHAlignment::CENTER, (int)t_width);
	descLabel->setPosition({winSize.width / 2, winSize. height / 2});
	this->m_pLayer->addChild(descLabel);
	
	auto titleLabel = Label::createWithBMFont("goldFont.fnt", title);
	titleLabel->setPosition({winSize.width / 2, winSize.height / 2 + (t_height / 5 + 5)});
	this->m_pLayer->addChild(titleLabel);
	
	auto btn1 = ui::Button::create("GJ_button_01.png");
	btn1->setScale9Enabled(true);
	btn1->setTitleAlignment(TextHAlignment::CENTER, TextVAlignment::CENTER);
	btn1->setTitleFontName("goldFont.fnt");
	btn1->setTitleText(btn1str);
	btn1->addTouchEventListener(CC_CALLBACK_2(AlertLayer::onBtn1, this));
	
	const float x_mult = 25;
	const float y_mult = 15;
	
	auto btnlabel_size = btn1->getTitleRenderer()->getContentSize();
	btn1->setContentSize({btnlabel_size.width + x_mult, btnlabel_size.height + y_mult});

	if(btn2str == "") 
	{
		btn1->setPosition({winSize.width / 2, winSize.height / 2 - (t_height / 5 + 10)});
		this->m_pLayer->addChild(btn1);
	}
	else
	{
		
		auto btn2 = ui::Button::create("GJ_button_01.png");
		btn2->setPosition({winSize.width / 2, winSize.height / 2});
		btn2->setScale9Enabled(true);
		btn2->setContentSize({100, 60});
		btn2->ignoreContentAdaptWithSize(true);
		btn2->setTitleAlignment(TextHAlignment::CENTER, TextVAlignment::CENTER);
		btn2->setTitleFontName("goldFont.fnt");
		btn2->setTitleText(btn2str);
		btn2->addTouchEventListener(CC_CALLBACK_2(AlertLayer::onBtn2, this));
		
		btnlabel_size = btn2->getTitleRenderer()->getContentSize();
		btn2->setContentSize({btnlabel_size.width + x_mult, btnlabel_size.height + y_mult});
		
		auto btnMenu = Menu::create();
		btnMenu->addChild(btn1);
		btnMenu->addChild(btn2);
		btnMenu->setPosition({winSize.width / 2, winSize.height / 2 - (t_height / 5 + 10)});
		btnMenu->alignItemsHorizontallyWithPadding(50);
		this->m_pLayer->addChild(btnMenu);

	}
	
	



	

    return true;
}


AlertLayer* AlertLayer::create(std::string title, std::string desc, std::string btn1str, std::string btn2str,
float width, float height) {

    AlertLayer* pRet = new(std::nothrow) AlertLayer();

    if (pRet && pRet->init(title, desc, btn1str, btn2str, width, height)) {
        pRet->autorelease();
        return pRet;
    } else {
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
}