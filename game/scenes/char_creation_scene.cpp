#include "char_creation_scene.hpp"

using namespace game::scene;

CharCreationScene::CharCreationScene()
{
    auto _resource = game::manager::ResourceManager::GetInstance();

    _avatars.push_back(_resource->GetResource<raylib::Texture2D>("00_avatar.png"));
    _avatars.push_back(_resource->GetResource<raylib::Texture2D>("01_avatar.png"));
    _avatars.push_back(_resource->GetResource<raylib::Texture2D>("02_avatar.png"));
    _avatars.push_back(_resource->GetResource<raylib::Texture2D>("03_avatar.png"));

    _confirm_button     = std::make_unique<core::gui::PushButton>("Confirm");
    _confirm_button->Move(raylib::Vector2(GetScreenWidth()/2.0f - 50, GetScreenHeight() - 50));

    _back_button        = std::make_unique<core::gui::PushButton>("Back");
    _back_button->Move(raylib::Vector2(GetScreenWidth()/2.0f + 50, GetScreenHeight() - 50));

    _next_avatar_button = std::make_unique<core::gui::PushButton>("  >  ");
    _next_avatar_button->Move(raylib::Vector2(GetScreenWidth()/2.0f + 70, GetScreenHeight()/2.0f - 70));

    _prev_avatar_button = std::make_unique<core::gui::PushButton>("  <  ");
    _prev_avatar_button->Move(raylib::Vector2(GetScreenWidth()/2.0f - 70, GetScreenHeight()/2.0f - 70));

    _next_class_button  = std::make_unique<core::gui::PushButton>("  >  ");
    _next_class_button->Move(raylib::Vector2(GetScreenWidth()/2.0f + 70, GetScreenHeight()/2.0f));

    _prev_class_button  = std::make_unique<core::gui::PushButton>("  <  ");
    _prev_class_button->Move(raylib::Vector2(GetScreenWidth()/2.0f - 70, GetScreenHeight()/2.0f));

    _avatar = std::make_unique<core::gui::CImage>(_avatars.at(_avatar_index % 4), raylib::Vector2(GetScreenWidth()/2.0f - 50,GetScreenHeight()/2.0f - 140), raylib::Vector2(100,100));

    _name_box = std::make_unique<core::gui::TextBox>("Char name");
    _name_box->Move(raylib::Vector2(GetScreenWidth()/2.0f, GetScreenHeight()/2.0f + 60));
    
    _scene = nullptr;
};

void CharCreationScene::Update()
{
    if (_confirm_button->ButtonPressed())
    {
        _scene = std::make_shared<MainScene>();
        std::cout << _name_box->GetText() << std::endl;
    }
    if (_back_button->ButtonPressed())
    {
        _scene = std::make_shared<LoginScene>();
    }

    if (_next_avatar_button->ButtonPressed())
    {
        _avatar->UpdateImage(_avatars.at(++_avatar_index % 4));
    }
    if(_prev_avatar_button->ButtonPressed())
    {
        _avatar->UpdateImage(_avatars.at(--_avatar_index % 4));
    }
    if(_next_class_button->ButtonPressed())
    {
        std::cout << "chosen X class\n";
    }
    if(_prev_class_button->ButtonPressed())
    {
        std::cout << "chosen X class\n";
    }

    _name_box->Update();

};

void CharCreationScene::Draw()
{
    _name_box->Draw();
    
    _confirm_button->Draw();
    _back_button->Draw();
    _next_avatar_button->Draw();
    _prev_avatar_button->Draw();
    _next_class_button->Draw();
    _prev_class_button->Draw();
    _avatar->Draw();
};

std::shared_ptr<core::scene::Scene> CharCreationScene::GetScene()
{
    return _scene;
};