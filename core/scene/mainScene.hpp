#ifndef _MAIN_SCENE_HPP
#define _MAIN_SCENE_HPP

#include "scene.hpp"

namespace core{
    namespace scene{
        class MainScene: public Scene
        {
            public:
            MainScene();
            virtual ~MainScene() {};
            virtual void Update();
            virtual void Draw();
        };
    } // scene
} // core

#endif // _MAIN_SCENE_HPP