#pragma once

// core includes
#include "core/scene/scene.hpp"
#include "core/gui/core_gui.hpp"

namespace game
{
  namespace scene
  {
    class SettingsScene : public core::scene::Scene
    {
    public:
      SettingsScene();
      virtual ~SettingsScene() override;
      virtual void                                Update() override;
      virtual void                                Draw() override;
      virtual std::shared_ptr<core::scene::Scene> GetScene() override;

    private:
      raylib::Rectangle m_background;

      std::unique_ptr<core::gui::PushButton> m_exitButton;

      std::shared_ptr<core::scene::Scene> m_scene;
    };
  } // namespace scene
} // namespace game
