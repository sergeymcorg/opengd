#include "GameManager.h"

GameManager* GameManager::getInstance() {
    static GameManager* g_pGM = new(std::nothrow) GameManager();
    // static GameManager* g_pGM;

    // if (!g_pGM) {
    //     g_pGM = new(std::nothrow) GameManager();
    //     g_pGM->setDefaults();
    // }

    return g_pGM;
}

bool GameManager::hasVariable(string name) {
    return this->m_values.contains(name);
}

void GameManager::setDefaults() {
    json defaults = {
        {"player-cube", 1},
        {"player-main-color", 0},
        {"player-secondary-color", 3}
    };

    for (auto& [key, value] : defaults.items()) {
        log_ << key << " : " << value << ";" << this->hasVariable(key);
        if (!this->hasVariable(key))
            this->setVariable(key, value);
    }
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

    this->setDefaults();
}