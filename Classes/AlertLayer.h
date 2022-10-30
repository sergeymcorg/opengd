#pragma once

#include "includes.h"
#include "PopupLayer.h"
#include "ui/CocosGUI.h"

class AlertLayer : public PopupLayer {
private:

   bool init(std::string title, std::string desc, std::string btn1str, std::string btn2str, float width, float height);

public:
    static AlertLayer* create(std::string title, std::string desc, std::string btn1str, std::string btn2str, float width, float height);
	void onBtn1(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
	void onBtn2(Ref* sender, cocos2d::ui::Widget::TouchEventType type);

	
	
	
};