#pragma once

// core includes
#include "core/scene/scene.hpp"

namespace game
{
  namespace scene
  {
    class ForgeScene : public core::scene::Scene
    {
    public:
      ForgeScene();
      virtual ~ForgeScene() override;
      virtual void                                Update() override;
      virtual void                                Draw() override;
      virtual std::shared_ptr<core::scene::Scene> GetScene() override;

    private:
      std::shared_ptr<core::scene::Scene> m_scene;
    };
  } // namespace scene
} // namespace game
