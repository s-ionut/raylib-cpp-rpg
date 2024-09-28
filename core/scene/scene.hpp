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
      virtual bool                   Shutdown() { return _should_close; };
      virtual std::shared_ptr<Scene> GetScene() { return nullptr; };

    protected:
      bool _should_close = false;
    };
  } // scene
} // core
