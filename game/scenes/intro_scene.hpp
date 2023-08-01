#pragma once

// core includes
#include "core/scene/scene.hpp"

// game includes
#include "char_creation_scene.hpp"

// system includes
#include "core/etc/system_includes.h"

namespace game {
    namespace scene {
        class IntroScene: public core::scene::Scene
        {
            public:
                IntroScene();
                virtual ~IntroScene() {};
                virtual void Update() override;
                virtual void Draw() override;
                virtual std::shared_ptr<core::scene::Scene> GetScene() override;
            
            private:
                std::shared_ptr<core::scene::Scene> _scene;
        };
    } // namespace scene
} // namespace game
