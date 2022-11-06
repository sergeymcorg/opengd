/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "AppDelegate.h"
#include "includes.h"

// #define USE_AUDIO_ENGINE 1

#if USE_AUDIO_ENGINE
#include "audio/include/AudioEngine.h"
#endif

USING_NS_CC;

static cocos2d::Size designResolutionSize = {1280, 720};
// static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
// static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
// static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

static cocos2d::Size windowSize = {1280, 720}; // 16 : 9
// static cocos2d::Size windowSize = {1920, 1080}; // 16 : 9

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate() 
{
#if USE_AUDIO_ENGINE
    AudioEngine::end();
#endif
}

// if you want a different context, modify the value of glContextAttrs
// it will affect all platforms
void AppDelegate::initGLContextAttrs()
{
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil,multisamplesCount
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8, 0};

    GLView::setGLContextAttrs(glContextAttrs);
}

// if you want to use the package manager to install more packages,  
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        // glview = GLViewImpl::createWithRect("OpenGD", cocos2d::Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
        glview = GLViewImpl::createWithRect("OpenGD", cocos2d::Rect(0, 0, windowSize.width, windowSize.height));
        // glview = GLViewImpl::createWithFullScreen("OpenGD");
#else
        glview = GLViewImpl::create("OpenGD");
#endif
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // Set the primary monitor FPS (fake vsync)
    auto mon = glfwGetPrimaryMonitor();
    auto md = glfwGetVideoMode(mon);    
    director->setAnimationInterval(1.0f / md->refreshRate);

    Application::getInstance()->setTextureQuality(TextureQuality::MEDIUM);

    // Set the design resolution
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);

    if (Application::getInstance()->getTextureQuality() == LOW) 
        director->setContentScaleFactor(0.5f);

    register_all_packages();

    
#ifdef _WIN32
    AllocConsole();
    freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
    SetConsoleOutputCP(65001); // if for some reason someone would need to output unicode chars
#endif

    srand(time(0));

    GameManager::getInstance()->loadFromSave();

    auto fileUtils = FileUtils::getInstance();
    auto resourcesPath = fileUtils->getDefaultResourceRootPath();
    fileUtils->addSearchPath(resourcesPath + "audio");
    fileUtils->addSearchPath(resourcesPath + "bg");
    fileUtils->addSearchPath(resourcesPath + "effects");
    fileUtils->addSearchPath(resourcesPath + "fonts");
    fileUtils->addSearchPath(resourcesPath + "grounds");
    fileUtils->addSearchPath(resourcesPath + "other");
    fileUtils->addSearchPath(resourcesPath + "sfx");
    fileUtils->addSearchPath(resourcesPath + "sprites");
    fileUtils->addSearchPath(resourcesPath + "spriteSheets");
    fileUtils->addSearchPath(resourcesPath + "ui");
 
    // run
    director->runWithScene(LoadingLayer::scene());

// #if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
// 	director->getScheduler()->schedule([=](float dt)
// 	{
// 		if(director->getRunningScene()->getChildByName("ImGUILayer") == NULL)
// 		{
// 			director->getRunningScene()->addChild(ImGuiLayer::create(), INT_MAX, "ImGUILayer");
// 		}
// 	}, this, 0,false, "checkImGUI");
// #endif

    // GLViewImpl::full

    return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::pauseAll();
#endif
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::resumeAll();
#endif
}
