#include "button.hpp"

using namespace core::gui;

Button::Button()
{
    _fx = std::make_shared<raylib::Sound>();
    _font = std::make_shared<raylib::Font>();
    _texture = std::make_shared<raylib::Texture>(GetDefaultTexture("BUTTON"));

	LoadCommonButtonSettings();
};

Button::Button(std::string name)
{
    _fx = std::make_shared<raylib::Sound>();
    _font = std::make_shared<raylib::Font>();
    _texture = std::make_shared<raylib::Texture>(GetDefaultTexture(name));

	LoadCommonButtonSettings();
}

Button::~Button() { };

Button::Button(std::string texture_path, std::string fx_path, std::string font_path):
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

	LoadCommonButtonSettings();
};

raylib::Texture Button::GetDefaultTexture(std::string text)
{
    // Create basic texture with nothing in it, just to not throw an error
    Vector2 textSize = _font->MeasureText(text, 10, 1);
    const int barHeight = textSize.y + 40;
    const int barWidth = textSize.x + 10;
    Color colors[] = {DARKGRAY, LIGHTGRAY, WHITE};
    Image image = GenImageColor(barWidth, 3 * barHeight, BLACK);

    for (int i = 0; i < 3; ++i) {
        Rectangle rec = {0, i * barHeight, static_cast<float>(barWidth), static_cast<float>(barHeight)};
        ImageDrawRectangleRec(&image, rec, colors[i]);
    }

    Texture2D default_texture = LoadTextureFromImage(image);

    UnloadImage(image);

    return default_texture;
};

void Button::LoadCommonButtonSettings()
{
    _NUM_FRAMES = 3;
	_frame_height = _texture->height / (float)_NUM_FRAMES;

    _source_rec = raylib::Rectangle(.0f, .0f, (float)_texture->width, (float)_frame_height);

	_state = ButtonState::NOT_PRESSED;
};