#pragma once

#include "includes.h"

class GitHubLayer : public Layer {
public:
    bool init();
    CREATE_FUNC(GitHubLayer);
};