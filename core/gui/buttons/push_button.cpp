#include "push_button.hpp"

using namespace core::gui;

PushButton::PushButton()
    : Button()
    , _timer()
{
  _action      = false;
  _text        = "BUTTON";
  _text_offset = 0;

  move(raylib::Vector2(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f));
};

PushButton::PushButton(std::string button_text)
    : Button(button_text)
    , _timer()
{
  _action      = false;
  _text        = button_text;
  _text_offset = 0;

  move(raylib::Vector2(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f));
};

PushButton::PushButton(std::string texture_path,
                       std::string fx_path,
                       std::string font_path)
    : Button(texture_path, fx_path, font_path)
    , _timer()
{
  _action      = false;
  _text        = "BUTTON";
  _text_offset = 0;
};

PushButton::~PushButton() {

};

void PushButton::Update() {};

void PushButton::Draw()
{
  Vector2 text_pos;

  // Get the button texture source coordinates
  _source_rec.y = static_cast<int>(_state) * _frame_height;

  // Draw the button texture
  _texture->Draw(_source_rec,
                 raylib::Vector2(_bounds.x, _bounds.y),
                 raylib::Color::White());

  // Render buttons to H:center / V:center by default
  text_pos.x = (_bounds.x + (_bounds.width / 2))
               - (_font->MeasureText(
                    _text, _font->getFontSize(), _font->getFontSpacing()))
                     .x
                   / 2.0f;
  text_pos.y = (_bounds.y + (_bounds.height / 2))
               - (_font->MeasureText(
                    _text, _font->getFontSize(), _font->getFontSpacing()))
                     .y
                   / 2.0f;

  // Draw the text on the button texture
  _font->DrawText(_text,
                  text_pos,
                  _font->getFontSize(),
                  _font->getFontSpacing(),
                  raylib::Color::Red());
};

bool PushButton::buttonPressed()
{
  raylib::Mouse   mouse;
  raylib::Vector2 position = mouse.GetPosition();

  _action = false;

  // If the mouse positon doesn't collide with the button
  if(!_bounds.CheckCollision(position))
  {
    // Do nothing
    _state = ButtonState::NOT_PRESSED;
    return false;
  }

  // If it collides and the mouse button has been pressed, act accordingly
  if(mouse.IsButtonPressed(MOUSE_BUTTON_LEFT))
  {
    _state = ButtonState::PRESSED;
  }
  else
  {
    _state = ButtonState::MOUSE_HOVER;
  }

  // If the mouse button has been released, button has been pressed and an
  // action will be queued
  if(mouse.IsButtonReleased(MOUSE_BUTTON_LEFT))
  {
    _action = true;
  }

  return _action;
};

void PushButton::move(raylib::Vector2 updated_position)
{
  raylib::Vector2 position_to_update = raylib::Vector2(
    updated_position.x - _texture->width / 2.0f,
    updated_position.y - _texture->height / _NUM_FRAMES / 2.0f);
  raylib::Vector2 size
    = raylib::Vector2(static_cast<float>(_texture->width), _frame_height);

  _bounds.SetPosition(position_to_update);
  _bounds.SetSize(size);
};

void PushButton::changeText(std::string text) { _text = text; };