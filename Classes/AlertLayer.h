#pragma once

#include "includes.h"
#include "PopupLayer.h"
#include "AlertLayerProtocol.h"
#include "ui/CocosGUI.h"

class AlertLayer : public PopupLayer {
private:
	bool init(std::string title, std::string desc, std::string btn1str, std::string btn2str, float width, float height);
	bool init(AlertLayerProtocol*, std::string title, std::string desc, std::string btn1str, std::string btn2str, float width, float height);

	void setup(std::string, std::string, std::string, std::string, float, float);

	AlertLayerProtocol* m_protocol = nullptr;

public:
    static AlertLayer* create(std::string title, std::string desc, std::string btn1str, std::string btn2str, float width, float height);
	static AlertLayer* create(AlertLayerProtocol* protocol, std::string title, std::string desc, std::string btn1str, std::string btn2str, float width, float height);

	void onBtn1(Ref* sender);
	void onBtn2(Ref* sender);
};