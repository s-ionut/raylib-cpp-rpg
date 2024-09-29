#include "intro_scene.hpp"

using namespace game::scene;

IntroScene::IntroScene()
    : m_timer()
{
  m_scene = nullptr;
};

void IntroScene::Update()
{
  // Do something interesting in the intro
  if(m_timer.hasTimePassedMS(2000))
  {
    m_scene = std::make_shared<LoginScene>();
  }
};

void IntroScene::Draw()
{
  raylib::DrawText("raylib-rpg IntroScene!", 160, 200, 20, LIGHTGRAY);
};

std::shared_ptr<core::scene::Scene> IntroScene::GetScene() { return m_scene; };