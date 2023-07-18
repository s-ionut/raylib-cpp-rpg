#include "button.hpp"

using namespace core::gui;

Button::Button()
{
	_texture = new raylib::Texture(GetDefaultTexture());
    _fx = new raylib::Sound();
    _font = new raylib::Font();

	LoadCommonButtonSettings();
};

Button::~Button()
{
    delete _texture;
    delete _fx;
    delete _font;
};

Button::Button(std::string texturePath, std::string fxPath, std::string fontPath):
    _texturePath(texturePath),
    _fxPath(fxPath),
     _fontPath(fontPath)
{
    try {
        _texture->Load(_texturePath);
    }
    catch (const raylib::RaylibException& error) {
        TraceLog(LOG_WARNING, "Failed to load texture: %s", error.what());
    }

    try {
        _fx->Load(_fxPath);
    }
    catch (const raylib::RaylibException& error) {
        TraceLog(LOG_WARNING, "Failed to load sound: %s", error.what());
    }

    try {
        _font->Load(_fontPath);
    }
    catch (const raylib::RaylibException& error) {
        TraceLog(LOG_WARNING, "Failed to load font: %s", error.what());
    }

	LoadCommonButtonSettings();
};

raylib::Texture Button::GetDefaultTexture()
{
    // Create basic texture with nothing in it, just to not throw an error
    raylib::Texture default_texture(1, 128, 128);
    return default_texture;
};

void Button::LoadCommonButtonSettings()
{
    _NUM_FRAMES = 3;
	_frameHeight = _texture->height / (float)_NUM_FRAMES;

    _sourceRec = raylib::Rectangle(.0f, .0f, (float)_texture->width, (float)_frameHeight);
    _bounds = raylib::Rectangle(GetScreenWidth()  / 2.0f - _texture->width / 2.0f,
							    GetScreenHeight() / 2.0f - _texture->height / _NUM_FRAMES / 2.0f,
							    (float)_texture->width,
							    (float)_frameHeight);

	_state = ButtonState::NOT_PRESSED;
};