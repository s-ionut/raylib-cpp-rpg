#pragma once

// raylib specific
#include "raylib-cpp.hpp"

// system specific
#include "etc/system_includes.h"

namespace core {
    namespace gui {
        class TextBox
        {
            public:
                TextBox();
                TextBox(std::string texture_path, std::string fx_path, std::string font_path);
                virtual ~TextBox();
                virtual void Update() {};
                virtual void Draw() {};
            
            protected:
                std::string _texture_path;      // Text Box texture file path
                std::string _fx_path;           // Text Box sound file path
                std::string _font_path;         // Text Box font file path

                raylib::Texture* _texture;      // Text Box texture
                raylib::Sound* _fx;             // Text Box sound
                raylib::Font* _font;            // Text Box font

            private:
                raylib::Texture GetDefaultTexture();
        };
    } // namespace gui
} // namespace core
