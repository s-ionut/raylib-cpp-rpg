#include "char_creation_scene.hpp"

using namespace game::scene;

CharCreationScene::CharCreationScene()
{
    button = std::make_shared<core::gui::PushButton>("CHARACTER CREATION SCREEN");
    _image = std::make_shared<core::gui::CImage>("/../game/resources/avatars/characters/00_avatar.png", raylib::Vector2(GetScreenWidth()/2 - 50,GetScreenHeight()/2 - 140), raylib::Vector2(100,100));
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
    _image->Draw();
    raylib::DrawText(display_text, 160, 200, 20, LIGHTGRAY);
};

std::shared_ptr<core::scene::Scene> CharCreationScene::GetScene()
{
    return _scene;
};