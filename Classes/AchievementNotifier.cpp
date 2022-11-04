#include "AchievementNotifier.h"

AchievementNotifier* AchievementNotifier::getInstance() {
    static AchievementNotifier* g_pAN = new(std::nothrow) AchievementNotifier();
    return g_pAN;
}

void AchievementNotifier::addToOrder(string key){
    this->achievementstoshow.push_back(key);
    log_ << "Added achievement " << key << " to queue!\n Now queue has ";
    for(int i = 0; i < this->achievementstoshow.size(); i++){
        log_ << achievementstoshow[i] << "; ";
    }
}

void AchievementNotifier::showAchievements(){
    // auto currentscene = Director::getInstance()->getRunningScene();
    if(this->currentachievement >= this->achievementstoshow.size()){
        this->achievementstoshow.clear();
        this->currentachievement = 0;
        this->canshow = true;
        return;
    }
    this->canshow = false;
    string smallText;
    auto winSize = Director::getInstance()->getWinSize();
    auto achievementlayer = Layer::create();
    auto achievement = AchievementManager::getInstance()->getAchievementByKey(achievementstoshow[currentachievement]);
    auto sprite = ui::Scale9Sprite::create("GJ_square01.png");
    sprite->setContentSize({winSize.width / 2, winSize.height / 5});
    sprite->setPosition({winSize.width / 2, winSize.height + (sprite->getContentSize().height / 2)});
    achievementlayer->addChild(sprite);
    switch(achievement.icon){
        case tIcon: {
            auto playericon = SimplePlayer::create(achievement.iconid);
            playericon->setPosition({sprite->getPositionX() - (sprite->getContentSize().width / 4), sprite->getPositionY()});
            //playericon->setScale(0.5f);
            playericon->setMainColor({158, 158, 158});
            playericon->setSecondaryColor({255, 255, 255});
            achievementlayer->addChild(playericon);
            smallText = "Unlocked new icon!";
            break;
        }
        case tColor:
        case tColor2: {
            auto color = Sprite::create("square.png");
            color->setPosition({sprite->getPositionX() - (sprite->getContentSize().width / 4), sprite->getPositionY()});
            color->setScale(0.5f);
            color->setColor(GameToolbox::iconColors[achievement.iconid]);
            achievementlayer->addChild(color);
            smallText = "Unlocked new color!";
        }
        default: {
            return;
        }
    }
    
    auto title = ui::TextBMFont::create(achievement.title, "bigFont.fnt");
    title->setPosition({sprite->getPositionX() - (sprite->getContentSize().width / 6), sprite->getPositionY() + (sprite->getContentSize().height / 4)});
    title->setAnchorPoint({0.0f, 1.0f});
    title->setScale(0.6f);
    auto description = ui::TextBMFont::create(smallText, "chatFont.fnt");
    description->setPosition({sprite->getPositionX() - (sprite->getContentSize().width / 6), sprite->getPositionY() - (sprite->getContentSize().height / 6)});
    description->setAnchorPoint({0.0f, 0.75f});
    achievementlayer->addChild(title);
    achievementlayer->addChild(description);
    AudioEngine::play2d("sounds/achievement_01.ogg");
    achievementlayer->runAction(
        Sequence::create(
            EaseInOut::create(MoveBy::create(1.0f, {0, -sprite->getContentSize().height}), 2.0f),
            DelayTime::create(1.5), 
            EaseInOut::create(MoveBy::create(1.0, {0, sprite->getContentSize().height}), 2.0f),
            CallFunc::create([=](){
                Director::getInstance()->getRunningScene()->removeChild(achievementlayer);
                this->currentachievement++;
                AchievementNotifier::showAchievements();
            }), 
            0
        )
    );
    Director::getInstance()->getRunningScene()->addChild(achievementlayer, 100);
}
