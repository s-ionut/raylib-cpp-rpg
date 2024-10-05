#include "main_scene.hpp"

using namespace game::scene;

MainScene::MainScene()
{
  m_scene = nullptr;

  m_characterButton = std::make_unique<core::gui::PushButton>(" CHARACTER ");
  m_mapButton   = std::make_unique<core::gui::PushButton>("      MAP      ");
  m_bagButton   = std::make_unique<core::gui::PushButton>("      BAG       ");
  m_forgeButton = std::make_unique<core::gui::PushButton>("    FORGE     ");
  m_settingsButton = std::make_unique<core::gui::PushButton>("   SETTINGS   ");

  auto baseHeight = 20;
  auto baseWidth  = 50;

  m_characterButton->move(raylib::Vector2(baseWidth, baseHeight));
  m_mapButton->move(raylib::Vector2(baseWidth, baseHeight + 40));
  m_bagButton->move(raylib::Vector2(baseWidth, baseHeight + 80));
  m_forgeButton->move(raylib::Vector2(baseWidth, baseHeight + 120));
  m_settingsButton->move(raylib::Vector2(baseWidth, baseHeight + 160));

  auto gameManager = game::manager::GameManager::getInstance();
  m_character      = gameManager->getPlayer(1);
  m_menuScene      = std::make_shared<MapScene>();
}

MainScene::~MainScene() { std::cout << "Destroyed main scene" << std::endl; }

void MainScene::Update()
{
  if(m_mapButton->buttonPressed())
  {
    m_menuScene = std::make_shared<MapScene>();
  }

  if(m_bagButton->buttonPressed())
  {
    m_menuScene = std::make_shared<BagScene>();
  }

  if(m_settingsButton->buttonPressed())
  {
    m_menuScene = std::make_shared<SettingsScene>();
  }

  m_characterButton->Update();
  m_mapButton->Update();
  m_bagButton->Update();
  m_forgeButton->Update();
  m_settingsButton->Update();

  updateMainScene();

  m_menuScene->Update();
};

void MainScene::Draw()
{
  m_characterButton->Draw();
  m_mapButton->Draw();
  m_bagButton->Draw();
  m_forgeButton->Draw();
  m_settingsButton->Draw();

  m_menuScene->Draw();

  if(m_menuScene->Shutdown())
    m_shouldClose = true;

  raylib::DrawText("raylib-rpg MainScene!", 160, 200, 20, LIGHTGRAY);
  raylib::DrawText(m_character->getName(), 160, 230, 20, LIGHTGRAY);
};

void game::scene::MainScene::updateMainScene()
{
  std::shared_ptr<core::scene::Scene> scene = m_menuScene->GetScene();

  if(scene != nullptr)
  {
    m_menuScene = scene;
  }
};

std::shared_ptr<core::scene::Scene> MainScene::GetScene() { return m_scene; }