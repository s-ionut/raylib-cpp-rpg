#ifndef _BUTTON_HPP
#define _BUTTON_HPP

#include "raylib-cpp.hpp"

namespace core {
    namespace gui {
        enum class ButtonState
        {
            NOT_PRESSED = 0,
            MOUSE_HOVER,
            PRESSED
        };

        class Button
        {
            public:
                Button();
                Button(std::string texturePath, std::string fxPath, std::string fontPath);
                virtual ~Button();
                virtual void Update();
                virtual void Draw();
            
            protected:
                std::string _texturePath;    // Button texture file path
                std::string _fxPath;         // Button sound file path
                std::string _fontPath;       // Button font file path

                Texture2D _texture;         // Button texture
                Sound _fx;	                // Button sound
                Font _font;                 // Button font

                ButtonState _state;         // Button state: 0-NOT_PRESSED, 1-MOUSE_HOVER, 2-PRESSED
        };
    } // namespace gui
} // namespace core

#endif // _BUTTON_HPP