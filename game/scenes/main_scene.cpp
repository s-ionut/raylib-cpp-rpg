#include "main_scene.hpp"
#include <iostream>

using namespace game::scene;

MainScene::MainScene()
{
  m_scene   = nullptr;
  m_textbox = std::make_unique<core::gui::TextBox>();

  auto gameManager = game::manager::GameManager::getInstance();
  m_character      = gameManager->getPlayer(1);
}

MainScene::~MainScene() { std::cout << "Destroyed main scene" << std::endl; }

void MainScene::Update()
{
  if(IsKeyPressed(KEY_A))
  {
    m_scene = std::make_shared<CharCreationScene>();
  }

  m_textbox->Update();
};

void MainScene::Draw()
{
  raylib::DrawText("raylib-rpg MainScene!", 160, 200, 20, LIGHTGRAY);
  raylib::DrawText(m_character->getName(), 160, 230, 20, LIGHTGRAY);
  m_textbox->Draw();
};

std::shared_ptr<core::scene::Scene> MainScene::GetScene() { return m_scene; };