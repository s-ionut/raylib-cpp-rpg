#pragma once

// core includes
#include "core/scene/scene.hpp"
#include "core/gui/textbox/text_box.hpp"

// game includes
#include "char_creation_scene.hpp"

// system includes
#include "core/etc/system_includes.h"

namespace game {
    namespace scene {
        class MainScene: public core::scene::Scene
        {
            public:
                MainScene();
                virtual ~MainScene() override;
                virtual void Update() override;
                virtual void Draw() override;
                virtual std::shared_ptr<core::scene::Scene> GetScene() override;
            
            private:
                std::shared_ptr<core::scene::Scene> _scene;
                std::unique_ptr<core::gui::TextBox> _textbox;
        };
    } // namespace scene
} // namespace game
