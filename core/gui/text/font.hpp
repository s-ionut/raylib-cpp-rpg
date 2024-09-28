#pragma once

// raylib specific
#include "raylib-cpp.hpp"

// system specific
#include "etc/system_includes.h"

namespace core
{
  namespace text
  {
    class CFont : public raylib::Font
    {
    public:
      CFont();
      CFont(std::string path);
      ~CFont();

      void        setFontSpacing(const float spacing);
      void        setFontSize(const float size);
      const float getFontSpacing();
      const float getFontSize();

    private:
      std::string                   _path;
      std::shared_ptr<raylib::Font> _font;

      float _font_spacing;
      float _font_size;
    };
  } // namespace text
} // namespace core