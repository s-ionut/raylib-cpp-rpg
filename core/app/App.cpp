#include "App.hpp"

using namespace core;

Application::Application(std::string windowName, int width, int height)
    : m_windowName(windowName)
    , m_width(width)
    , m_height(height)
    , m_window(width, height, windowName)
    , m_renderer()
{
  SetTargetFPS(m_targetedFps);

  // Disable ESC key for exiting the program
  SetExitKey(KEY_NULL);
};

Application::~Application() {

};

// Main game loop
void Application::Execute()
{
  auto resourceManager
    = game::manager::ResourceManager::getInstance({"..", "resources"});
  auto gameManager = game::manager::GameManager::getInstance();

  while(!m_window.ShouldClose()) // Detect window close button
  {
    if(m_renderer.Shutdown())
    {
      m_window.Close();
    }
    m_renderer.Update();
    m_renderer.Draw();
  }
};
