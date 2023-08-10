#include "login_scene.hpp"

using namespace game::scene;

LoginScene::LoginScene()
{
    _scene = nullptr;
    _username_box = std::make_unique<core::gui::TextBox>("Username");
    _pass_box = std::make_unique<core::gui::TextBox>("Password");

    _username_box->Move(raylib::Vector2(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f - 40));
    _pass_box->Move(raylib::Vector2(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f));
};

void LoginScene::Update()
{
    // Do something interesting in the intro
    if (IsKeyPressed(KEY_N))
    {
        _scene = std::make_shared<CharCreationScene>();
    }
    
    _username_box->Update();
    _pass_box->Update();
};

void LoginScene::Draw()
{
    raylib::DrawText("raylib-rpg Login Scene!", 160, 200, 20, LIGHTGRAY);

    _username_box->Draw();
    _pass_box->Draw();
};

std::shared_ptr<core::scene::Scene> LoginScene::GetScene()
{
    return _scene;
};