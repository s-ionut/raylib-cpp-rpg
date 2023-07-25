#ifndef _SCENE_MANAGER_HPP
#define _SCENE_MANAGER_HPP

#include "game/scenes/main_scene.hpp"
#include "game/scenes/char_creation_scene.hpp"

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

#endif // _SCENE_MANAGER_HPP