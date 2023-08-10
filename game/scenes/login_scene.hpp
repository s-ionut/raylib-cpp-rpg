#pragma once

// core includes
#include "core/scene/scene.hpp"

// game includes
#include "char_creation_scene.hpp"

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
        };
    } // namespace scene
} // namespace game
