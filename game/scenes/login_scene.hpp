#pragma once

// core includes
#include "core/scene/scene.hpp"
#include "core/gui/core_gui.hpp"

// game includes
#include "char_creation_scene.hpp"
#include "main_scene.hpp"
#include "managers/game_manager.hpp"

namespace game
{
  namespace scene
  {
    class LoginScene : public core::scene::Scene
    {
    public:
      LoginScene();
      virtual ~LoginScene() {};
      virtual void                                Update() override;
      virtual void                                Draw() override;
      virtual std::shared_ptr<core::scene::Scene> GetScene() override;

    private:
      std::shared_ptr<core::scene::Scene> m_scene;
      std::unique_ptr<core::gui::TextBox> m_usernameBox;
      std::unique_ptr<core::gui::TextBox> m_passBox;

      std::unique_ptr<core::gui::PushButton> m_loginButton;
      std::unique_ptr<core::gui::PushButton> m_exitButton;

      game::manager::GameManager* m_gameManager;
    };
  } // namespace scene
} // namespace game
