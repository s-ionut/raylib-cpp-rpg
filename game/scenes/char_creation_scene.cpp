#include "char_creation_scene.hpp"

using namespace game::scene;

CharCreationScene::CharCreationScene()
{
  auto resource    = game::manager::ResourceManager::getInstance();
  auto gameManager = game::manager::GameManager::getInstance();

  m_avatars.push_back(
    resource->getResource<raylib::Texture2D>("00_avatar.png"));
  m_avatars.push_back(
    resource->getResource<raylib::Texture2D>("01_avatar.png"));
  m_avatars.push_back(
    resource->getResource<raylib::Texture2D>("02_avatar.png"));
  m_avatars.push_back(
    resource->getResource<raylib::Texture2D>("03_avatar.png"));

  m_confirmButton = std::make_unique<core::gui::PushButton>("Confirm");
  m_confirmButton->move(
    raylib::Vector2(GetScreenWidth() / 2.0f - 50, GetScreenHeight() - 50.0f));

  m_backButton = std::make_unique<core::gui::PushButton>("Back");
  m_backButton->move(
    raylib::Vector2(GetScreenWidth() / 2.0f + 50, GetScreenHeight() - 50.0f));

  m_nextAvatarButton = std::make_unique<core::gui::PushButton>("  >  ");
  m_nextAvatarButton->move(raylib::Vector2(GetScreenWidth() / 2.0f + 70,
                                           GetScreenHeight() / 2.0f - 70));

  m_prevAvatarButton = std::make_unique<core::gui::PushButton>("  <  ");
  m_prevAvatarButton->move(raylib::Vector2(GetScreenWidth() / 2.0f - 70,
                                           GetScreenHeight() / 2.0f - 70));

  m_nextClassButton = std::make_unique<core::gui::PushButton>("  >  ");
  m_nextClassButton->move(raylib::Vector2(GetScreenWidth() / 2.0f + 70.0f,
                                          GetScreenHeight() / 2.0f));

  m_prevClassButton = std::make_unique<core::gui::PushButton>("  <  ");
  m_prevClassButton->move(raylib::Vector2(GetScreenWidth() / 2.0f - 70.0f,
                                          GetScreenHeight() / 2.0f));

  m_avatar = std::make_unique<core::gui::CImage>(
    m_avatars.at(0),
    raylib::Vector2(GetScreenWidth() / 2.0f - 50,
                    GetScreenHeight() / 2.0f - 140),
    raylib::Vector2(100, 100));

  m_nameBox = std::make_unique<core::gui::TextBox>("Char name");
  m_font    = std::make_unique<core::text::CFont>();
  m_nameBox->move(
    raylib::Vector2(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f + 60));

  m_scene     = nullptr;
  m_character = gameManager->getPlayer(1);
};

void CharCreationScene::Update()
{
  auto avatarIndex = m_character->getAvatar();

  if(m_confirmButton->buttonPressed())
  {
    m_character->setName(m_nameBox->getText());
    m_character->setClass(entity::getClassTypeByIndex(m_classIndex));
    m_character->setAvatar(avatarIndex);
    m_scene = std::make_shared<MainScene>();
  }
  if(m_backButton->buttonPressed())
  {
    m_scene = std::make_shared<LoginScene>();
  }

  if(m_nextAvatarButton->buttonPressed())
  {
    m_avatar->updateImage(m_avatars.at(++m_avatarIndex % 4));
  }
  if(m_prevAvatarButton->buttonPressed())
  {
    m_avatar->updateImage(m_avatars.at(--m_avatarIndex % 4));
  }
  if(m_nextClassButton->buttonPressed())
  {
    m_classIndex = ++m_classIndex % static_cast<int>(entity::ClassType::COUNT);
  }
  if(m_prevClassButton->buttonPressed())
  {
    m_classIndex = --m_classIndex % static_cast<int>(entity::ClassType::COUNT);
  }

  m_nameBox->Update();

  m_tempTextXPos
    = GetScreenWidth() / 2
      - (MeasureText(game::entity::getClassNameByType(
                       game::entity::getClassTypeByIndex(m_classIndex))
                       .c_str(),
                     1)
         / 2);
};

void CharCreationScene::Draw()
{
  m_nameBox->Draw();

  m_confirmButton->Draw();
  m_backButton->Draw();
  m_nextAvatarButton->Draw();
  m_prevAvatarButton->Draw();
  m_nextClassButton->Draw();
  m_prevClassButton->Draw();
  m_avatar->Draw();

  raylib::DrawText(game::entity::getClassNameByType(
                     game::entity::getClassTypeByIndex(m_classIndex)),
                   m_tempTextXPos,
                   GetScreenHeight() / 2,
                   static_cast<int>(m_font->getFontSize()),
                   BLACK);
};

std::shared_ptr<core::scene::Scene> CharCreationScene::GetScene()
{
  return m_scene;
};