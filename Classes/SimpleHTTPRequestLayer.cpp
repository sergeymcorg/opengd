#include "SimpleHTTPRequestLayer.h"
#include <cocos/network/HttpClient.h>
#include "AlertLayer.h"

using namespace cocos2d::network;

bool SimpleHTTPRequestLayer::init() {
    Layer *l = Layer::create();
    auto winSize = Director::getInstance()->getWinSize();

    auto base = Sprite::create("square.png");
    base->setPosition({ 0, 0 });
    base->setScale(25.f);
    base->setScaleX(40.f);
    base->setColor({0, 0, 0});
    base->setOpacity(0);
    base->runAction(FadeTo::create(0.5f, 125));
    auto loadingCircle = LoadingCircleLayer::create();
    loadingCircle->m_pCircle->setOpacity(0);
    loadingCircle->m_pCircle->runAction(FadeTo::create(0.5f, 255));
    loadingCircle->setPosition({ winSize.width / 2, winSize.height / 2 });
    loadingCircle->addChild(base, -1);
    l->addChild(loadingCircle);

    addChild(l);

    m_pLC = loadingCircle;

    return true;
}

void SimpleHTTPRequestLayer::start(std::string url, std::function<void(cocos2d::network::HttpClient *client, cocos2d::network::HttpResponse *response)> callback) {
    HttpClient *cl = HttpClient::getInstance();
    HttpRequest *req = new HttpRequest;
    req->setRequestType(HttpRequest::Type::POST);
    req->setUrl(url);
    req->setResponseCallback(callback);
    cl->send(req);
}

void SimpleHTTPRequestLayer::close() {
    m_pLC->removeAllChildrenWithCleanup(true);
    m_pLC->unscheduleUpdate();
    m_pLC->removeFromParentAndCleanup(true);
    m_pLC->release();
}