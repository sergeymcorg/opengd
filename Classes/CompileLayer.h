#pragma once

#include "includes.h"

unsigned int hash(const char* string);

class CompileLayer : public Layer {
protected:
    int next;
    std::string rand();
public:
    inline std::string getRandom() {
        std::string segment = std::string();
        std::string result = "Build ";
        std::string t = __TIME__;

        this->next = hash(t.c_str());

        int i = 0;
        while (i < 4){
            result.append(this->rand());
            i++;
        }
        return result;
    }
    bool init();
    CREATE_FUNC(CompileLayer);
};