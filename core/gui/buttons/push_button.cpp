#include "push_button.hpp"

using namespace core::gui;

PushButton::PushButton():
    Button()
{
    _action = false;
    _text = "BUTTON";
    _text_offset = 0;
};

PushButton::PushButton(std::string texture_path, std::string fx_path, std::string font_path):
    Button(texture_path, fx_path, font_path)
{
    _action = false;
    _text = "BUTTON";
    _text_offset = 0;
};

PushButton::~PushButton()
{

};

void PushButton::Update()
{
    Move(raylib::Vector2(GetScreenWidth(),GetScreenHeight()));

    _action = false;
    CheckButtonPressed();
    if (_action)
    {
        // Do something with the FX;
        // Change the scene
    }
};

void PushButton::Draw()
{
    Vector2 text_pos;

	// Get the button texture source coordinates
	_source_rec.y = static_cast<int>(_state) * _frame_height;
	
	// Draw the button texture
    _texture->Draw(_source_rec, raylib::Vector2(_bounds.x, _bounds.y), raylib::Color::White());

	// Render buttons to H:center / V:center by default
	text_pos.x = (_bounds.x + (_bounds.width / 2)) - raylib::MeasureText(_text, 10) / 2.0f;
	text_pos.y = (_bounds.y + (_bounds.height / 2)) - 20.0f / 2 + _text_offset;

	// Draw the text on the button texture
    _font->DrawText(_text, text_pos, 10, 1, raylib::Color::Red());
};

void PushButton::CheckButtonPressed()
{
    raylib::Mouse mouse;
    raylib::Vector2 position = mouse.GetPosition();

	// If the mouse positon doesn't collide with the button
	if (!_bounds.CheckCollision(position))
	{
		// Do nothing
		_state = ButtonState::NOT_PRESSED;
		return;
	}

	// If it collides and the mouse button has been pressed, act accordingly
	if (mouse.IsButtonPressed(MOUSE_BUTTON_LEFT))
    {
        
        _state = ButtonState::PRESSED;
    }
    else
    {
        _state = ButtonState::MOUSE_HOVER;
    }

	// If the mouse button has been released, button has been pressed and an action will be queued
	if (mouse.IsButtonReleased(MOUSE_BUTTON_LEFT))
        _action = true;
}

void PushButton::Move(raylib::Vector2 updated_position)
{   
    raylib::Vector2 position_to_update = raylib::Vector2(updated_position.x / 2.0f - _texture->width / 2.0f, updated_position.y / 2.0f - _texture->height / _NUM_FRAMES / 2.0f);
    raylib::Vector2 size = raylib::Vector2((float)_texture->width, _frame_height);

    _bounds = raylib::Rectangle(position_to_update, size);
};