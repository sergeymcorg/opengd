#pragma once
#include "includes.h"
#include "../libs/filesystem.hpp"

USING_NS_CC;
using namespace ghc::filesystem;

#define ccp(x,y) Point(x,y)

inline std::vector<string> splitString(string str, char separator) {
    string temp = "";
    std::vector<string> v;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == separator) {
            v.push_back(temp);
            temp = "";
        }
        else {
            temp.push_back(str[i]);
        }
    }
    v.push_back(temp);
    return v;
}

inline string joinStrings(std::vector<string> strings, const char* delim) {
    string ret;
    for (size_t i = 0; i < strings.size(); i++) {
        auto str = strings[i];
        ret += (i != strings.size() - 1) ? str + delim : str;
    }
    return ret;
}

template <typename T>
inline bool isInVector(std::vector<T> vec, T item) {
    return std::find(vec.begin(), vec.end(), item) != vec.end();
}

inline int countFilesRecursively(string dir, std::vector<string> extensions) {
    int count = 0;

    for (auto const& entry : recursive_directory_iterator(dir)) {
        if (!entry.is_directory()) {
            if (isInVector(extensions, entry.path().extension().string()))
                count++;
        }
    }

    return count;
}

inline void iterateRecursive(string dir, std::vector<string> extensions, std::function<void(const string)> fn) {
    for (auto const& entry : recursive_directory_iterator(dir)) {
        if (!entry.is_directory()) {
            if (isInVector(extensions, entry.path().extension().string()))
                fn(entry.path().string());
        }
    }
}

template <typename T>
inline T inRange(T value, T min, T max) {
    return MIN(MAX(value, min), max);
}

#define SETUP_SWALLOW_LISTENER(node) auto listener = EventListenerTouchOneByOne::create();\
	listener->setEnabled(true);\
	listener->setSwallowTouches(true);\
    listener->onTouchBegan = [=](Touch*, Event*) -> bool {\
        return true;\
    };\
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, node);

#define REMOVE_SWALLOW_LISTENER(node) Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(node);

#define GETTER(varName, funcName, vType) vType get##funcName() { return varName; }