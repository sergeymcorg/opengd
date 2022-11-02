#pragma once
#include "includes.h"

class TextButton : public MenuItemSprite {
private:
    bool init(string text, string font, float width, float height, string bgTexture, std::function<void(TextButton*)> callback);
    void selected() override;
    void unselected() override;
    void activate() override;

    ui::Scale9Sprite* m_pBG;
    Label* m_pText;
    std::function<void(TextButton*)> m_fCallback;
    float m_fWidth;
    float m_fHeight;
    CC_SYNTHESIZE(float, m_fNewScale, NewScale)

public:

    /// @brief Basically a ButtonSprite implementation.
    /// @param text The button text
    /// @param font The font of the text
    /// @param width The width of the bg. Leave 0 for auto-adjusting
    /// @param height The height of the bg. Leave 0 for auto-adjusting
    /// @param bgTexture The texture of the bg
    /// @param callback The callback function, called on button release. Can be a lambda. The Node* is the button itself
    /// @return A new button
    static TextButton* create(string text, string font, float width, float height, string bgTexture, std::function<void(TextButton*)> callback);

    /// @brief Basically a ButtonSprite implementation.
    /// @param text The button text
    /// @param font The font of the text
    /// @param width The width of the bg. Leave 0 for auto-adjusting
    /// @param height The height of the bg. Leave 0 for auto-adjusting
    /// @param callback The callback function, called on button release. Can be a lambda. The Node* is the button itself
    /// @return A new button
    static TextButton* create(string text, string font, float width, float height, std::function<void(TextButton*)> callback);

    /// @brief Basically a ButtonSprite implementation.
    /// @param text The button text
    /// @param font The font of the text
    /// @param callback The callback function, called on button release. Can be a lambda. The Node* is the button itself
    /// @return A new button
    static TextButton* create(string text, string font, std::function<void(TextButton*)> callback);

    /// @brief Basically a ButtonSprite implementation.
    /// @param text The button text
    /// @param callback The callback function, called on button release. Can be a lambda. The Node* is the button itself
    /// @return A new button
    static TextButton* create(string text, std::function<void(TextButton*)> callback);

    void setText(std::string text);
    
    Label* getLabel();
    ui::Scale9Sprite* getBG();
};