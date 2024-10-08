#pragma once

// core specific
#include "button.hpp"
#include "time/timer.hpp"

namespace core
{
  namespace gui
  {
    class PushButton : public Button
    {
    public:
      PushButton();
      PushButton(std::string buttonText);
      PushButton(std::string texturePath,
                 std::string fxPath,
                 std::string fontPath);
      virtual ~PushButton() override;
      virtual void Update() override;
      virtual void Draw() override;
      bool         buttonPressed();
      void         changeText(std::string text);
      void         move(raylib::Vector2 updatedPosition);
      void         setFixedSize(Vector2 size);
      void         setFixedPosition(Vector2 position);

    private:
      Vector2     m_size;
      Vector2     m_position;
      bool        m_action;     // Button action should be activated
      std::string m_text;       // Button display text
      int         m_textOffset; // Text Y offset of the button
      time::Timer m_timer;      // Basic timer
      bool        m_fixedSize     = false;
      bool        m_fixedPosition = false;
    };
  } // namespace gui
} // namespace core
