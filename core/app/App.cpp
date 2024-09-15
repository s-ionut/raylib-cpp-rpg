#include "App.hpp"

using namespace core;

Application::Application(std::string window_name, int width, int height):
    _window_name(window_name),
    _width(width),
    _height(height),
    _window(width, height, window_name),
    _renderer()
{
  #if defined(PLATFORM_WEB)
    emscripten_set_main_loop(Execute, 0, 1);
  #else
    SetTargetFPS(_targeted_fps);
  #endif

  // Disable ESC key for exiting the program
  SetExitKey(KEY_NULL);
};

Application::~Application()
{

};

// Main game loop
void Application::Execute()
{
  auto resourceManager = game::manager::ResourceManager::getInstance({"..","resources"});
  auto gameManager = game::manager::GameManager::getInstance();

  while (!_window.ShouldClose())    // Detect window close button
  {
    if(_renderer.Shutdown())
    {
      _window.Close();
    }
    
    _renderer.Update();
    _renderer.Draw();
  }
};
