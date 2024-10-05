#include "character.hpp"

using namespace game::scene;

CharacterScene::CharacterScene() { m_scene = nullptr; }

CharacterScene::~CharacterScene()
{
  std::cout << "Destroyed character scene" << std::endl;
}

void CharacterScene::Update() {};

void CharacterScene::Draw()
{
  raylib::DrawText("CHARACTER!", 160, 200, 20, LIGHTGRAY);
};

std::shared_ptr<core::scene::Scene> CharacterScene::GetScene()
{
  return m_scene;
}