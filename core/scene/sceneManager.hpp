#ifndef _SCENE_MANAGER_HPP
#define _SCENE_MANAGER_HPP

#include "mainScene.hpp"
#include "charCreationScene.hpp"

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
                    static MainScene _mainScene;
                    static CharCreationScene _charCreationScene;
                    static Scene* _scene;
            };
    } // scene
} // core

#endif // _SCENE_MANAGER_HPP