#ifndef _PUSH_BUTTON_HPP
#define _PUSH_BUTTON_HPP

#include "button.hpp"

namespace core {
    namespace gui {
        class PushButton: public Button
        {
            public:
                PushButton();
                PushButton(std::string texture_path, std::string fx_path, std::string font_path);
                virtual ~PushButton() override; 
                virtual void Update() override;
                virtual void Draw() override;

            private:
                bool _action;               // Button action should be activated
                std::string _text;          // Button display text
                int _text_offset;           // Text Y offset of the button

                void CheckButtonPressed();
                void Move(raylib::Vector2 updated_position);
        };
    } // namespace gui
} // namespace core

#endif // _PUSH_BUTTON_HPP