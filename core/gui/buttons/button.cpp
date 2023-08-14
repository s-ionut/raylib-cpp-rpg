#include "button.hpp"

using namespace core::gui;

Button::Button()
{
    _fx = std::make_shared<raylib::Sound>();
    _font = std::make_shared<text::CFont>();
    _texture = std::make_shared<raylib::Texture>(GetDefaultTexture("BUTTON"));

	LoadCommonButtonSettings();
};

Button::Button(std::string name)
{
    _fx = std::make_shared<raylib::Sound>();
    _font = std::make_shared<text::CFont>();
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

    _font = std::make_shared<text::CFont>(_font_path);

	LoadCommonButtonSettings();
};

raylib::Texture Button::GetDefaultTexture(std::string text)
{
    // Create basic texture with nothing in it, just to not throw an error
    Vector2 textSize = _font->MeasureText(text, _font->get_font_size(), _font->get_font_spacing());
    const int barHeight = static_cast<int>(textSize.y) + 20;
    const int barWidth = static_cast<int>(textSize.x) + 10;
    std::vector<Color> colors = {DARKGRAY, LIGHTGRAY, WHITE};
    Image image = GenImageColor(barWidth, static_cast<int>(colors.size()) * barHeight, BLACK);

    for (int i = 0; i < colors.size(); ++i)
    {
        Rectangle rec = {0, static_cast<float>(i * barHeight), static_cast<float>(barWidth), static_cast<float>(barHeight)};
        ImageDrawRectangleRec(&image, rec, colors[i]);
    }

    Texture2D default_texture = LoadTextureFromImage(image);

    UnloadImage(image);

    return default_texture;
};

void Button::LoadCommonButtonSettings()
{
    _NUM_FRAMES = static_cast<int>(ButtonState::COUNT);
	_frame_height = _texture->height / static_cast<float>(_NUM_FRAMES);

    _source_rec = raylib::Rectangle(.0f, .0f, static_cast<float>(_texture->width), static_cast<float>(_frame_height));

	_state = ButtonState::NOT_PRESSED;
};