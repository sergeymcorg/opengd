#include "GJGameLevel.h"

GJGameLevel* GJGameLevel::create() {
	GJGameLevel* res = new GJGameLevel();
	CCASSERT(res != nullptr, "OpenGD - Cannot create GameLevel!");
	
	return res;
}

std::vector<GameObject*> GJGameLevel::parseLevelData() {
	std::vector<GameObject*> t;
	
	return t;
}