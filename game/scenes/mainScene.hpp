#ifndef _MAIN_SCENE_HPP
#define _MAIN_SCENE_HPP

#include "core/scene/scene.hpp"

namespace game{
    namespace scene{
        class MainScene: public core::scene::Scene
        {
            public:
            MainScene();
            virtual ~MainScene() {};
            virtual void Update();
            virtual void Draw();
        };
    } // scene
} // game

#endif // _MAIN_SCENE_HPP