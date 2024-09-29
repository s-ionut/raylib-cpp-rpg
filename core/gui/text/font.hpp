#pragma once

// raylib specific
#include "raylib-cpp.hpp"

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
      std::string                   m_path;
      std::shared_ptr<raylib::Font> m_font;

      float m_fontSpacing;
      float m_fontSize;
    };
  } // namespace text
} // namespace core