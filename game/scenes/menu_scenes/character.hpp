#pragma once

// core includes
#include "core/scene/scene.hpp"
#include "core/gui/core_gui.hpp"
#include "core/gui/text/text_utils.hpp"

// game includes
#include "managers/resource_manager.hpp"
#include "managers/game_manager.hpp"
#include "entity/character.hpp"

namespace game
{
  namespace scene
  {
    class CharacterScene : public core::scene::Scene
    {
    public:
      CharacterScene();
      virtual ~CharacterScene() override;
      virtual void                                Update() override;
      virtual void                                Draw() override;
      virtual std::shared_ptr<core::scene::Scene> GetScene() override;

    private:
      std::string m_charName;

      std::shared_ptr<core::scene::Scene> m_scene;

      raylib::Rectangle                  m_background;
      raylib::Texture2D*                 m_charAvatar;
      std::unique_ptr<core::gui::CImage> m_charImage;

      entity::Character* m_character;
    };
  } // namespace scene
} // namespace game
