#pragma once
#include "includes.h"

class ObjectManager : public Node {
public:
    ValueMap objectDefinitions;
    ValueMap copiedSets;

public:
    static ObjectManager* instance();
    bool init();
    void loadCopiedAnimations();
    void loadCopiedSets();
};