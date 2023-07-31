#pragma once

#include "core/scene/scene.hpp"

#include "char_creation_scene.hpp"

namespace game{
    namespace scene{
        class MainScene: public core::scene::Scene
        {
            public:
                MainScene();
                virtual ~MainScene() {};
                virtual void Update() override;
                virtual void Draw() override;
                virtual core::scene::Scene* GetScene() override;
            
            private:
                core::scene::Scene* _scene;
        };
    } // namespace scene
} // namespace game
