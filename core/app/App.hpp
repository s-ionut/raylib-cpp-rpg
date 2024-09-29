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
    Application(std::string windowName, int width, int height);
    ~Application();

    void Execute();

  private:
    raylib::Window      m_window;                     // Context window
    raylib::AudioDevice m_audioDevice;                // Audio device
    std::string         m_windowName = "Application"; // Window name
    int                 m_width      = 800;           // Window width
    int                 m_height     = 600;           // Window height
    renderer::Renderer  m_renderer;                   // Displays scenes
    int                 m_targetedFps = 60;           // Targeted FPS
  };
} // namespace core
