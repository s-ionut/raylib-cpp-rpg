#pragma once

// raylib specific
#include "raylib-cpp.hpp"

// core specific
#include "scene/scene.hpp"

// game specific
#include "game/scenes/intro_scene.hpp"

//system specific
#include "etc/system_includes.h"

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
                std::shared_ptr<scene::Scene> _scene;
                void GetScene();

        };
    } // namespace renderer
} // namespace core
