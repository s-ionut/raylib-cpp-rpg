#include "login_scene.hpp"

using namespace game::scene;

LoginScene::LoginScene()
{
    _scene = nullptr;
    _username_box = std::make_unique<core::gui::TextBox>("Username");
    _pass_box = std::make_unique<core::gui::TextBox>("Password");
    _login_button = std::make_unique<core::gui::PushButton>("    Login    ");
    _exit_button = std::make_unique<core::gui::PushButton>("    Exit    ");

    _username_box->move(raylib::Vector2(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f - 40));
    _pass_box->move(raylib::Vector2(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f));
    _login_button->move(raylib::Vector2(GetScreenWidth() / 2.0f - 40, GetScreenHeight() / 2.0f + 80));
    _exit_button->move(raylib::Vector2(GetScreenWidth() / 2.0f + 40, GetScreenHeight() / 2.0f + 80));
};

void LoginScene::Update()
{
    auto game_manager = game::manager::GameManager::getInstance();

    if (_login_button->buttonPressed())
    {
        /// TODO: check login data from database, print for now
        std::cout << "Username: " << _username_box->getText() << std::endl;
        std::cout << "Password: " << _pass_box->getText() << std::endl;
        if (!game_manager->checkPlayer(1))
        {
            _scene = std::make_shared<CharCreationScene>();
        }
        else
        {
            _scene = std::make_shared<MainScene>();
        }
    }

    if(_exit_button->buttonPressed())
    {
        std::cout << "Exit scene" << std::endl;
        _should_close = true;
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