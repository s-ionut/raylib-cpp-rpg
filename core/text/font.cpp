#include "font.hpp"

using namespace core::text;

CFont::CFont()
{
    _font = std::make_shared<raylib::Font>();

    _font_size = 10;
    _font_spacing = 1;

};

CFont::CFont(std::string path)
{
    _path = path;

    try {
        _font->Load(_path);
    }
    catch (const raylib::RaylibException& error) {
        TraceLog(LOG_WARNING, "Failed to load font: %s", error.what());
    }
    
    _font_size = 10;
    _font_spacing = 1;
};

void CFont::set_font_spacing(const float spacing)
{
    _font_spacing = spacing;
};

void CFont::set_font_size(const float size)
{
    _font_size = size;
};

const float CFont::get_font_spacing()
{
    return _font_spacing;
};

const float CFont::get_font_size()
{
    return _font_size;
};

CFont::~CFont()
{

};