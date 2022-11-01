#pragma once
#include "includes.h"


class PopupLayer : public LayerColor {
	
public:
	
	Layer* m_pLayer;
	
public:
	static PopupLayer* create();
	
	bool init();
	virtual void keyBackClicked();
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

	virtual void show();
	virtual void close();
};