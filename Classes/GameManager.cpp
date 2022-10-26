#include "GameManager.h"

GameManager* GameManager::getInstance() {
    static GameManager* g_pGM = new(std::nothrow) GameManager();

    return g_pGM;
}

void GameManager::save() {
    auto path = FileUtils::getInstance()->getWritablePath() + "/GameManager.json";

    std::ofstream file(path);
    if (file.good())
        file << this->m_values.dump(4);
    else
        log_ << "Failed to save GameManager!";
    file.close();
}

void GameManager::loadFromSave() {
    auto path = FileUtils::getInstance()->getWritablePath() + "/GameManager.json";

    std::ifstream file(path);
    if (file.good())
        this->m_values = json::parse(file);
    else
        log_ << "Failed to load GameManager!";
    file.close();
}

bool GameManager::test() {
    setVariable("gj_saveTest", 128);
    save();
    loadFromSave();
    int t = getVariable<int>("gj_saveTest");
    if(t == 128) return true;

    return false;
}