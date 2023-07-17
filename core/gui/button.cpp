#include "button.hpp"

using namespace core::gui;

Button::Button()
{

};

Button::Button(std::string texturePath, std::string fxPath, std::string fontPath):
    _texturePath(texturePath),
    _fxPath(fxPath),
     _fontPath(fontPath)
{
    try {
        _texture = raylib::Texture(_texturePath);
    }
    catch (const raylib::RaylibException& error) {
        TraceLog(LOG_WARNING, "Failed to load texture: %s", error.what());
    }

    try {
        _fx = raylib::Sound(_fxPath);
    }
    catch (const raylib::RaylibException& error) {
        TraceLog(LOG_WARNING, "Failed to load sound: %s", error.what());
    }

    try {
        _font = raylib::Font(_fontPath);
    }
    catch (const raylib::RaylibException& error) {
        TraceLog(LOG_WARNING, "Failed to load font: %s", error.what());
    }
};