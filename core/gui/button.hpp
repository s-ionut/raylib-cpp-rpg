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
                virtual void Update() {};
                virtual void Draw() {};
            
            protected:
                std::string _texturePath;    // Button texture file path
                std::string _fxPath;         // Button sound file path
                std::string _fontPath;       // Button font file path

                raylib::Texture* _texture;           // Button texture
                raylib::Sound* _fx;	                // Button sound
                raylib::Font* _font;                 // Button font

                ButtonState _state;         // Button state: 0-NOT_PRESSED, 1-MOUSE_HOVER, 2-PRESSED
                int _NUM_FRAMES;            // Number of frames in the texture
                float _frameHeight;         // Height of current texture frame
                
                raylib::Rectangle _sourceRec;       // Button frame rectangle for drawing
                raylib::Rectangle _bounds;          // Button bounds on screen

            private:
                void LoadCommonButtonSettings();

                raylib::Texture GetDefaultTexture();
        };
    } // namespace gui
} // namespace core

#endif // _BUTTON_HPP