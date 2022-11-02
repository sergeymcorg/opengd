#pragma once

#include <cocos2d.h>
#include "PopupLayer.h"

class AlertLayerProtocol
{
public:

	// Temporary solution
	virtual void onBtn(cocos2d::Ref*, bool, PopupLayer*);

	//virtual void onBtn(cocos2d::Ref*, bool);
};