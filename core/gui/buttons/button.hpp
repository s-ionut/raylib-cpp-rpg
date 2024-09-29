#pragma once

// raylib specific
#include "raylib-cpp.hpp"

// core specific
#include "gui/text/font.hpp"

namespace core
{
  namespace gui
  {
    enum class ButtonState
    {
      NOT_PRESSED = 0,
      MOUSE_HOVER,
      PRESSED,
      COUNT
    };

    class Button
    {
    public:
      Button();
      Button(std::string name);
      Button(std::string texturePath,
             std::string fxPath,
             std::string fontPath);
      virtual ~Button();
      virtual void Update() {};
      virtual void Draw() {};

    protected:
      std::string m_texturePath; // Button texture file path
      std::string m_fxPath;      // Button sound file path
      std::string m_fontPath;    // Button font file path

      std::shared_ptr<raylib::Texture> m_texture; // Button texture
      std::shared_ptr<raylib::Sound>   m_fx;      // Button sound
      std::shared_ptr<text::CFont>     m_font;    // Button font

      ButtonState m_state;       // 0-NOT_PRESSED, 1-MOUSE_HOVER, 2-PRESSED
      int         m_numFrames;   // Number of frames in the texture
      float       m_frameHeight; // Height of current texture frame

      raylib::Rectangle m_sourceRec; // Button frame rectangle for drawing
      raylib::Rectangle m_bounds;    // Button bounds on screen

    private:
      void loadCommonButtonSettings();

      raylib::Texture getDefaultTexture(std::string text);
    };
  } // namespace gui
} // namespace core
