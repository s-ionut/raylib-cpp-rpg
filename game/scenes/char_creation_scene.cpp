#include "char_creation_scene.hpp"

using namespace game::scene;

CharCreationScene::CharCreationScene()
{
    button = std::make_shared<core::gui::PushButton>("CHARACTER CREATION SCREEN");
    _scene = nullptr;
};

void CharCreationScene::Update()
{
    if (button->ButtonPressed())
    {
        _scene = std::make_shared<MainScene>();
    }

    count++ ;
    display_text = "raylib-rpg CharCreationScene!" + std::to_string(count);
};

void CharCreationScene::Draw()
{
    button->Draw();
    raylib::DrawText(display_text, 160, 200, 20, LIGHTGRAY);
};

std::shared_ptr<core::scene::Scene> CharCreationScene::GetScene()
{
    return _scene;
};