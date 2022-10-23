#pragma once
#include "includes.h"

class MenuItemSpriteExtra : public MenuItemSprite {
private:
    MenuItemSpriteExtra(const char* sprite, Node* sprNode, std::function<void(Node*)> callback);
    virtual bool init() override;

    Node* m_pSprite;
    float m_fAnimDuration;
    std::function<void(Node*)> m_fCallback;
    CC_SYNTHESIZE(float, m_fNewScale, NewScale);

public:
    /// @brief Create a funny scaling button like in gd
    /// @param sprite The name of the sprite FRAME (it should be in a plist)
    /// @param callback Runs when you release the button with mouse hovered. Can be a lambda func. The Node* param is the button itself
    /// @return The button
    static MenuItemSpriteExtra* create(const char* sprite, std::function<void(Node*)> callback);
    static MenuItemSpriteExtra* createWithNode(Node* sprite, std::function<void(Node*)> callback);
    virtual void selected() override;
    virtual void unselected() override;
    virtual void activate() override;
};