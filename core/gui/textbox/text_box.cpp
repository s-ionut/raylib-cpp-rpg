#include "text_box.hpp"

using namespace core::gui;

TextBox::TextBox()
{
    _fx = std::make_shared<raylib::Sound>();
    _font = std::make_shared<text::CFont>();
	_texture = std::make_shared<raylib::Texture>(GetDefaultTexture());

    _source_rec = raylib::Rectangle(.0f, .0f, (float)_texture->width, (float)_texture->height);
    _input_text = "username";
};

TextBox::~TextBox() { };

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

void TextBox::Update()
{
    raylib::Vector2 updated_position = raylib::Vector2((float)GetScreenWidth(),(float)GetScreenHeight());
    raylib::Vector2 position_to_update = raylib::Vector2(updated_position.x / 2.0f - _texture->width / 2.0f, updated_position.y / 2.0f - _texture->height / 2.0f);
    raylib::Vector2 size = raylib::Vector2((float)_texture->width, (float)_texture->height);

    _bounds.SetPosition(position_to_update);
    _bounds.SetSize(size);
};

void TextBox::Draw()
{
    Vector2 text_pos;

	// Get the textbox texture source coordinates
	_source_rec.y = static_cast<float>(_texture->height);
	
	// Draw the textbox texture
    _texture->Draw(_source_rec, raylib::Vector2(_bounds.x, _bounds.y), raylib::Color::Blue());

	// Render text to H:center / V:center by default
	text_pos.x = (_bounds.x + (_bounds.width / 2)) - (_font->MeasureText(_input_text, _font->get_font_size(), _font->get_font_spacing())).x / 2.0f;
	text_pos.y = (_bounds.y + (_bounds.height / 2)) - (_font->MeasureText(_input_text, _font->get_font_size(), _font->get_font_spacing())).y / 2.0f;

	// Draw the text on the button texture
    _font->DrawText(_input_text, text_pos, _font->get_font_size(), _font->get_font_spacing(), raylib::Color::Red());
};

raylib::Texture TextBox::GetDefaultTexture()
{
    // Create basic texture with nothing in it, just to not throw an error
    const int bar_height = 30;
    const int bar_width = 130;
    Color color = WHITE;
    Image image = GenImageColor(bar_width, bar_height, BLACK);

    Rectangle rec = {0, 0, static_cast<float>(bar_width), static_cast<float>(bar_height)};
    ImageDrawRectangleRec(&image, rec, color);

    Texture2D default_texture = LoadTextureFromImage(image);

    UnloadImage(image);

    return default_texture;
};