#pragma once

// game specific
#include "game/scenes/main_scene.hpp"
#include "game/scenes/char_creation_scene.hpp"

// system specific
#include "etc/system_includes.h"

namespace core{
    namespace scene{
            class SceneManager
            {
                public:
                    SceneManager();
                    ~SceneManager();
                    Scene* GetScene();
                private:
                    Scene* Manage();
                    void InitScene();
                    Scene* _scene = nullptr;                                           // Current scene to display
            };
    } // mamespace scene
} // namespace core
