#pragma once

// core specific
#include "core/scene/scene.hpp"
#include "core/gui/core_gui.hpp"

// game specific
#include "main_scene.hpp"

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
                std::shared_ptr<core::gui::PushButton> button;
                std::shared_ptr<core::gui::CImage> _image;
                int count = 0;
                std::string display_text;
        };
    } // namespace scene
} // namespace game
