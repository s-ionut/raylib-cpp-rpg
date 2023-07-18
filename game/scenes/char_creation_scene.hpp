#ifndef _CHAR_CREATION_SCENE_HPP
#define _CHAR_CREATION_SCENE_HPP

#include "core/scene/scene.hpp"
#include "core/gui/push_button.hpp"

namespace game{
    namespace scene{
        class CharCreationScene: public core::scene::Scene
        {
            public:
                CharCreationScene();
                virtual ~CharCreationScene() {};
                virtual void Update();
                virtual void Draw();

            private:
                core::gui::PushButton* button;
        };
    } // namespace scene
} // namespace game

#endif // _CHAR_CREATION_SCENE_HPP