#include "raylib-cpp.hpp"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

namespace Core{
    class Scene
    {
        public:
            Scene();
            ~Scene();
        private:
    };
} // Core