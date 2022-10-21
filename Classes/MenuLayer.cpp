#include "MenuLayer.h"

// WIP
// Scene* MenuLayer::scene() {
//     auto scene = Scene::create();
//     scene->addChild(MenuLayer::create());
//     return scene;
// }

// bool MenuLayer::init(){
//     if (!Layer::init()) return false;

//     auto winSize = Director::getInstance()->getWinSize();

//     auto bg = Sprite::create("game_bg_01_001.png");
//     bg->setPosition(winSize / 2);
//     bg->setScale(1.185); // like a original gd
//     this->addChild(bg);

//     bg->runAction(
//         RepeatForever::create(
//             Sequence::create(
//                 TintTo::create(4.0f, {255, 0, 0}),
//                 TintTo::create(4.0f, {255, 255, 0}),
//                 TintTo::create(4.0f, {0, 255, 0}),
//                 TintTo::create(4.0f, {0, 255, 255}),
//                 TintTo::create(4.0f, {0, 0, 255}),
//                 TintTo::create(4.0f, {255, 0, 255}),
//                 TintTo::create(4.0f, {255, 0, 0}),
//                 nullptr
//             )
//         )
//     );
    
//     auto mainButtons = Menu::create();
//     // auto playBtn = MenuItemSprite();
//     return true;
// }