#pragma once

#include "raylib-cpp.hpp"
#include "scene/scene.hpp"

// game specific
#include "game/scenes/intro_scene.hpp"

namespace core {
    namespace renderer {
        class Renderer
        {
            public:
                Renderer();
                ~Renderer();
                void Update();
                void Draw();
            
            private:
                scene::Scene* _scene;
                void GetScene();

        };
    } // namespace renderer
} // namespace core
