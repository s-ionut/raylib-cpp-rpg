#include "font.hpp"

using namespace core::text;

CFont::CFont()
{
  _font = std::make_shared<raylib::Font>();

  _font_size    = 10;
  _font_spacing = 1;
};

CFont::CFont(std::string path)
{
  _path = path;

  try
  {
    _font->Load(_path);
  }
  catch(const raylib::RaylibException& error)
  {
    TraceLog(LOG_WARNING, "Failed to load font: %s", error.what());
  }

  _font_size    = 10;
  _font_spacing = 1;
};

void CFont::setFontSpacing(const float spacing) { _font_spacing = spacing; };

void CFont::setFontSize(const float size) { _font_size = size; };

const float CFont::getFontSpacing() { return _font_spacing; };

const float CFont::getFontSize() { return _font_size; };

CFont::~CFont() {

};