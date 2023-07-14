#ifndef _PUSH_BUTTON_HPP
#define _PUSH_BUTTON_HPP

#include "raylib-cpp.hpp"

enum PushButtonState
{
    NORMAL = 0,
    MOUSE_HOVER,
    PRESSED
};

class PushButton
{
    public:
        PushButton();
        PushButton(std::string texturePath, std::string fxPath, std::string fontPath);
        ~PushButton();  

    private:
        std::string _texturePath;    // Button texture file path
        std::string _fxPath;         // Button sound file path
        std::string _fontPath;       // Button font file path

        int _NUM_FRAMES;            // Number of frames in the texture
        Texture2D _texture;        // Button texture
        Sound _fx;	                // Button sound
        Font _font;                 // Button font
        float _frameHeight;         // Height of current texture frame
        Rectangle _sourceRec;       // Button frame rectangle for drawing
        Rectangle _bounds;          // Button bounds on screen
        PushButtonState _state;	    // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
        bool _action;				// Button action should be activated
        std::string _text;          // Button display text
        int _textOffset;            // Text Y offset of the button
        bool _hovering;             // True if mouse hovering over button, False otherwise
};

#endif // _PUSH_BUTTON_HPP