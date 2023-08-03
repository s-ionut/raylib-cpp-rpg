#pragma once

// raylib specific
#include "raylib-cpp.hpp"

// core specific
#include "text/font.hpp"

// system specific
#include "etc/system_includes.h"

namespace core {
    namespace gui {
        class TextBox
        {
            public:
                TextBox();
                TextBox(std::string texture_path, std::string fx_path, std::string font_path);
                ~TextBox();
                void Update();
                void Draw();
            
            protected:
                std::string _texture_path;      // Text Box texture file path
                std::string _fx_path;           // Text Box sound file path
                std::string _font_path;         // Text Box font file path

                std::shared_ptr<raylib::Texture> _texture;      // Text Box texture
                std::shared_ptr<raylib::Sound> _fx;             // Text Box sound
                std::shared_ptr<text::CFont> _font;             // Text Box font

                std::string _input_text;        // Input text that is currently being typed
                std::string _output_text;       // Comitted text that shall be used

                raylib::Rectangle _source_rec;  // Button frame rectangle for drawing
                raylib::Rectangle _bounds;      // Button bounds on screen

            private:
                raylib::Texture GetDefaultTexture();
        };
    } // namespace gui
} // namespace core
