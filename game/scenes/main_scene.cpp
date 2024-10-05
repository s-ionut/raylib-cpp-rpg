#include "main_scene.hpp"

using namespace game::scene;

MainScene::MainScene()
{
  m_scene = nullptr;

  m_characterButton = std::make_unique<core::gui::PushButton>("CHARACTER");
  m_mapButton       = std::make_unique<core::gui::PushButton>("MAP");
  m_bagButton       = std::make_unique<core::gui::PushButton>("BAG");
  m_forgeButton     = std::make_unique<core::gui::PushButton>("FORGE");
  m_settingsButton  = std::make_unique<core::gui::PushButton>("SETTINGS");

  auto baseHeight = GetScreenHeight() / 2 - 125;
  auto baseWidth  = 1;

  m_characterButton->setFixedPosition(raylib::Vector2(baseWidth, baseHeight));
  m_mapButton->setFixedPosition(raylib::Vector2(baseWidth, baseHeight + 50));
  m_bagButton->setFixedPosition(raylib::Vector2(baseWidth, baseHeight + 100));
  m_forgeButton->setFixedPosition(
    raylib::Vector2(baseWidth, baseHeight + 150));
  m_settingsButton->setFixedPosition(
    raylib::Vector2(baseWidth, baseHeight + 200));

  m_characterButton->setFixedSize(raylib::Vector2(100, 50));
  m_mapButton->setFixedSize(raylib::Vector2(100, 50));
  m_bagButton->setFixedSize(raylib::Vector2(100, 50));
  m_forgeButton->setFixedSize(raylib::Vector2(100, 50));
  m_settingsButton->setFixedSize(raylib::Vector2(100, 50));

  m_menuScene = std::make_shared<CharacterScene>();
}

MainScene::~MainScene() { std::cout << "Destroyed main scene" << std::endl; }

void MainScene::Update()
{
  if(m_characterButton->buttonPressed() && !isCurrentScene<CharacterScene>())
  {
    m_menuScene = std::make_shared<CharacterScene>();
  }

  if(m_mapButton->buttonPressed() && !isCurrentScene<MapScene>())
  {
    m_menuScene = std::make_shared<MapScene>();
  }

  if(m_bagButton->buttonPressed() && !isCurrentScene<BagScene>())
  {
    m_menuScene = std::make_shared<BagScene>();
  }

  if(m_forgeButton->buttonPressed() && !isCurrentScene<ForgeScene>())
  {
    m_menuScene = std::make_shared<ForgeScene>();
  }

  if(m_settingsButton->buttonPressed() && !isCurrentScene<SettingsScene>())
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
};

void game::scene::MainScene::updateMainScene()
{
  std::shared_ptr<core::scene::Scene> scene = m_menuScene->GetScene();

  if(scene != nullptr && scene != m_menuScene)
  {
    m_menuScene = scene;
  }
};

std::shared_ptr<core::scene::Scene> MainScene::GetScene() { return m_scene; }