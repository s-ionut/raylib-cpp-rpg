#pragma once

// core specific
#include "core/scene/scene.hpp"
#include "core/gui/core_gui.hpp"
#include "core/gui/text/font.hpp"

// game specific
#include "main_scene.hpp"
#include "login_scene.hpp"
#include "managers/resource_manager.hpp"
#include "managers/game_manager.hpp"
#include "entity/character.hpp"

namespace game
{
  namespace scene
  {
    class CharCreationScene : public core::scene::Scene
    {
    public:
      CharCreationScene();
      virtual ~CharCreationScene() {};
      virtual void                                Update() override;
      virtual void                                Draw() override;
      virtual std::shared_ptr<core::scene::Scene> GetScene() override;

    private:
      std::shared_ptr<core::scene::Scene>    m_scene;
      std::unique_ptr<core::gui::PushButton> m_confirmButton;
      std::unique_ptr<core::gui::PushButton> m_backButton;
      std::unique_ptr<core::gui::PushButton> m_nextAvatarButton;
      std::unique_ptr<core::gui::PushButton> m_prevAvatarButton;
      std::unique_ptr<core::gui::PushButton> m_nextClassButton;
      std::unique_ptr<core::gui::PushButton> m_prevClassButton;
      std::unique_ptr<core::gui::TextBox>    m_nameBox;
      std::unique_ptr<core::gui::CImage>     m_avatar;
      std::unique_ptr<core::text::CFont>     m_font;

      std::vector<raylib::Texture2D*> m_avatars;
      uint8_t                         m_avatarIndex  = 0;
      uint8_t                         m_classIndex   = 0;
      int                             m_tempTextXPos = 0;

      entity::Character* m_character;
    };
  } // namespace scene
} // namespace game
