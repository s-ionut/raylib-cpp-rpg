#include "text_box.hpp"

using namespace core::gui;

TextBox::TextBox(): _timer()
{
    _fx = std::make_shared<raylib::Sound>();
    _font = std::make_shared<text::CFont>();
	_texture = std::make_shared<raylib::Texture>(GetDefaultTexture());

    _input_text = "placeholder";
    LoadCommonTextBoxSettings();

    Move(raylib::Vector2(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f));
};

TextBox::TextBox(std::string text): _timer()
{
    _fx = std::make_shared<raylib::Sound>();
    _font = std::make_shared<text::CFont>();
	_texture = std::make_shared<raylib::Texture>(GetDefaultTexture());

    _input_text = text;
    LoadCommonTextBoxSettings();

    Move(raylib::Vector2(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f));
};

TextBox::~TextBox() { };

TextBox::TextBox(std::string texture_path, std::string fx_path, std::string font_path):
    _texture_path(texture_path),
    _fx_path(fx_path),
    _font_path(font_path),
    _timer()
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

    LoadCommonTextBoxSettings();
};

void TextBox::Update()
{

    if(IsActive())
    {
        // Get char pressed (unicode character) on the queue
        int key = GetCharPressed();

        // Check if more characters have been pressed on the same frame
        while (key > 0)
        {
            // NOTE: Only allow keys in range [32..125]
            if ((key >= 32) && (key <= 125))
            {
                _input_text.push_back(static_cast<char>(key));
            }

            key = GetCharPressed();  // Check next character in the queue
        }

        if (IsKeyPressed(KEY_BACKSPACE))
        {
            if(_input_text.size() > 0)
                _input_text.pop_back();
        }

        if (IsKeyPressed(KEY_ENTER))
        {
            std::cout << _input_text << std::endl;
        }

        CursorBlink();
    }

    SetOutputText();
};

void TextBox::Draw()
{
    Vector2 text_pos;

	// Get the button texture source coordinates
	_source_rec.y = static_cast<int>(_state) * _frame_height;
	
	// Draw the textbox texture
    _texture->Draw(_source_rec, raylib::Vector2(_bounds.x, _bounds.y), raylib::Color::White());

	// Render text to H:center / V:center by default
	text_pos.x = (_bounds.x + (_bounds.width / 2)) - (_font->MeasureText(_output_text, _font->get_font_size(), _font->get_font_spacing())).x / 2.0f;
	text_pos.y = (_bounds.y + (_bounds.height / 2)) - (_font->MeasureText(_output_text, _font->get_font_size(), _font->get_font_spacing())).y / 2.0f;

	// Draw the text on the button texture
    _font->DrawText(_output_text, text_pos, _font->get_font_size(), _font->get_font_spacing(), raylib::Color::Red());
};

bool TextBox::IsActive()
{
    raylib::Mouse mouse;
    raylib::Vector2 position = mouse.GetPosition();

	if (!_bounds.CheckCollision(position))
	{
        if (mouse.IsButtonPressed(MOUSE_BUTTON_LEFT))
        {
            _state = TextBoxState::NOT_ACTIVE;
            CursorBlink();
        }
    }
    else
    {
        if (mouse.IsButtonPressed(MOUSE_BUTTON_LEFT))
        {
            _state = TextBoxState::ACTIVE;
        }
    }

    return ( _state == TextBoxState::ACTIVE);
};

void TextBox::CursorBlink()
{
    if(_state == TextBoxState::ACTIVE && !_timer.HasTimePassedMS(400)) return;

    if (_output_text.back() != '|')
    {
        _output_text.append("|");
    }
    else
    {
        _output_text.pop_back();
    }

    _timer.Refresh();
};

void TextBox::SetOutputText()
{
    if(_output_text.size() && _output_text.back() == '|')
        _output_text = _input_text + "|";
    else
        _output_text = _input_text;

    if(!_output_text.size())
    {
        _output_text = "-";
    }
};

void TextBox::Move(raylib::Vector2 updated_position)
{
    raylib::Vector2 position_to_update = raylib::Vector2(updated_position.x - _texture->width / 2.0f, updated_position.y - _texture->height / 2.0f);
    raylib::Vector2 size = raylib::Vector2(static_cast<float>(_texture->width), _frame_height);

    _bounds.SetPosition(position_to_update);
    _bounds.SetSize(size);
};

raylib::Texture TextBox::GetDefaultTexture()
{
    // Create basic texture with nothing in it, just to not throw an error
    const int bar_height = 30;
    const int bar_width = 130;
    std::vector<Color> colors = {BLUE, SKYBLUE};
    Image image = GenImageColor(bar_width, static_cast<int>(colors.size()) * bar_height, BLACK);

    for (size_t i = 0; i < colors.size(); ++i)
    {
        Rectangle rec = {0, static_cast<float>(i * bar_height), static_cast<float>(bar_width), static_cast<float>(bar_height)};
        ImageDrawRectangleRec(&image, rec, colors[i]);
    }

    Texture2D default_texture = LoadTextureFromImage(image);

    UnloadImage(image);

    return default_texture;
};


std::string TextBox::GetText()
{
    return _input_text;
};

void TextBox::LoadCommonTextBoxSettings()
{
    _NUM_FRAMES = static_cast<int>(TextBoxState::COUNT);
	_frame_height = _texture->height / static_cast<float>(_NUM_FRAMES);

    _source_rec = raylib::Rectangle(.0f, .0f, static_cast<float>(_texture->width), static_cast<float>(_frame_height));

	_state = TextBoxState::NOT_ACTIVE;
};