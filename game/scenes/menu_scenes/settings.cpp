#include "settings.hpp"

using namespace game::scene;

SettingsScene::SettingsScene()
    : m_background(100, 0, GetScreenWidth(), GetScreenHeight())
{
  m_exitButton = std::make_unique<core::gui::PushButton>("    Exit    ");

  m_exitButton->move(
    raylib::Vector2(GetScreenWidth() - 30, GetScreenHeight() - 20));

  m_scene = nullptr;
}

SettingsScene::~SettingsScene()
{
  std::cout << "Destroyed settings scene" << std::endl;
}

void SettingsScene::Update()
{
  if(m_exitButton->buttonPressed())
  {
    std::cout << "Exit scene" << std::endl;
    m_shouldClose = true;
  }

  m_exitButton->Update();
};

void SettingsScene::Draw()
{
  m_background.Draw(raylib::Color(0, 0, 0, 127));

  m_exitButton->Draw();
};

std::shared_ptr<core::scene::Scene> SettingsScene::GetScene()
{
  return m_scene;
}