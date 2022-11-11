#include "LoadingLayer.h"

const vector<string> splashes = {
    "Listen to the music to help time your jumps", 
    "Back for more are ya?", 
    "Use practice mode to learn the layout of a level", 
    "Build your own levels using the level editor", 
    "Go online to play other players levels!", 
    "If at first you don't succeed, try, try again...",
    "Can you beat them all?",
    "Customize your character's icon and color!",
    "You can download all songs from the level select page!",
    "Spikes are not your friends, don't forget to jump",
    "Unlock new icons and colors by completing achievements!"
};

const char* LoadingLayer::getSplash() {
    return splashes[rand() % (splashes.size()-1)].c_str();
}

Scene* LoadingLayer::scene() {
    auto scene = Scene::create();
    scene->addChild(LoadingLayer::create());
    return scene;
}

bool LoadingLayer::init() {
    if (!Layer::init()) return false;


    Director::getInstance()->getTextureCache()->addImage("GJ_LaunchSheet.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("GJ_LaunchSheet.plist");

    auto winSize = Director::getInstance()->getWinSize();

    auto bgSpr = Sprite::create("game_bg_01_001.png");
    bgSpr->setPosition(winSize / 2);
    bgSpr->setScale(winSize.width / bgSpr->getContentSize().width);
    bgSpr->setColor({ 0, 102, 255 });
    this->addChild(bgSpr);

    auto logoSpr = Sprite::createWithSpriteFrameName("GJ_logo_001.png");
    logoSpr->setPosition(winSize / 2);
    logoSpr->setScale(1.05f);
    this->addChild(logoSpr);

    auto robLogoSpr = Sprite::createWithSpriteFrameName("RobTopLogoBig_001.png");
    robLogoSpr->setPosition({ winSize.width / 2, winSize.height / 2 + 190 });
    this->addChild(robLogoSpr);

    auto splash = this->getSplash();
    auto splashText = Label::createWithBMFont("goldFont.fnt", splash);
    splashText->setPosition({ winSize.width / 2, winSize.height / 2 - 200});
    splashText->setScale(0.7f);

    this->addChild(splashText);
    m_pGrooveSprite = Sprite::create("slidergroove.png");
    m_pGrooveSprite->setPosition({ winSize.width / 2, splashText->getPositionY() + 70 });
    this->m_fTotalBarWidth = m_pGrooveSprite->getContentSize().width - 8;
    this->addChild(m_pGrooveSprite);

    m_pBarSprite = Sprite::create("sliderBar.png");
    m_pBarSprite->getTexture()->setTexParameters({ backend::SamplerFilter::NEAREST, backend::SamplerFilter::NEAREST, backend::SamplerAddressMode::REPEAT, backend::SamplerAddressMode::REPEAT });
    m_pBarSprite->setAnchorPoint({0, 0});
    m_pBarSprite->setPosition({ 4.0, 8.0 });
    m_pGrooveSprite->addChild(m_pBarSprite, -1);
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
	
    this->loadAssets();
    
    AchievementManager::getInstance()->loadAchievements();
    AchievementNotifier::getInstance()->addToOrder("geometry.ach.level01b"); //just for test
    AchievementNotifier::getInstance()->addToOrder("geometry.ach.level03b"); // and it also for test

#endif

    return true;
}

void LoadingLayer::loadAssets() {
    auto texCache = cocos2d::Director::getInstance()->getTextureCache();
    auto frameCache = SpriteFrameCache::getInstance();
    auto basePath = FileUtils::getInstance()->getDefaultResourceRootPath();

    // m_nTotalAssets = countFilesRecursively(basePath, {".png", ".plist"});
    iterateRecursive(basePath, {".png", ".plist"}, [&](string path) {
        if (Application::getInstance()->getTextureQuality() == LOW && path.find("-hd") != string::npos) return;
        else if (Application::getInstance()->getTextureQuality() == MEDIUM && path.find("-hd") == string::npos) return;

        this->m_nTotalAssets++;
    });

    // Recursively iterate over all textures and .plists in Resources/ directory which doesnt take a lot of performance
    iterateRecursive(basePath, {".png"}, [&](string path) {        
        if (Application::getInstance()->getTextureQuality() == LOW && path.find("-hd") != string::npos) return;
        else if (Application::getInstance()->getTextureQuality() == MEDIUM && path.find("-hd") == string::npos) return;
		
        texCache->addImageAsync(path, CC_CALLBACK_1(LoadingLayer::assetLoaded, this));
    });

    iterateRecursive(basePath, {".plist"}, [&](string path) {
        if (Application::getInstance()->getTextureQuality() == LOW && path.find("-hd") != string::npos) return;
        else if (Application::getInstance()->getTextureQuality() == MEDIUM && path.find("-hd") == string::npos) return;

        // SpriteFrameCache doesnt like absolute filenames
		
        frameCache->addSpriteFramesWithFile(ghc::filesystem::path(path).filename().string());
        this->assetLoaded(nullptr);
    });
}

void LoadingLayer::assetLoaded(cocos2d::Ref *sender){
    this->m_nAssetsLoaded++;
    m_pBarSprite->setTextureRect({0, 0, m_fTotalBarWidth * (this->m_nAssetsLoaded / this->m_nTotalAssets), m_pBarSprite->getContentSize().height});

    if (m_nAssetsLoaded == m_nTotalAssets)
        Director::getInstance()->replaceScene(MenuLayer::scene());
}