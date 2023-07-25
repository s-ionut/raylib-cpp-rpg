#ifndef _TEXT_BOX_HPP
#define _TEXT_BOX_HPP

#include "raylib-cpp.hpp"

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
                std::string _texture_path;      // Button texture file path
                std::string _fx_path;           // Button sound file path
                std::string _font_path;         // Button font file path

                raylib::Texture* _texture;      // Button texture
                raylib::Sound* _fx;             // Button sound
                raylib::Font* _font;            // Button font

            private:
                raylib::Texture GetDefaultTexture();
        };
    } // namespace gui
} // namespace core

#endif // _TEXT_BOX_HPP