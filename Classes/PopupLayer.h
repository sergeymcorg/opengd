#pragma once
#include "includes.h"


class PopupLayer : public LayerColor {
	
public:
	
	Layer* m_pLayer;
	
public:
	static PopupLayer* create();
	
	bool init();
	virtual void keyBackClicked();
	virtual bool onTouchBegan (Touch *touch, Event *unused_event);

	virtual void show();
	virtual void close();
};