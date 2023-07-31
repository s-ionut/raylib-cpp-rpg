#pragma once

#include "raylib-cpp.hpp"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

namespace core{
    namespace scene{
        class Scene
        {
            public:
                virtual ~Scene() {};
                virtual void Update() {};
                virtual void Draw() {};
                virtual Scene* GetScene() { return nullptr; };
        };
    } // scene
} // core
