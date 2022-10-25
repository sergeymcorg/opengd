#pragma once
#include "includes.h"
#include <fstream>

#include "../libs/json.hpp"
using namespace nlohmann;

class GameManager : public Node {
public:
    static GameManager* getInstance();
    
    /// @brief Set a game variable which can be saved. Usage: GameManager::getInstance()->getVariable<var type>(name)
    /// @tparam T Type of the variable
    /// @param name The name of the variable
    /// @return The variable from the json dict
    template <typename T>
    T getVariable(string name) {
        return this->m_values.contains(name) ? static_cast<T>(this->m_values[name]) : NULL;
    }

    /// @brief Get a game variable. Usage: GameManager::getInstance()->setVariable(name, value)
    /// @param name The name of the variable
    /// @param value The value to assign
    template <typename T>
    void setVariable(string name, T value) {
        this->m_values[name] = value;
    }

    void save();
    void loadFromSave();
    bool test();

private:
    json m_values;
};