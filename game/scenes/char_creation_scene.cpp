#include "char_creation_scene.hpp"

using namespace game::scene;

CharCreationScene::CharCreationScene()
{
  auto resource     = game::manager::ResourceManager::getInstance();
  auto game_manager = game::manager::GameManager::getInstance();

  _avatars.push_back(
    resource->getResource<raylib::Texture2D>("00_avatar.png"));
  _avatars.push_back(
    resource->getResource<raylib::Texture2D>("01_avatar.png"));
  _avatars.push_back(
    resource->getResource<raylib::Texture2D>("02_avatar.png"));
  _avatars.push_back(
    resource->getResource<raylib::Texture2D>("03_avatar.png"));

  _confirm_button = std::make_unique<core::gui::PushButton>("Confirm");
  _confirm_button->move(
    raylib::Vector2(GetScreenWidth() / 2.0f - 50, GetScreenHeight() - 50.0f));

  _back_button = std::make_unique<core::gui::PushButton>("Back");
  _back_button->move(
    raylib::Vector2(GetScreenWidth() / 2.0f + 50, GetScreenHeight() - 50.0f));

  _next_avatar_button = std::make_unique<core::gui::PushButton>("  >  ");
  _next_avatar_button->move(raylib::Vector2(GetScreenWidth() / 2.0f + 70,
                                            GetScreenHeight() / 2.0f - 70));

  _prev_avatar_button = std::make_unique<core::gui::PushButton>("  <  ");
  _prev_avatar_button->move(raylib::Vector2(GetScreenWidth() / 2.0f - 70,
                                            GetScreenHeight() / 2.0f - 70));

  _next_class_button = std::make_unique<core::gui::PushButton>("  >  ");
  _next_class_button->move(raylib::Vector2(GetScreenWidth() / 2.0f + 70.0f,
                                           GetScreenHeight() / 2.0f));

  _prev_class_button = std::make_unique<core::gui::PushButton>("  <  ");
  _prev_class_button->move(raylib::Vector2(GetScreenWidth() / 2.0f - 70.0f,
                                           GetScreenHeight() / 2.0f));

  _avatar = std::make_unique<core::gui::CImage>(
    _avatars.at(0),
    raylib::Vector2(GetScreenWidth() / 2.0f - 50,
                    GetScreenHeight() / 2.0f - 140),
    raylib::Vector2(100, 100));

  _name_box = std::make_unique<core::gui::TextBox>("Char name");
  _font     = std::make_unique<core::text::CFont>();
  _name_box->move(
    raylib::Vector2(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f + 60));

  _scene     = nullptr;
  _character = game_manager->getPlayer(1);
};

void CharCreationScene::Update()
{
  auto avatar_index = _character->getAvatar();

  if(_confirm_button->buttonPressed())
  {
    _character->setName(_name_box->getText());
    _character->setClass(entity::getClassTypeByIndex(_class_index));
    _character->setAvatar(avatar_index);
    _scene = std::make_shared<MainScene>();
  }
  if(_back_button->buttonPressed())
  {
    _scene = std::make_shared<LoginScene>();
  }

  if(_next_avatar_button->buttonPressed())
  {
    _avatar->updateImage(_avatars.at(++_avatar_index % 4));
  }
  if(_prev_avatar_button->buttonPressed())
  {
    _avatar->updateImage(_avatars.at(--_avatar_index % 4));
  }
  if(_next_class_button->buttonPressed())
  {
    _class_index = ++_class_index % static_cast<int>(entity::ClassType::COUNT);
  }
  if(_prev_class_button->buttonPressed())
  {
    _class_index = --_class_index % static_cast<int>(entity::ClassType::COUNT);
  }

  _name_box->Update();

  _temp_text_X_pos
    = GetScreenWidth() / 2
      - (MeasureText(game::entity::getClassNameByType(
                       game::entity::getClassTypeByIndex(_class_index))
                       .c_str(),
                     1)
         / 2);
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

  raylib::DrawText(game::entity::getClassNameByType(
                     game::entity::getClassTypeByIndex(_class_index)),
                   _temp_text_X_pos,
                   GetScreenHeight() / 2,
                   static_cast<int>(_font->getFontSize()),
                   BLACK);
};

std::shared_ptr<core::scene::Scene> CharCreationScene::GetScene()
{
  return _scene;
};