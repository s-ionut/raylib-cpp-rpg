#ifndef _INTRO_SCENE_HPP
#define _INTRO_SCENE_HPP

#include "core/scene/scene.hpp"

namespace game{
    namespace scene{
        class IntroScene: public core::scene::Scene
        {
            public:
                IntroScene();
                virtual ~IntroScene() {};
                virtual void Update();
                virtual void Draw();
        };
    } // namespace scene
} // namespace game

#endif // _INTRO_SCENE_HPP