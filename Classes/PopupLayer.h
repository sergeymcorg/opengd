#pragma once
#include "includes.h"

class PopupLayer : public LayerColor {
public:
	Layer* m_pMainLayer;

    virtual void setup() {};
	
	bool init();
	void keyBackClicked();

	virtual void show();
	virtual void close();
};