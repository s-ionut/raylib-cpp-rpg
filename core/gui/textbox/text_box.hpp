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
      TextBox(std::string texture_path,
              std::string fx_path,
              std::string font_path);
      ~TextBox();
      void        Update();
      void        Draw();
      void        move(raylib::Vector2 updated_position);
      std::string getText();

    private:
      std::string _texture_path; // Text Box texture file path
      std::string _fx_path;      // Text Box sound file path
      std::string _font_path;    // Text Box font file path

      std::shared_ptr<raylib::Texture> _texture; // Text Box texture
      std::shared_ptr<raylib::Sound>   _fx;      // Text Box sound
      std::shared_ptr<text::CFont>     _font;    // Text Box font

      std::string _input_text;  // Input text that is currently being typed
      std::string _output_text; // Comitted text that shall be used

      raylib::Rectangle _source_rec; // Button frame rectangle for drawing
      raylib::Rectangle _bounds;     // Button bounds on screen
      TextBoxState      _state;      // Checks if has been activated or not

      int   _NUM_FRAMES;   // Number of frames in the texture
      float _frame_height; // Height of current texture frame

      time::Timer _timer; // Timer for drawing inside textbox

      raylib::Texture getDefaultTexture();
      void            loadCommonTextBoxSettings();
      bool            isActive();
      void            cursorBlink();
      void            setOutputText();
    };
  } // namespace gui
} // namespace core
