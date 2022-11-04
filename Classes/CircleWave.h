#pragma once
#include "includes.h"

class CircleWave : public DrawNode, public ActionTweenDelegate {
private:
    void draw();
    virtual void updateTweenAction(float value, const std::string& key) override;
    bool init(float duration, Color4B color, float radiusMin, float radiusMax, bool easing, float lineWidth, bool filled);
    void update(float dt);

    Color4F m_eColor; // damn CC_SYNTHESIZE doesnt work with it :skull:
    Node* m_pFollowedNode;
    CC_SYNTHESIZE(float, m_fLineWidth, LineWidth)
    CC_SYNTHESIZE(float, m_fRadius, Radius)
    CC_SYNTHESIZE(float, m_fWidth, Width)
    CC_SYNTHESIZE(bool, m_bFilled, Filled)
    
public:
    void followNode(Node* node);
    static CircleWave* create(float duration, Color4B color, float radiusMin, float radiusMax, bool easing, bool filled, float lineWidth = 2.0f);

    void setColor(Color4B col);
    Color4B getColor();
};