#pragma once
#include "includes.h"
#include <filesystem>

USING_NS_CC;
using namespace std::filesystem;

#define ccp(x,y) Vec2(x,y)

vector<string> splitString(string str, char separator) {
    string temp = "";
    vector<string> v;
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

string joinStrings(vector<string> strings, const char* delim) {
    string ret;
    for (size_t i = 0; i < strings.size(); i++) {
        auto str = strings[i];
        ret += (i != strings.size() - 1) ? str + delim : str;
    }
    return ret;
}

template <typename T>
bool isInVector(vector<T> vec, T item) {
    return std::find(vec.begin(), vec.end(), item) != vec.end();
}

int countFilesRecursively(string dir, vector<string> extensions) {
    int count = 0;

    for (auto const& entry : recursive_directory_iterator(dir)) {
        if (!entry.is_directory()) {
            if (isInVector(extensions, entry.path().extension().string()))
                count++;
        }
    }

    return count;
}

void iterateRecursive(string dir, vector<string> extensions, std::function<void(const string)> fn) {
    for (auto const& entry : recursive_directory_iterator(dir)) {
        if (!entry.is_directory()) {
            if (isInVector(extensions, entry.path().extension().string()))
                fn(entry.path().string());
        }
    }
}