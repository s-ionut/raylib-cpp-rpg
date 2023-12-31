#pragma once

// core specific
#include "core/scene/scene.hpp"
#include "core/gui/core_gui.hpp"
#include "core/gui/text/font.hpp"

// game specific
#include "main_scene.hpp"
#include "login_scene.hpp"
#include "managers/resource_manager.hpp"
#include "managers/game_manager.hpp"
#include "entity/character.hpp"

// system specific
#include "core/etc/system_includes.h"


namespace game {
    namespace scene {
        class CharCreationScene: public core::scene::Scene
        {
            public:
                CharCreationScene();
                virtual ~CharCreationScene() {};
                virtual void Update() override;
                virtual void Draw() override;
                virtual std::shared_ptr<core::scene::Scene> GetScene() override;

            private:
                std::shared_ptr<core::scene::Scene> _scene;
                std::unique_ptr<core::gui::PushButton> _confirm_button;
                std::unique_ptr<core::gui::PushButton> _back_button;
                std::unique_ptr<core::gui::PushButton> _next_avatar_button;
                std::unique_ptr<core::gui::PushButton> _prev_avatar_button;
                std::unique_ptr<core::gui::PushButton> _next_class_button;
                std::unique_ptr<core::gui::PushButton> _prev_class_button;
                std::unique_ptr<core::gui::TextBox> _name_box;
                std::unique_ptr<core::gui::CImage> _avatar;
                std::unique_ptr<core::text::CFont> _font;

                std::vector<raylib::Texture2D*> _avatars;
                uint8_t _avatar_index = 0;
                uint8_t _class_index = 0;
                int _temp_text_X_pos = 0;

                entity::Character* _character;
        };
    } // namespace scene
} // namespace game
