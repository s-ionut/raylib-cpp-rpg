#pragma once

// raylib specific
#include "raylib-cpp.hpp"

// core specific
#include "renderer/renderer.hpp"

// game specific
#include "game/managers/game_manager.hpp"
#include "game/managers/resource_manager.hpp"

namespace core
{
  class Application
  {
  public:
    Application(std::string _window_name, int _width, int _height);
    ~Application();

    void Execute();

  private:
    raylib::Window      _window;                      // Context window
    raylib::AudioDevice _audio_device;                // Audio device
    std::string         _window_name = "Application"; // Window name
    int                 _width       = 800;           // Window width
    int                 _height      = 600;           // Window height
    renderer::Renderer  _renderer;                    // Displays scenes
    int                 _targeted_fps = 60;           // Targeted FPS
  };
} // namespace core
