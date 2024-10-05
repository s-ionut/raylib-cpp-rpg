#pragma once

// core includes
#include "core/scene/scene.hpp"
#include "core/gui/core_gui.hpp"

// game includes
#include "managers/game_manager.hpp"
#include "entity/character.hpp"

#include "menu_scenes/map.hpp"
#include "menu_scenes/bag.hpp"
#include "menu_scenes/settings.hpp"

namespace game
{
  namespace scene
  {
    class MainScene : public core::scene::Scene
    {
    public:
      MainScene();
      virtual ~MainScene() override;
      virtual void                                Update() override;
      virtual void                                Draw() override;
      virtual std::shared_ptr<core::scene::Scene> GetScene() override;

    private:
      void updateMainScene();

    private:
      std::shared_ptr<core::scene::Scene> m_scene;
      std::shared_ptr<core::scene::Scene> m_menuScene;

      std::unique_ptr<core::gui::PushButton> m_characterButton;
      std::unique_ptr<core::gui::PushButton> m_mapButton;
      std::unique_ptr<core::gui::PushButton> m_bagButton;
      std::unique_ptr<core::gui::PushButton> m_forgeButton;
      std::unique_ptr<core::gui::PushButton> m_settingsButton;

      entity::Character* m_character;
    };
  } // namespace scene
} // namespace game
