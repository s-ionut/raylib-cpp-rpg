#include "app.hpp"

using namespace core;

Application::Application(std::string window_name, int width, int height):
    _window_name(window_name),
    _width(width),
    _height(height),
    _window(width, height, window_name),
    _scene_manager(),
    _renderer()
{
    #if defined(PLATFORM_WEB)
      emscripten_set_main_loop(Execute, 0, 1);
    #else
      SetTargetFPS(_targeted_fps);
    #endif
};

Application::~Application()
{

};

// Main game loop
void Application::Execute()
{
    while (!_window.ShouldClose())    // Detect window close button or ESC key
    {
        _renderer.Update();
        _renderer.Draw();
    }
};
