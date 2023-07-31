#pragma once

// core specific
#include "core/scene/scene.hpp"
#include "core/gui/core_gui.hpp"

// game specific
#include "main_scene.hpp"

// system specific
#include "core/etc/system_includes.h"

namespace game{
    namespace scene{
        class CharCreationScene: public core::scene::Scene
        {
            public:
                CharCreationScene();
                virtual ~CharCreationScene() {};
                virtual void Update() override;
                virtual void Draw() override;
                virtual core::scene::Scene* GetScene() override;

            private:
                core::scene::Scene* _scene;
                int count = 0;
                std::string display_text;
                core::gui::PushButton* button;
        };
    } // namespace scene
} // namespace game
