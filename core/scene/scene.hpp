#ifndef _SCENE_HPP
#define _SCENE_HPP

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
        };
    } // scene
} // core

#endif // _SCENE_HPP