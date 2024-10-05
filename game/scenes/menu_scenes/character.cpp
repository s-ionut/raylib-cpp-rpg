#include "character.hpp"

using namespace game::scene;

CharacterScene::CharacterScene()
    : m_background(100, 0, GetScreenWidth(), GetScreenHeight())
{
  m_scene = nullptr;

  auto gameManager     = game::manager::GameManager::getInstance();
  auto resourceManager = game::manager::ResourceManager::getInstance();
  m_character          = gameManager->getPlayer(1);

  m_charName = m_character->getName();

  m_charAvatar = resourceManager->getResource<raylib::Texture2D>(
    "0" + std::to_string(m_character->getAvatar()) + "_avatar.png");
  m_charImage = std::make_unique<core::gui::CImage>(
    m_charAvatar,
    raylib::Vector2(GetScreenWidth() / 2, 50),
    raylib::Vector2(100, 100));
}

CharacterScene::~CharacterScene()
{
  std::cout << "Destroyed character scene" << std::endl;
}

void CharacterScene::Update() {};

void CharacterScene::Draw()
{
  m_background.Draw(raylib::Color(0, 0, 0, 127));

  m_charImage->Draw();

  auto className = getClassNameByType(m_character->getClass());
  raylib::DrawText(m_charName,
                   core::text::centerTextToMiddleScreen(m_charName) + 50,
                   155,
                   20,
                   RED);
  raylib::DrawText(className,
                   core::text::centerTextToMiddleScreen(className) + 50,
                   180,
                   20,
                   RED);

  // draw character stats
  raylib::DrawText(
    "Level:" + std::to_string(m_character->getLevel()), 130, 170, 30, BLACK);
  raylib::DrawText(
    "Attack: " + std::to_string(m_character->getAttack()), 130, 205, 30, BLACK);
  raylib::DrawText("Defense: " + std::to_string(m_character->getDefense()),
                   130,
                   240,
                   30,
                   BLACK);
  raylib::DrawText(
    "HP: " + std::to_string(m_character->getMaxHP()), 130, 275, 30, BLACK);
  raylib::DrawText(
    "MANA: " + std::to_string(m_character->getMaxMana()), 130, 310, 30, BLACK);
};

std::shared_ptr<core::scene::Scene> CharacterScene::GetScene()
{
  return m_scene;
}