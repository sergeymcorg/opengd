#include "AchievementManager.h"

AchievementManager* AchievementManager::getInstance() {
    static AchievementManager* g_pAM = new(std::nothrow) AchievementManager();
    return g_pAM;
}

bool AchievementManager::loadAchievements(){
    string path = FileUtils::getInstance()->fullPathForFilename("AchievementsDesc.json");
    log_ << path;
    std::ifstream file(path);
    if (file.good())
        this->achievementsmap = json::parse(file);
    else{
        log_ << "Failed to load achievements!";
        return false;
    }
    file.close();
    //log_ << static_cast<string>(this->achievementsmap.[0]["achievedDescription"]);
    for (auto& [key, value] : this->achievementsmap.items()) {
        std::string iconraw = this->achievementsmap[key]["icon"]; // idk why it does not compile without var
        std::vector<string> icon;
        std::stringstream streamData(iconraw);
        std::string val;
        
        while (std::getline(streamData, val, '_')) {
            icon.push_back(val);
        }
        // bad code
        if(icon[0].compare("icon")){
            this->achievements[key].icon = tIcon;
        }else if(!icon[0].compare("color") || !icon[0].compare("color2")){
            this->achievements[key].icon = tColor;
        }else if(!icon[0].compare("color2") || !icon[0].compare("color2")){
            this->achievements[key].icon = tColor2;
        }

        log_ << key << "\n\t- " << this->achievementsmap[key]["title"] << "\n\t- " << this->achievementsmap[key]["achievedDescription"] << "\n\t- " << this->achievementsmap[key]["icon"];
        this->achievements[key].achievedDescription = this->achievementsmap[key]["achievedDescription"];
        this->achievements[key].order = this->achievementsmap[key]["order"];
        this->achievements[key].title = this->achievementsmap[key]["title"];
        this->achievements[key].iconid = stoi(icon[1]);
        this->achievements[key].unachievedDescription = this->achievementsmap[key]["unachievedDescription"];

        this->achorder[this->achievementsmap[key]["order"]] = key;
    }

    return true;
}

int AchievementManager::percentForAchievement(string key){
    json completed = GM->getVariable<json>("completed-achievements");
    if(completed.contains(key)){
        return static_cast<int>(completed[key]);
    }else return 0;
}

Achievement AchievementManager::getAchievementByKey(string key){
    return achievements[key];
}

Achievement AchievementManager::getAchievementByOrder(int order){
    return achievements[achorder[order]];
}
