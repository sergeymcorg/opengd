#pragma once

#include "includes.h"
#include "LoadingCircleLayer.h"
#include <cocos/network/HttpClient.h>

class SimpleHTTPRequestLayer: public Layer {
public:
    LoadingCircleLayer *m_pLC;
    
    bool init();

    void start(std::string url, std::function<void(cocos2d::network::HttpClient *client, cocos2d::network::HttpResponse *response)> callback);
    
    void close();

    CREATE_FUNC(SimpleHTTPRequestLayer);
};
