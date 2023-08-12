#include "login_scene.hpp"

using namespace game::scene;

LoginScene::LoginScene()
{
    _scene = nullptr;
    _username_box = std::make_unique<core::gui::TextBox>("Username");
    _pass_box = std::make_unique<core::gui::TextBox>("Password");
    _login_button = std::make_unique<core::gui::PushButton>("Login");
    _exit_button = std::make_unique<core::gui::PushButton>("Exit");

    _username_box->Move(raylib::Vector2(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f - 40));
    _pass_box->Move(raylib::Vector2(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f));
    _login_button->Move(raylib::Vector2(GetScreenWidth() / 2.0f - 40, GetScreenHeight() / 2.0f + 80));
    _exit_button->Move(raylib::Vector2(GetScreenWidth() / 2.0f + 40, GetScreenHeight() / 2.0f + 80));
};

void LoginScene::Update()
{
    // Do something interesting in the intro
    if (_login_button->ButtonPressed())
    {
        _scene = std::make_shared<CharCreationScene>();
    }

    if(_exit_button->ButtonPressed())
    {
        std::cout << "Exit scene" << std::endl;
        ///TODO: call somehow window.close()
    }
    
    _username_box->Update();
    _pass_box->Update();
    _login_button->Update();
    _exit_button->Update();
};

void LoginScene::Draw()
{
    _username_box->Draw();
    _pass_box->Draw();

    _login_button->Draw();
    _exit_button->Draw();
};

std::shared_ptr<core::scene::Scene> LoginScene::GetScene()
{
    return _scene;
};