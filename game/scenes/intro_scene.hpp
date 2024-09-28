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
      std::shared_ptr<core::scene::Scene> _scene;
      core::time::Timer                   _timer;
    };
  } // namespace scene
} // namespace game
