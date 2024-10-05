#include "forge.hpp"

using namespace game::scene;

ForgeScene::ForgeScene() { m_scene = nullptr; }

ForgeScene::~ForgeScene()
{
  std::cout << "Destroyed forge scene" << std::endl;
}

void ForgeScene::Update() {};

void ForgeScene::Draw()
{
  raylib::DrawText("FORGE!", 160, 200, 20, LIGHTGRAY);
};

std::shared_ptr<core::scene::Scene> ForgeScene::GetScene() { return m_scene; }