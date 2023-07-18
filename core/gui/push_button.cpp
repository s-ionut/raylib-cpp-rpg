#include "push_button.hpp"

using namespace core::gui;

PushButton::PushButton():
    Button()
{
    _action = false;
};

PushButton::PushButton(std::string texturePath, std::string fxPath, std::string fontPath):
    Button(texturePath, fxPath, fontPath)
{
    _action = false;
};

PushButton::~PushButton()
{

};

void PushButton::Update()
{
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
	float textYPos, textXPos;

	// Get the button texture source coordinates
	_sourceRec.y = static_cast<int>(_state) * _frameHeight;
	
	// Draw the button texture
    _texture->Draw(_sourceRec, raylib::Vector2(_bounds.x, _bounds.y), raylib::Color::White());

	// Render buttons to H:center / V:center by default
	textXPos = (_bounds.x + (_bounds.width / 2)) - raylib::MeasureText(_text, 20) / 2.0f;
	textYPos = (_bounds.y + (_bounds.height / 2)) - 20.0f / 2 + _textOffset;

	// Draw the text on the button texture
	//raylib::DrawTextEx(_font.font, btn->text, (Vector2) { textXPos, textYPos }, btn->font->fontSize, btn->font->fontSpacing, btn->font->color);
    //raylib::DrawTextEx(_font, _text, raylib::Vector2(textXPos, textYPos), _font.baseSize, _font.
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

};