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
        _scene = std::make_shared<CharCreationScene>();
    }
};

void MainScene::Draw()
{
    raylib::DrawText("raylib-rpg MainScene!", 160, 200, 20, LIGHTGRAY);
};

std::shared_ptr<core::scene::Scene> MainScene::GetScene()
{
    return _scene;
};