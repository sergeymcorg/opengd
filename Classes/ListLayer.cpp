#include "ListLayer.h"

ListLayer::ListLayer()
{
    m_Title = nullptr;
}

ListLayer::ListLayer(const char* title)
{
    m_Title = title;
}

ListLayer::~ListLayer()
{
}

void ListLayer::setup()
{
    auto winSize = Director::getInstance()->getWinSize();

    // Ew code
    auto mainLayer = Layer::create();
    auto cellMenu = Menu::create();


    mainLayer->setPosition(Vec2(winSize.width / 2, winSize.height / 2));

    auto chain1 = Sprite::createWithSpriteFrameName("chain_01_001.png");
    chain1->setAnchorPoint({ 0.5, 0.0 });
    chain1->setPosition({ -300, 0 });

    auto chain2 = Sprite::createWithSpriteFrameName("chain_01_001.png");
    chain2->setAnchorPoint({ 0.5, 0.0 });
    chain2->setPosition({ 300, 0 });

    // Empty Node, practical for regrouping
    auto chainGroup = Node::create();
    chainGroup->addChild(chain1);
    chainGroup->addChild(chain2);

    // You can change it to 310 if you want
    chainGroup->setPositionY(308);

    mainLayer->addChild(chainGroup);

    // Might make this a vector<Sprite*>, not sure
    auto topSprite = Sprite::createWithSpriteFrameName("GJ_table_top_001.png");
    topSprite->setPositionY(275);

    auto bottomSprite = Sprite::createWithSpriteFrameName("GJ_table_bottom_001.png");
    bottomSprite->setPositionY(-275);

    auto leftSprite = Sprite::createWithSpriteFrameName("GJ_table_side_001.png");
    leftSprite->setPositionX(-370);
    leftSprite->setScaleY(3.85f);

    auto rightSprite = Sprite::createWithSpriteFrameName("GJ_table_side_001.png");
    rightSprite->setFlippedX(true);
    rightSprite->setPositionX(370);
    rightSprite->setScaleY(3.85f);

    auto bg = Sprite::createWithSpriteFrameName("whiteSquare60_001.png");
    bg->setColor({ 0, 0, 0 });
    bg->setOpacity(108);

    bg->setScale(12.5f, 9);

    mainLayer->addChild(bg, -1);
     
    auto tableGroup = Node::create();
    tableGroup->addChild(topSprite, 1);
    tableGroup->addChild(bottomSprite, 1);
    tableGroup->addChild(leftSprite);
    tableGroup->addChild(rightSprite);

    mainLayer->addChild(tableGroup);

    if (m_Title != "")
    {
        auto label = Label::createWithBMFont("bigFont.fnt", m_Title);

        label->setPositionY(282);
        label->setScale(0.85f);

        mainLayer->addChild(label);
    }

    this->getButtonsMenu()->addChild(cellMenu);
    this->getMainLayer()->addChild(mainLayer);
}

ListLayer* ListLayer::create(const char* title) {
    ListLayer* pRet = new(std::nothrow) ListLayer(title);

    if (pRet && pRet->init()) {
        pRet->autorelease();
        return pRet;
    }
    else {
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
}
