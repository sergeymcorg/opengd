#pragma once

#include "cocos2d.h"
#include <cocos-ext.h>
//#include <Windows.h>
#include <iostream>
#include <iomanip>

USING_NS_CC;
using std::string, std::vector;
/*
#ifdef _WIN32
#define ENABLE_DISCORD 1
#else
#define ENABLE_DISCORD 0
#endif
*/
#define ENABLE_DISCORD 1

// logger
class Logger : private std::streambuf, public std::ostream {
public:
    Logger() : std::ostream(this) {
        std::time_t t = std::time(nullptr);
        std::tm tm = *std::localtime(&t);
        std::cout << "[" << std::put_time(&tm, "%H:%M:%S") << "] ";
    }

    ~Logger() {
        std::cout << std::endl;
    }

private:
    int overflow(int c) override {
        std::cout.put(c);
        return 0;
    }
};

// defines
#define log_ Logger()
#define GM GameManager::getInstance()

// Most used things
#include "utils.h"
#include "constants.h"
#include "MenuItemSpriteExtra.h"
#include "DropDownLayer.h"
#include "GameManager.h"
#include "TextButton.h"
#include "GameToolbox.h"
