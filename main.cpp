#include "raylib-cpp.hpp"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

#include "App.hpp"

int screenWidth = 800;
int screenHeight = 450;

// Main Enry Point
int main()
{
    Application app("raylib-rpg", screenWidth, screenHeight);

    app.Execute();

    return 0;
}