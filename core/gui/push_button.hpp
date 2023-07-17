#ifndef _PUSH_BUTTON_HPP
#define _PUSH_BUTTON_HPP

#include "button.hpp"

class PushButton: Button
{
    public:
        PushButton();
        PushButton(std::string texturePath, std::string fxPath, std::string fontPath);
        ~PushButton(); 

    private:
        int _NUM_FRAMES;            // Number of frames in the texture
        float _frameHeight;         // Height of current texture frame
        Rectangle _sourceRec;       // Button frame rectangle for drawing
        Rectangle _bounds;          // Button bounds on screen
        bool _action;				// Button action should be activated
        std::string _text;          // Button display text
        int _textOffset;            // Text Y offset of the button
        bool _hovering;             // True if mouse hovering over button, False otherwise
};

#endif // _PUSH_BUTTON_HPP