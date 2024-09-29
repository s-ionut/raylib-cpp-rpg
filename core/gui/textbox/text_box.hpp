#pragma once

// raylib specific
#include "raylib-cpp.hpp"

// core specific
#include "gui/text/font.hpp"
#include "time/timer.hpp"

namespace core
{
  namespace gui
  {

    enum class TextBoxState
    {
      NOT_ACTIVE = 0,
      ACTIVE,
      COUNT
    };

    class TextBox
    {
    public:
      TextBox();
      TextBox(std::string text);
      TextBox(std::string texturePath,
              std::string fxPath,
              std::string fontPath);
      ~TextBox();
      void        Update();
      void        Draw();
      void        move(raylib::Vector2 updatedPosition);
      std::string getText();

    private:
      std::string m_texturePath; // Text Box texture file path
      std::string m_fxPath;      // Text Box sound file path
      std::string m_fontPath;    // Text Box font file path

      std::shared_ptr<raylib::Texture> m_texture; // Text Box texture
      std::shared_ptr<raylib::Sound>   m_fx;      // Text Box sound
      std::shared_ptr<text::CFont>     m_font;    // Text Box font

      std::string m_inputText;  // Input text that is currently being typed
      std::string m_outputText; // Comitted text that shall be used

      raylib::Rectangle m_sourceRec; // Button frame rectangle for drawing
      raylib::Rectangle m_bounds;    // Button bounds on screen
      TextBoxState      m_state;     // Checks if has been activated or not

      int   m_numFrames;   // Number of frames in the texture
      float m_frameHeight; // Height of current texture frame

      time::Timer m_timer; // Timer for drawing inside textbox

      raylib::Texture getDefaultTexture();
      void            loadCommonTextBoxSettings();
      bool            isActive();
      void            cursorBlink();
      void            setOutputText();
    };
  } // namespace gui
} // namespace core
