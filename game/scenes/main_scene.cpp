#include "main_scene.hpp"
#include <iostream>

using namespace game::scene;

MainScene::MainScene()
{
    _scene = nullptr;
    _textbox = std::make_unique<core::gui::TextBox>();
}

MainScene::~MainScene()
{
    std::cout << "Destroyed main scene" << std::endl;
}

void MainScene::Update()
{
    if (IsKeyPressed(KEY_A))
    {
        _scene = std::make_shared<CharCreationScene>();
    }

    _textbox->Update();
};

void MainScene::Draw()
{
    raylib::DrawText("raylib-rpg MainScene!", 160, 200, 20, LIGHTGRAY);
    _textbox->Draw();
};

std::shared_ptr<core::scene::Scene> MainScene::GetScene()
{
    return _scene;
};