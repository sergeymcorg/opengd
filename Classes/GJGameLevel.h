#pragma once

enum GJLevelType {
    kGJLevelTypeLocal = 1,
    kGJLevelTypeEditor = 2,
    kGJLevelTypeSaved = 3
};

enum GJDifficulty {
    kGJDifficultyAuto = 0,
    kGJDifficultyEasy = 1,
    kGJDifficultyNormal = 2,
    kGJDifficultyHard = 3,
    kGJDifficultyHarder = 4,
    kGJDifficultyInsane = 5
};

#include "includes.h"
#include "GameObject.h"

class GJGameLevel : public Node {
public:
    int m_nLevelID;
    int m_nUserID;
    int m_nAudioTrack;
    int m_nRatings;
    int m_nDownloads;
    bool m_bIsVerified;
    bool m_bIsUploaded;
    int m_nAttempts;

    std::string m_sLevelName;
    std::string m_sLevelDesc;
    std::string m_sLevelString;
    std::string m_sCreatorName;

    static GJGameLevel* create();

    // WIP
    std::vector<GameObject*> parseLevelData();
};