#include "text_box.hpp"

using namespace core::gui;

TextBox::TextBox()
{
	_texture = new raylib::Texture(GetDefaultTexture());
    _fx = new raylib::Sound();
    _font = new raylib::Font();
};

TextBox::~TextBox()
{
    delete _texture;
    delete _fx;
    delete _font;
};

TextBox::TextBox(std::string texture_path, std::string fx_path, std::string font_path):
    _texture_path(texture_path),
    _fx_path(fx_path),
     _font_path(font_path)
{
    try {
        _texture->Load(_texture_path);
    }
    catch (const raylib::RaylibException& error) {
        TraceLog(LOG_WARNING, "Failed to load texture: %s", error.what());
    }

    try {
        _fx->Load(_fx_path);
    }
    catch (const raylib::RaylibException& error) {
        TraceLog(LOG_WARNING, "Failed to load sound: %s", error.what());
    }

    try {
        _font->Load(_font_path);
    }
    catch (const raylib::RaylibException& error) {
        TraceLog(LOG_WARNING, "Failed to load font: %s", error.what());
    }
};

raylib::Texture TextBox::GetDefaultTexture()
{
    // Create basic texture with nothing in it, just to not throw an error
    raylib::Texture default_texture(1, 128, 128);
    return default_texture;
};