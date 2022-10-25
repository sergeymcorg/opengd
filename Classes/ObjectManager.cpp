#include "ObjectManager.h"

ObjectManager* activeInstance = nullptr;

ObjectManager* ObjectManager::instance() {
    if(activeInstance == nullptr) {
        activeInstance = new(std::nothrow) ObjectManager();
        activeInstance->init();
    } 
    return activeInstance;
}

bool ObjectManager::init() {
    // this shit dont even do nothing
    //auto utils = FileUtils::getInstance();
    //auto path = utils->fullPathFromRelativeFile("objectDefinitions.plist");
    //this->objectDefinitions = utils->getValueMapFromFile(path);
    
    loadCopiedAnimations();
    loadCopiedSets();

    

    return true;
}

void ObjectManager::loadCopiedAnimations() {
    // shit for loading stuff from objectDefinitions, but that file is empty
}

void ObjectManager::loadCopiedSets() {
    // shit for loading stuff from objectDefinitions, but that file is empty
}