#pragma once

#include "includes.h"
#include <fstream>
#include <map>

#include "../libs/json.hpp"
using namespace nlohmann;

enum AchievementIconType {
    tIcon = 0,
    tColor,
    tColor2
};

struct Achievement {
    string achievedDescription;
    int order;
    string title;
    AchievementIconType icon;
    int iconid;
    string unachievedDescription;
};

class AchievementManager : public Node {
public:
    static AchievementManager* getInstance();
    bool loadAchievements();
    int percentForAchievement(string key);
    Achievement getAchievementByKey(string key);
    Achievement getAchievementByOrder(int order);
private:
    json achievementsmap;
    std::map<string, Achievement> achievements;
    std::map<int, string> achorder;
};