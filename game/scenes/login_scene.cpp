#include "login_scene.hpp"

using namespace game::scene;

LoginScene::LoginScene()
{
  m_scene = nullptr;

  m_gameManager = game::manager::GameManager::getInstance();
  m_gameManager->updatePlayers();

  m_usernameBox = std::make_unique<core::gui::TextBox>("Username");
  m_passBox     = std::make_unique<core::gui::TextBox>("Password");
  m_loginButton = std::make_unique<core::gui::PushButton>("    Login    ");
  m_exitButton  = std::make_unique<core::gui::PushButton>("    Exit    ");

  m_usernameBox->move(
    raylib::Vector2(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f - 40));
  m_passBox->move(
    raylib::Vector2(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f));
  m_loginButton->move(raylib::Vector2(GetScreenWidth() / 2.0f - 40,
                                      GetScreenHeight() / 2.0f + 80));
  m_exitButton->move(raylib::Vector2(GetScreenWidth() / 2.0f + 40,
                                     GetScreenHeight() / 2.0f + 80));
};

void LoginScene::Update()
{

  if(m_loginButton->buttonPressed())
  {
    /// TODO: check login data from database, print for now
    std::cout << "Username: " << m_usernameBox->getText() << std::endl;
    std::cout << "Password: " << m_passBox->getText() << std::endl;
    if(!m_gameManager->checkPlayer(1))
    {
      m_gameManager->updatePlayers();
      m_scene = std::make_shared<CharCreationScene>();
    }
    else
    {
      m_scene = std::make_shared<MainScene>();
    }
  }

  if(m_exitButton->buttonPressed())
  {
    std::cout << "Exit scene" << std::endl;
    m_shouldClose = true;
  }

  m_usernameBox->Update();
  m_passBox->Update();
  m_loginButton->Update();
  m_exitButton->Update();
};

void LoginScene::Draw()
{
  m_usernameBox->Draw();
  m_passBox->Draw();

  m_loginButton->Draw();
  m_exitButton->Draw();
};

std::shared_ptr<core::scene::Scene> LoginScene::GetScene() { return m_scene; };