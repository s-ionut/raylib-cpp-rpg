#pragma once

// raylib specific
#include "raylib-cpp.hpp"

// system specific
#include "etc/system_includes.h"

namespace core {
    namespace gui {
        class CImage
        {
            public:
                CImage() = delete;
                CImage(std::string image_path, raylib::Vector2 position, raylib::Vector2 size);
                CImage(raylib::Texture2D* image, raylib::Vector2 position, raylib::Vector2 size);
                ~CImage();
                void Draw();

            private:
                std::string _image_path;
                std::shared_ptr<raylib::Texture2D> _image;
                raylib::Vector2 _position;
                raylib::Vector2 _size;
                raylib::Rectangle _rectangle;

        };
    } // namespace gui
} // namespace core