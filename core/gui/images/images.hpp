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
                CImage();
                CImage(std::string image_path);
                ~CImage();

            private:
                std::string _image_path;
        };
    } // namespace gui
} // namespace core