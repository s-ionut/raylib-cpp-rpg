#ifndef _INTRO_SCENE_HPP
#define _INTRO_SCENE_HPP

#include "core/scene/scene.hpp"

#include "char_creation_scene.hpp"

namespace game{
    namespace scene{
        class IntroScene: public core::scene::Scene
        {
            public:
                IntroScene();
                virtual ~IntroScene() {};
                virtual void Update() override;
                virtual void Draw() override;
                virtual core::scene::Scene* GetScene() override;
            
            private:
                core::scene::Scene* _scene;
        };
    } // namespace scene
} // namespace game

#endif // _INTRO_SCENE_HPP