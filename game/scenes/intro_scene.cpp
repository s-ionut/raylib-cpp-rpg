#include "intro_scene.hpp"

using namespace game::scene;

IntroScene::IntroScene()
    : _timer()
{
  _scene = nullptr;
};

void IntroScene::Update()
{
  // Do something interesting in the intro
  if(_timer.hasTimePassedMS(2000))
  {
    _scene = std::make_shared<LoginScene>();
  }
};

void IntroScene::Draw()
{
  raylib::DrawText("raylib-rpg IntroScene!", 160, 200, 20, LIGHTGRAY);
};

std::shared_ptr<core::scene::Scene> IntroScene::GetScene() { return _scene; };