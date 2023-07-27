#ifndef _MAIN_SCENE_HPP
#define _MAIN_SCENE_HPP

#include "core/scene/scene.hpp"

#include "char_creation_scene.hpp"

namespace game{
    namespace scene{
        class MainScene: public core::scene::Scene
        {
            public:
                MainScene();
                virtual ~MainScene() {};
                virtual void Update();
                virtual void Draw();
                core::scene::Scene* GetScene();
            
            private:
                core::scene::Scene* _scene;
        };
    } // namespace scene
} // namespace game

#endif // _MAIN_SCENE_HPP