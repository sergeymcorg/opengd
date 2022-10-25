#pragma once
#include "includes.h"

class GameObject : public Sprite {
public:
    static GameObject* create(const char*);
    static GameObject* createObject(const char*);
    static GameObject* objectFromString(std::string);
    bool init(const char*);

    static const char* keyToFrame(int key);
    static std::map<std::string, std::string> stringSetupToDict(std::string);
};