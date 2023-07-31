#pragma once

// raylib specific
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
                Button(std::string name);
                Button(std::string texture_path, std::string fx_path, std::string font_path);
                virtual ~Button();
                virtual void Update() {};
                virtual void Draw() {};
            
            protected:
                std::string _texture_path;      // Button texture file path
                std::string _fx_path;           // Button sound file path
                std::string _font_path;         // Button font file path

                raylib::Texture* _texture;      // Button texture
                raylib::Sound* _fx;             // Button sound
                raylib::Font* _font;            // Button font

                ButtonState _state;             // Button state: 0-NOT_PRESSED, 1-MOUSE_HOVER, 2-PRESSED
                int _NUM_FRAMES;                // Number of frames in the texture
                float _frame_height;            // Height of current texture frame
                
                raylib::Rectangle _source_rec;  // Button frame rectangle for drawing
                raylib::Rectangle _bounds;      // Button bounds on screen

            private:
                void LoadCommonButtonSettings();

                raylib::Texture GetDefaultTexture(std::string text);
        };
    } // namespace gui
} // namespace core
