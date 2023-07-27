#include "intro_scene.hpp"

using namespace game::scene;

IntroScene::IntroScene()
{
    _scene = nullptr;
}

void IntroScene::Update()
{
    // Do something interesting in the intro
    delete _scene;
    _scene = new CharCreationScene();
}

void IntroScene::Draw()
{
    raylib::DrawText("raylib-rpg IntroScene!", 160, 200, 20, LIGHTGRAY);
}

core::scene::Scene* IntroScene::GetScene()
{
    return _scene;
}