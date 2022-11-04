#include "AlertLayer.h"
#include "ui/CocosGUI.h"

// Hacky solution, fix if there are any other solutions
void AlertLayer::onBtn1(Ref* sender) {
	
	if (this->m_protocol != nullptr) {
		this->m_protocol->onBtn(sender, false, this);
	}
	else {
		this->close();
	}

}

// Hacky solution, fix if there are any other solutions
void AlertLayer::onBtn2(Ref* sender) {

	if (this->m_protocol != nullptr) {
		this->m_protocol->onBtn(sender, true, this);
	}
	else {
		this->close();
	}
}

void AlertLayer::setup(std::string title, std::string desc, std::string btn1str, std::string btn2str, float t_width, float t_height)
{
	auto winSize = Director::getInstance()->getWinSize();


	auto square = ui::Scale9Sprite::create("square01_001.png");
	square->setPosition({ winSize.width / 2, winSize.height / 2 });
	square->setContentSize({ t_width, t_height });
	this->m_pLayer->addChild(square);

	auto descLabel = Label::createWithBMFont("chatFont.fnt", desc, TextHAlignment::CENTER, (int)t_width);
	descLabel->setPosition({ winSize.width / 2, winSize.height / 2 });
	this->m_pLayer->addChild(descLabel);

	auto titleLabel = Label::createWithBMFont("goldFont.fnt", title);
	titleLabel->setPosition({ winSize.width / 2, winSize.height / 2 + (t_height / 5 + 5) });
	this->m_pLayer->addChild(titleLabel);

	auto btn1 = TextButton::create(btn1str, CC_CALLBACK_1(AlertLayer::onBtn1, this));

	const float x_mult = 25;
	const float y_mult = 15;

	auto btnlabel_size = btn1->getLabel()->getContentSize();
	btn1->setContentSize({ btnlabel_size.width + x_mult, btnlabel_size.height + y_mult });

	auto btnMenu = Menu::create();

	btnMenu->setPosition({ winSize.width / 2, winSize.height / 2 - (t_height / 5 - 10 + 30) });

	btn1->setPosition(Vec2::ZERO);

	// btnMenu->setPosition({ winSize.width / 2, winSize.height / 2 - (t_height / 5 + 10) });

	if (btn2str == "")
	{
		btnMenu->addChild(btn1);
	}
	else
	{

		auto btn2 = TextButton::create(btn2str, CC_CALLBACK_1(AlertLayer::onBtn2, this));
		btn2->setContentSize({ 100, 60 });

		btnlabel_size = btn2->getLabel()->getContentSize();
		btn2->setContentSize({ btnlabel_size.width + x_mult, btnlabel_size.height + y_mult });
		btn2->setPosition(Vec2::ZERO);

		btnMenu->addChild(btn1);
		btnMenu->addChild(btn2);
		btnMenu->alignItemsHorizontallyWithPadding(50);
	}

	this->m_pLayer->addChild(btnMenu);
}


bool AlertLayer::init(std::string title, std::string desc, std::string btn1str, std::string btn2str, float t_width, float t_height) {
	

    if (!PopupLayer::init()) return false;

	m_protocol = nullptr;

	this->setup(title, desc, btn1str, btn2str, t_width, t_height);
    
	return true;
}

bool AlertLayer::init(AlertLayerProtocol* callbacks, std::string title, std::string desc, std::string btn1str, std::string btn2str, float t_width, float t_height) {


	if (!PopupLayer::init()) return false;

	this->m_protocol = callbacks;

	this->setup(title, desc, btn1str, btn2str, t_width, t_height);

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

AlertLayer* AlertLayer::create(AlertLayerProtocol* protocol, std::string title, std::string desc, std::string btn1str, std::string btn2str, float width, float height) {

	AlertLayer* pRet = new(std::nothrow) AlertLayer();

	if (pRet && pRet->init(protocol, title, desc, btn1str, btn2str, width, height)) {
		pRet->autorelease();
		return pRet;
	}
	else {
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}