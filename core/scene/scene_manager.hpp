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
                    void Manage();
                    void InitScene();
                    static game::scene::MainScene _mainScene;
                    static game::scene::CharCreationScene _charCreationScene;
                    static Scene* _scene;
            };
    } // mamespace scene
} // namespace core

#endif // _SCENE_MANAGER_HPP