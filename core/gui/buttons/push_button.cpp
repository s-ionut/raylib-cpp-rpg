#include "push_button.hpp"

using namespace core::gui;

PushButton::PushButton()
    : Button()
    , m_timer()
{
  m_action     = false;
  m_text       = "BUTTON";
  m_textOffset = 0;

  move(raylib::Vector2(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f));
};

PushButton::PushButton(std::string button_text)
    : Button(button_text)
    , m_timer()
{
  m_action     = false;
  m_text       = button_text;
  m_textOffset = 0;

  move(raylib::Vector2(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f));
};

PushButton::PushButton(std::string texturePath,
                       std::string fxPath,
                       std::string fontPath)
    : Button(texturePath, fxPath, fontPath)
    , m_timer()
{
  m_action     = false;
  m_text       = "BUTTON";
  m_textOffset = 0;
};

PushButton::~PushButton() {

};

void PushButton::Update() {};

void PushButton::Draw()
{
  Vector2 textPos;

  // Get the button texture source coordinates
  m_sourceRec.y = static_cast<int>(m_state) * m_frameHeight;

  m_texture->Draw(
    m_sourceRec,
    raylib::Rectangle(m_bounds.x, m_bounds.y, m_size.x, m_size.y),
    {0, 0},
    0,
    raylib::Color::White());

  // Render buttons to H:center / V:center by default
  textPos.x = (m_bounds.x + (m_bounds.width / 2))
              - (m_font->MeasureText(
                   m_text, m_font->getFontSize(), m_font->getFontSpacing()))
                    .x
                  / 2.0f;
  textPos.y = (m_bounds.y + (m_bounds.height / 2))
              - (m_font->MeasureText(
                   m_text, m_font->getFontSize(), m_font->getFontSpacing()))
                    .y
                  / 2.0f;

  // Draw the text on the button texture
  m_font->DrawText(m_text,
                   textPos,
                   m_font->getFontSize(),
                   m_font->getFontSpacing(),
                   raylib::Color::Red());
};

bool PushButton::buttonPressed()
{
  raylib::Mouse   mouse;
  raylib::Vector2 position = mouse.GetPosition();

  m_action = false;

  // If the mouse positon doesn't collide with the button
  if(!m_bounds.CheckCollision(position))
  {
    // Do nothing
    m_state = ButtonState::NOT_PRESSED;
    return false;
  }

  // If it collides and the mouse button has been pressed, act accordingly
  if(mouse.IsButtonPressed(MOUSE_BUTTON_LEFT))
  {
    m_state = ButtonState::PRESSED;
  }
  else
  {
    m_state = ButtonState::MOUSE_HOVER;
  }

  // If the mouse button has been released, button has been pressed and an
  // action will be queued
  if(mouse.IsButtonReleased(MOUSE_BUTTON_LEFT))
  {
    m_action = true;
  }

  return m_action;
};

void PushButton::move(raylib::Vector2 updatedPosition)
{
  if(m_fixedPosition && m_fixedSize)
    return;

  m_position = raylib::Vector2(updatedPosition.x - m_texture->width / 2.0f,
                               updatedPosition.y
                                 - m_texture->height / m_numFrames / 2.0f);

  m_size
    = raylib::Vector2(static_cast<float>(m_texture->width), m_frameHeight);

  m_bounds.SetPosition(m_position);
  m_bounds.SetSize(m_size);
};

void PushButton::setFixedPosition(Vector2 position)
{
  m_position      = position;
  m_fixedPosition = true;

  m_bounds.SetPosition(m_position);
}

void PushButton::setFixedSize(Vector2 size)
{
  m_size      = size;
  m_fixedSize = true;

  m_bounds.SetSize(m_size);
};

void PushButton::changeText(std::string text) { m_text = text; };