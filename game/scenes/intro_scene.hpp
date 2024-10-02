#pragma once

// core includes
#include "core/scene/scene.hpp"
#include "core/time/timer.hpp"

// game includes
#include "login_scene.hpp"

namespace game
{
  namespace scene
  {
    class IntroScene : public core::scene::Scene
    {
    public:
      IntroScene();
      virtual ~IntroScene() {};
      virtual void                                Update() override;
      virtual void                                Draw() override;
      virtual std::shared_ptr<core::scene::Scene> GetScene() override;

    private:
      std::shared_ptr<core::scene::Scene> m_scene;
      core::time::Timer                   m_timer;
      raylib::Rectangle                   m_foreground;
      raylib::Rectangle                   m_background;

      uint8_t       m_colorAlpha = 255;
      uint8_t       m_switcher   = -1;
      raylib::Color m_fgColor    = raylib::Color(255, 255, 255, m_colorAlpha);
    };
  } // namespace scene
} // namespace game
