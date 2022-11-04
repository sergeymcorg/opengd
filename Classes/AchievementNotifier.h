#pragma once

#include "includes.h"
#include <vector>
#include "ui/CocosGUI.h"
#include "AchievementManager.h"
#include "SimplePlayer.h"
#include "GameToolbox.h"
#include "AudioEngine.h"

class AchievementNotifier : public Node {
public:
    static AchievementNotifier* getInstance();
    void addToOrder(string key);
    void showAchievements();
private:
    unsigned int currentachievement = 0;
    std::vector<string> achievementstoshow;
    bool canshow = true;
};