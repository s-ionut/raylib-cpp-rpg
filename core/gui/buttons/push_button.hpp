#pragma once

// core specific
#include "button.hpp"
#include "time/timer.hpp"

// system specific
#include "etc/system_includes.h"

namespace core {
    namespace gui {
        class PushButton: public Button
        {
            public:
                PushButton();
                PushButton(std::string button_text);
                PushButton(std::string texture_path, std::string fx_path, std::string font_path);
                virtual ~PushButton() override; 
                virtual void Update() override;
                virtual void Draw() override;
                bool ButtonPressed();
                void ChangeText(std::string text);

            private:
                bool _action;               // Button action should be activated
                std::string _text;          // Button display text
                int _text_offset;           // Text Y offset of the button
                time::Timer _timer;         // Basic timer

                void Move(raylib::Vector2 updated_position);
        };
    } // namespace gui
} // namespace core
