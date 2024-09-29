#include "font.hpp"

using namespace core::text;

CFont::CFont()
{
  m_font = std::make_shared<raylib::Font>();

  m_fontSize    = 10;
  m_fontSpacing = 1;
};

CFont::CFont(std::string path)
{
  m_path = path;

  try
  {
    m_font->Load(m_path);
  }
  catch(const raylib::RaylibException& error)
  {
    TraceLog(LOG_WARNING, "Failed to load font: %s", error.what());
  }

  m_fontSize    = 10;
  m_fontSpacing = 1;
};

void CFont::setFontSpacing(const float spacing) { m_fontSpacing = spacing; };

void CFont::setFontSize(const float size) { m_fontSize = size; };

const float CFont::getFontSpacing() { return m_fontSpacing; };

const float CFont::getFontSize() { return m_fontSize; };

CFont::~CFont() {

};