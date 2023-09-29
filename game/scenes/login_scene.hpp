#pragma once

// core includes
#include "core/scene/scene.hpp"
#include "core/gui/core_gui.hpp"

// game includes
#include "char_creation_scene.hpp"
#include "managers/game_manager.hpp"

// system includes
#include "core/etc/system_includes.h"

namespace game {
    namespace scene {
        class LoginScene: public core::scene::Scene
        {
            public:
                LoginScene();
                virtual ~LoginScene() {};
                virtual void Update() override;
                virtual void Draw() override;
                virtual std::shared_ptr<core::scene::Scene> GetScene() override;
            
            private:
                std::shared_ptr<core::scene::Scene> _scene;
                std::unique_ptr<core::gui::TextBox> _username_box;
                std::unique_ptr<core::gui::TextBox> _pass_box;

                std::unique_ptr<core::gui::PushButton> _login_button;
                std::unique_ptr<core::gui::PushButton> _exit_button;
        };
    } // namespace scene
} // namespace game
