#pragma once

#include "cocos2d.h"
#include <cocos-ext.h>
#include <Windows.h>
#include <iostream>
#include <iomanip>

USING_NS_CC;
using std::string, std::vector;

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

#define log_ Logger()

// Most used things
#include "utils.h"
#include "MenuItemSpriteExtra.h"
#include "DropDownLayer.h"
#include "GameManager.h"