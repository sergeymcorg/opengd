#include "GJMoreGamesLayer.h"

// void GJMoreGamesLayer::showLayer(bool instant) {
//     ListLayer::showLayer(instant);

//     auto nogames = Label::createWithBMFont("bigFont.fnt", "Nothing here yet... sorry :(");
//     auto winSize = Director::getInstance()->getWinSize();
//     nogames->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
//     nogames->setScale(0.6f);

//     getCCMainLayer()->addChild(nogames);
// } 
// void GJMoreGamesLayer::setup() {
//     ListLayer::setup();

//     auto nogames = Label::createWithBMFont("bigFont.fnt", "Nothing here yet... sorry :(");
//     auto winSize = Director::getInstance()->getWinSize();
//     nogames->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
//     nogames->setScale(0.6f);

//     getCCMainLayer()->addChild(nogames);
// }

bool GJMoreGamesLayer::init() {
    if (!Layer::init()) return false;

    m_pL = ListLayer::create("More Games");

    if(!m_pL) return false;

    auto nogames = Label::createWithBMFont("bigFont.fnt", "Nothing here yet... sorry :(");
    auto winSize = Director::getInstance()->getWinSize();
    nogames->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
    nogames->setScale(0.6f);

    m_pL->getCCMainLayer()->addChild(nogames);
    m_pL->showLayer(false);

    addChild(m_pL);

    return true;
}