#include "main_scene.hpp"

using namespace game::scene;

MainScene::MainScene()
{
    _scene = nullptr;
}

void MainScene::Update()
{
    if (IsKeyPressed(KEY_A))
    {
        delete _scene;
        _scene = new CharCreationScene();
    }
}

void MainScene::Draw()
{
    raylib::DrawText("raylib-rpg MainScene!", 160, 200, 20, LIGHTGRAY);
}

core::scene::Scene* MainScene::GetScene()
{
    return _scene;
}