#include "raylib-cpp.hpp"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

class Scene
{
    public:
        Scene();
        ~Scene();
    private:
};