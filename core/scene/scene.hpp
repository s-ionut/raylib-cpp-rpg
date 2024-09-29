#pragma once

// raylib specific
#include "raylib-cpp.hpp"

namespace core
{
  namespace scene
  {
    class Scene
    {
    public:
      virtual ~Scene() {};
      virtual void                   Update() {};
      virtual void                   Draw() {};
      virtual bool                   Shutdown() { return m_shouldClose; };
      virtual std::shared_ptr<Scene> GetScene() { return nullptr; };

    protected:
      bool m_shouldClose = false;
    };
  } // scene
} // core
