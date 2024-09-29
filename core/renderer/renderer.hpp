#pragma once

// raylib specific
#include "raylib-cpp.hpp"

// core specific
#include "scene/scene.hpp"

// game specific
#include "game/scenes/intro_scene.hpp"

namespace core
{
  namespace renderer
  {
    class Renderer
    {
    public:
      Renderer();
      ~Renderer();
      void Update();
      void Draw();
      bool Shutdown();

    private:
      std::shared_ptr<scene::Scene> m_scene;
      void                          GetScene();
    };
  } // namespace renderer
} // namespace core
