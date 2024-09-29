#include "scene_manager.hpp"

using namespace core::scene;

SceneManager::SceneManager() { InitScene(); };

SceneManager::~SceneManager() {};

void SceneManager::InitScene()
{
  m_scene = std::make_shared<game::scene::CharCreationScene>();
};

std::shared_ptr<Scene> SceneManager::Manage()
{
  if(IsKeyPressed(KEY_A))
  {
    return std::make_shared<game::scene::CharCreationScene>();
  }
  else if(IsKeyPressed(KEY_B))
  {
    return std::make_shared<game::scene::MainScene>();
  }

  return nullptr;
};

std::shared_ptr<Scene> SceneManager::GetScene()
{
  std::shared_ptr<Scene> currentScene = Manage();

  if(currentScene != nullptr)
  {
    m_scene = currentScene;
  }

  return m_scene;
};