#include "char_creation_scene.hpp"

using namespace game::scene;

CharCreationScene::CharCreationScene()
{
    button = new core::gui::PushButton("CHARACTER CREATION SCREEN");
    _scene = nullptr;
};

void CharCreationScene::Update()
{
    if (button->ButtonPressed())
    {
        delete _scene;
        _scene = new MainScene();
    }

    count++ ;
    display_text = "raylib-rpg CharCreationScene!" + std::to_string(count);
};

void CharCreationScene::Draw()
{
    button->Draw();
    raylib::DrawText(display_text, 160, 200, 20, LIGHTGRAY);
};

core::scene::Scene* CharCreationScene::GetScene()
{
    return _scene;
};