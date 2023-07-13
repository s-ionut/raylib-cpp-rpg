#ifndef _CHAR_CREATION_SCENE_HPP
#define _CHAR_CREATION_SCENE_HPP

#include "scene.hpp"

namespace core{
    namespace scene{
        class CharCreationScene: public Scene
        {
            public:
            CharCreationScene();
            virtual ~CharCreationScene() {};
            virtual void Update();
            virtual void Draw();
        };
    } // scene
} // core

#endif // _CHAR_CREATION_SCENE_HPP