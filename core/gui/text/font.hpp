#pragma once

// raylib specific
#include "raylib-cpp.hpp"

// system specific
#include "etc/system_includes.h"

namespace core {
    namespace text {
        class CFont : public raylib::Font
        {
            public:
                CFont();
                CFont(std::string path);
                ~CFont();

                void set_font_spacing(const float spacing);
                void set_font_size(const float size);
                const float get_font_spacing();
                const float get_font_size();

            private:
                std::string _path;
                std::shared_ptr<raylib::Font> _font;

                float _font_spacing;
                float _font_size;
        };
    }  // namespace text
} // namespace core