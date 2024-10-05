#pragma once

// core includes
#include "core/scene/scene.hpp"
#include "core/gui/core_gui.hpp"

#include "menu_scenes/character.hpp"
#include "menu_scenes/map.hpp"
#include "menu_scenes/bag.hpp"
#include "menu_scenes/forge.hpp"
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

      template <typename SceneType> bool isCurrentScene()
      {
        return std::dynamic_pointer_cast<SceneType>(m_menuScene) != nullptr;
      }

    private:
      std::shared_ptr<core::scene::Scene> m_scene;
      std::shared_ptr<core::scene::Scene> m_menuScene;

      std::unique_ptr<core::gui::PushButton> m_characterButton;
      std::unique_ptr<core::gui::PushButton> m_mapButton;
      std::unique_ptr<core::gui::PushButton> m_bagButton;
      std::unique_ptr<core::gui::PushButton> m_forgeButton;
      std::unique_ptr<core::gui::PushButton> m_settingsButton;
    };
  } // namespace scene
} // namespace game
