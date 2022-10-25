#include "GitHubLayer.h"

std::string getGitHash()
{
   return "Build ge92c526";
}

bool GitHubLayer::init() {
    if(!Layer::init()) return false;

    auto gh = Label::createWithBMFont("chatFont.fnt", getGitHash());
    gh->setPosition({ -550, 340});
    gh->setScale(0.7f);
    gh->setOpacity(64);
    addChild(gh, 999999);

    return true;
}