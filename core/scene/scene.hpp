#pragma once

// raylib specific
#include "raylib-cpp.hpp"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

// system specific
#include "etc/system_includes.h"

namespace core {
    namespace scene {
        class Scene
        {
            public:
                virtual ~Scene() {};
                virtual void Update() {};
                virtual void Draw() {};
                virtual std::shared_ptr<Scene> GetScene() { return nullptr; };
        };
    } // scene
} // core
