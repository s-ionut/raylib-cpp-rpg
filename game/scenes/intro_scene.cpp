#include "intro_scene.hpp"

using namespace game::scene;

IntroScene::IntroScene()
    : m_timer()
    , m_foreground(0, 0, GetScreenWidth(), GetScreenHeight())
    , m_background(0, 0, GetScreenWidth(), GetScreenHeight())
{
  m_scene = nullptr;
};

void IntroScene::Update()
{
  m_colorAlpha += m_switcher * 2;
  m_fgColor = raylib::Color(255, 255, 255, m_colorAlpha);

  if(!m_timer.hasTimePassedMS(4000))
  {
    if(m_timer.hasTimePassedMS(2000))
      m_switcher = 1;
    return;
  }

  m_scene = std::make_shared<LoginScene>();
};

void IntroScene::Draw()
{
  m_background.Draw(raylib::Color(0, 0, 0, 255));
  raylib::DrawText("ADVENTURE BEGINS",
                   GetScreenWidth() / 2 - 250,
                   GetScreenHeight() / 2 - 25,
                   50,
                   LIGHTGRAY);
  m_foreground.Draw(m_fgColor);
};

std::shared_ptr<core::scene::Scene> IntroScene::GetScene() { return m_scene; };